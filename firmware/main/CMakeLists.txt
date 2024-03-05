set(srcs
	"main.c"
	"factory_reset.c"
	"ota_update.c"
	"platform.c"
	"system.c"

)

set(includes
	"./"
	"$ENV{IDF_PATH}/components/mbedtls/mbedtls/tests/include/test/"
)

set(requires
	"buses"
	"driver_display_st7789v"
	"driver_framebuffer"
	"driver_rtcmem"
	"esp_event"
	"resource_ssl_certs"
	# "python"
)

set(priv_requires
	"nvs_flash"
	"spi_flash"
	"app_update"
	"esp_wifi"
	"mbedtls"
	"esp_hw_support"
)

idf_component_register(
	SRCS "${srcs}"
	INCLUDE_DIRS ${includes}
	REQUIRES ${requires}
    PRIV_REQUIRES ${priv_requires}
)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-error)
