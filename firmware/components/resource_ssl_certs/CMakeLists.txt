set(srcs
	"pinned_certs.c"
)

set(includes
	"./"
)

set(requires
	""
)

set(priv_requires
	""
)

idf_component_register(
	SRCS "${srcs}"
	INCLUDE_DIRS ${includes}
	REQUIRES ${requires}
    PRIV_REQUIRES ${priv_requires}
)
