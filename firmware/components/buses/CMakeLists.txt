set(srcs
	"buses.c"
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
