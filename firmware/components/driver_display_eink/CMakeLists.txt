set(srcs
	"driver_eink.c"
	"driver_eink_lut.c"
	"driver_eink_dev.c"
)

set(includes
	"include"
)

set(requires
	""
)

set(priv_requires
	"nvs_flash"
	"driver"
)

idf_component_register(
	SRCS "${srcs}"
	INCLUDE_DIRS ${includes}
	REQUIRES ${requires}
    PRIV_REQUIRES ${priv_requires}
)
