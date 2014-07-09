/*
	Yelo: Open Sauce SDK
		Halo 1 (Editing Kit) Edition

	See license\OpenSauce\Halo1_CheApe for specific license information
*/
#pragma once

#if PLATFORM_TYPE == PLATFORM_TOOL
namespace Yelo
{
	namespace Tool { namespace Shader { namespace Compiler
	{
		void PLATFORM_API compile_shaders(char* arguments[]);
	};};};
};
#endif