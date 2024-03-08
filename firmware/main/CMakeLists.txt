set(srcs
	# "main.c"
	# "mc_main.c"
	"factory_reset.c"
	"ota_update.c"
	"platform.c"
	"system.c"
	"main.c"
)

set(includes
	"./"
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
