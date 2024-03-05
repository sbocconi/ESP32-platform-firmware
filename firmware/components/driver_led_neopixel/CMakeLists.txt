set(srcs
	"driver_neopixel.c"
)

set(includes
	"include"
)

set(requires
	"driver_input_mpr121"
)

set(priv_requires
	"driver"
)

idf_component_register(
	SRCS "${srcs}"
	INCLUDE_DIRS ${includes}
	REQUIRES ${requires}
    PRIV_REQUIRES ${priv_requires}
)
