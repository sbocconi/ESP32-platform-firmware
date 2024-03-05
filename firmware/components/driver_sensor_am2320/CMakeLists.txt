set(srcs
	"driver_am2320.c"
)

set(includes
	"include"
)

set(requires
	"buses"
)

set(priv_requires
	"driver"
	"esp_timer"
)

idf_component_register(
	SRCS "${srcs}"
	INCLUDE_DIRS ${includes}
	REQUIRES ${requires}
    PRIV_REQUIRES ${priv_requires}
)
