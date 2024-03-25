set(srcs
	# "main.c"
	"factory_reset.c"
	"ota_update.c"
	"platform.c"
	"system.c"
	"sha_main.c"
)

set(includes
	"./include"
	"$ENV{IDF_PATH}/components/mbedtls/mbedtls/tests/include/test/"
)

set(requires
	"driver"
	"nvs_flash"
	"spi_flash"
	"esp_partition"
)

set(priv_requires
	# "micropython"
	"buses"
	"driver_display_st7789v"
	"driver_framebuffer"
	"driver_rtcmem"
	"driver_fpga_ice40"
	"driver_led_neopixel"
	"driver_led_apa102"
	"driver_microphone"
	"driver_mpu6050"
	"driver_sdcard"
	"driver_radio_lora"
	"driver_sensor_am2320"
	"resource_ssl_certs"
	"app_update"
	"esp_wifi"
	# "mbedtls"
	# "esp_hw_support"
	"esp_event"
	# "esp_psram"
	"mbedtls"
)

idf_component_register(
	SRCS "${srcs}"
	INCLUDE_DIRS ${includes}
	REQUIRES ${requires}
    PRIV_REQUIRES ${priv_requires}
)
