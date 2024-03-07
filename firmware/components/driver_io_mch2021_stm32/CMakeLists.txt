set(srcs
	"driver_mch2021_stm32.c"
)

set(includes
	"include"
)

set(requires
	""
)

set(priv_requires
	"driver_io_pca9555"
	"driver"
)

idf_component_register(
	SRCS "${srcs}"
	INCLUDE_DIRS ${includes}
	REQUIRES ${requires}
    PRIV_REQUIRES ${priv_requires}
)
