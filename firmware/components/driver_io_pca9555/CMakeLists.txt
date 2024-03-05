set(srcs
	"driver_pca9555.c"
)

set(includes
	"include"
)

set(requires
	"driver_io_pca9555"
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
