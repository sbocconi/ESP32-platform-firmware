set(srcs
	"driver_ice40.c"
)

set(includes
	"include"
)

set(requires
	"driver_io_pca9555"
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
