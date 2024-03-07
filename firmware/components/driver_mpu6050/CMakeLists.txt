set(srcs
	"driver_mpu6050.c"
)

set(includes
	"include"
)

set(requires
	""
)

set(priv_requires
	"buses"
	"driver"
)

idf_component_register(
	SRCS "${srcs}"
	INCLUDE_DIRS ${includes}
	REQUIRES ${requires}
    PRIV_REQUIRES ${priv_requires}
)
