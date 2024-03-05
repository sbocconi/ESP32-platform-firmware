set(srcs
	"driver_st7789v.c"
)

set(includes
	"include"
)

set(requires
  	"driver"
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
