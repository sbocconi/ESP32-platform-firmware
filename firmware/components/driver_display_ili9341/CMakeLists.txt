set(srcs
	"driver_ili9341.c"
)

set(includes
	"include"
)

set(requires
	"driver_io_mch2021_stm32"
	""	
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
