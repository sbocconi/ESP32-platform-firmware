set(srcs
	"driver_mpr121.c"
)

set(includes
	"include"
)

set(requires
	"buses"
)

set(priv_requires
	"driver"
	"nvs_flash"
)

idf_component_register(
	SRCS "${srcs}"
	INCLUDE_DIRS ${includes}
	REQUIRES ${requires}
    PRIV_REQUIRES ${priv_requires}
)
