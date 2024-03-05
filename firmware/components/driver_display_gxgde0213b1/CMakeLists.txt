set(srcs
	"driver_gxgde0213b1.c"
)

set(includes
	"include"
)

set(requires
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
