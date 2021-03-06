#define VARS_VIEWPROJ
#define VARS_FOG
#define VARS_TEXSCALE
#define VARS_NODEMATRIX
#define VARS_NORMALSSCALE
#include "include/rasterizer_dx9_vertex_shaders_defs2.h"
#include "include/fog.fx"
#include "include/model/model_vs.fx"

Technique model_fogged
{
	Pass P0
	{
		VertexShader = compile TGT ModelVS(false, true);
	}
}