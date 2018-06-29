/*
	Yelo: Open Sauce SDK
		Halo 1 (CE) Edition

	See license\OpenSauce\Halo1_CE for specific license information
*/
#include <halo/halo.h>
#include "Game/Lights.hpp"

#include "Memory/MemoryInterface.hpp"
#include <Pointers/Game.Lights.hpp>

namespace Yelo
{
	namespace Lights
	{
		lights_data_t& Lights()									DPTR_IMP_GET_BYREF(lights);
		s_lights_globals_data* LightsGlobals()					DPTR_IMP_GET(light_game_globals);
		s_light_cluster_data* LightCluster()					DPTR_IMP_GET(light_cluster);
		cluster_light_reference_data_t& ClusterLightReference()	DPTR_IMP_GET_BYREF(cluster_light_reference);
		light_cluster_reference_data_t& LightClusterReference()	DPTR_IMP_GET_BYREF(light_cluster_reference);
	};
};