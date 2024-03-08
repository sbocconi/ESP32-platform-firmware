/*
 * Some parts
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 * other parts SHA17 Badge Team
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"

#include "nvs_flash.h"
#include "nvs.h"

#include "include/platform.h"
#include "include/ota_update.h"
#include "include/factory_reset.h"
#include "driver_rtcmem.h"


void reset() {
    fflush(stdout);
	vTaskDelay(1000 / portTICK_PERIOD_MS);
	esp_restart();
}

esp_err_t nvs_init() {
    const esp_partition_t * nvs_partition = esp_partition_find_first(ESP_PARTITION_TYPE_DATA, ESP_PARTITION_SUBTYPE_DATA_NVS, NULL);
    if (nvs_partition == NULL) return ESP_FAIL;        
    esp_err_t res = nvs_flash_init();
    if (res != ESP_OK) {
        res = esp_partition_erase_range(nvs_partition, 0, nvs_partition->size);
        if (res != ESP_OK) return res;
        res = nvs_flash_init();
        if (res != ESP_OK) return res;
    }
    return ESP_OK;
}

int magic() {
	int valueA, valueB;
	if (driver_rtcmem_int_read(0, &valueA) != ESP_OK){
        printf("Return 0 at valueA\n");
         return 0;
    }
	if (driver_rtcmem_int_read(1, &valueB) != ESP_OK){
            printf("Return 0 at valueA\n");
         return 0;
    }
	if (valueA == (uint8_t)~valueB) {
        printf("Return valueA\n");
        return valueA;
    }
    printf("Return 0 at the end\n");
	return 0;
}


void app_main(void)
{
    printf("Hello world!\n");

    if (nvs_init() != ESP_OK) {
        printf("Unable to access the non-volatile storage partition in flash\n");
        printf("This could be caused by an unstable 3.3v supply rail to the ESP32 or by a damaged flash chip.\n");
        reset();
    }
    // Start the other components
	platform_init();

    // Start the application
	switch(magic()) {
		case MAGIC_OTA:
			badge_ota_update();
			break;
		case MAGIC_FACTORY_RESET:
			factory_reset();
			break;
		default:
            break;
			// micropython_entry();
	}

    // badge_ota_update();
    // factory_reset();

    /* Print chip information */
    esp_chip_info_t chip_info;
    uint32_t flash_size;
    esp_chip_info(&chip_info);
    printf("This is %s chip with %d CPU core(s), %s%s%s%s, ",
           CONFIG_IDF_TARGET,
           chip_info.cores,
           (chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "WiFi/" : "",
           (chip_info.features & CHIP_FEATURE_BT) ? "BT" : "",
           (chip_info.features & CHIP_FEATURE_BLE) ? "BLE" : "",
           (chip_info.features & CHIP_FEATURE_IEEE802154) ? ", 802.15.4 (Zigbee/Thread)" : "");

    unsigned major_rev = chip_info.revision / 100;
    unsigned minor_rev = chip_info.revision % 100;
    printf("silicon revision v%d.%d, ", major_rev, minor_rev);
    if(esp_flash_get_size(NULL, &flash_size) != ESP_OK) {
        printf("Get flash size failed");
        return;
    }

    printf("%" PRIu32 "MB %s flash\n", flash_size / (uint32_t)(1024 * 1024),
           (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    printf("Minimum free heap size: %" PRIu32 " bytes\n", esp_get_minimum_free_heap_size());

    for (int i = 10; i >= 0; i--) {
        printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    printf("Restarting now.\n");
    fflush(stdout);
    // esp_restart();
    // mc_main();
}
