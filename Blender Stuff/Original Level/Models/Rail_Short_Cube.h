// "Rail_Short_Cube.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "Rail_Short_Cube.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _Rail_Short_Cube_version_
const char Rail_Short_Cube_version[4] = { '0','1','9','d' };
#define _Rail_Short_Cube_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _Rail_Short_Cube_vertexcount_
const unsigned Rail_Short_Cube_vertexcount = 144;
#define _Rail_Short_Cube_vertexcount_
#endif
#ifndef _Rail_Short_Cube_indexcount_
const unsigned Rail_Short_Cube_indexcount = 768;
#define _Rail_Short_Cube_indexcount_
#endif
#ifndef _Rail_Short_Cube_materialcount_
const unsigned Rail_Short_Cube_materialcount = 1; // can be used for batched draws
#define _Rail_Short_Cube_materialcount_
#endif
#ifndef _Rail_Short_Cube_meshcount_
const unsigned Rail_Short_Cube_meshcount = 1;
#define _Rail_Short_Cube_meshcount_
#endif
/************************************************/
/*  This section contains the raw data to load  */
/************************************************/
#ifndef __OBJ_VEC3__
typedef struct _OBJ_VEC3_
{
	float x,y,z; // 3D Coordinate.
}OBJ_VEC3;
#define __OBJ_VEC3__
#endif
#ifndef __OBJ_VERT__
typedef struct _OBJ_VERT_
{
	OBJ_VEC3 pos; // Left-handed +Z forward coordinate w not provided, assumed to be 1.
	OBJ_VEC3 uvw; // D3D/Vulkan style top left 0,0 coordinate.
	OBJ_VEC3 nrm; // Provided direct from obj file, may or may not be normalized.
}OBJ_VERT;
#define __OBJ_VERT__
#endif
#ifndef _Rail_Short_Cube_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT Rail_Short_Cube_vertices[144] =
{
	{	{ 0.000000f, 0.176690f, 0.022747f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, -0.707800f, 0.706400f }	},
	{	{ 0.000000f, 0.169394f, 0.000393f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, -1.000000f, -0.007000f }	},
	{	{ 0.470556f, 0.168506f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.007500f, -1.000000f, -0.000200f }	},
	{	{ 0.566509f, 0.170870f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.308900f, -0.951100f, -0.000000f }	},
	{	{ 0.559772f, 0.170091f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.058700f, -0.998300f, -0.000000f }	},
	{	{ 0.562120f, 0.176679f, -0.023142f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.025900f, -0.729800f, -0.683200f }	},
	{	{ 0.471225f, 0.175780f, -0.022663f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.002500f, -0.712800f, -0.701300f }	},
	{	{ 0.562120f, 0.176679f, 0.022910f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.025900f, -0.729800f, 0.683100f }	},
	{	{ 0.471225f, 0.175780f, 0.022431f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.003400f, -0.712900f, 0.701200f }	},
	{	{ 0.624632f, 0.163579f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.987600f, 0.156900f, -0.000000f }	},
	{	{ 0.616413f, 0.193912f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.893000f, 0.450000f, -0.000000f }	},
	{	{ 0.610424f, 0.190795f, 0.021837f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.679400f, 0.340000f, 0.650200f }	},
	{	{ 0.601435f, 0.212952f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.610600f, 0.791900f, 0.000000f }	},
	{	{ 0.597070f, 0.207692f, 0.021791f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.462200f, 0.608300f, 0.645300f }	},
	{	{ 0.610424f, 0.190795f, -0.022069f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.679400f, 0.340000f, -0.650200f }	},
	{	{ 0.597070f, 0.207692f, -0.022023f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.462200f, 0.608300f, -0.645300f }	},
	{	{ 0.592461f, 0.181446f, -0.030242f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.071400f, 0.031600f, -0.996900f }	},
	{	{ 0.617566f, 0.162447f, -0.022206f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.727400f, 0.108800f, -0.677600f }	},
	{	{ 0.583972f, 0.191911f, -0.030321f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.049500f, 0.071400f, -0.996200f }	},
	{	{ 0.574496f, 0.172097f, -0.023352f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.604200f, -0.268000f, -0.750400f }	},
	{	{ 0.596368f, 0.159052f, -0.030085f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.026100f, 0.003100f, -0.999700f }	},
	{	{ 0.596368f, 0.159051f, 0.029853f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.026100f, 0.003100f, 0.999700f }	},
	{	{ 0.592461f, 0.181446f, 0.030010f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.071400f, 0.031600f, 0.996900f }	},
	{	{ 0.574496f, 0.172097f, 0.023121f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.604100f, -0.268000f, 0.750500f }	},
	{	{ 0.583973f, 0.191911f, 0.030090f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.049600f, 0.071400f, 0.996200f }	},
	{	{ 0.617566f, 0.162447f, 0.021975f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.727400f, 0.108800f, 0.677600f }	},
	{	{ 0.597086f, -0.007305f, 0.029777f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.000200f, -0.000600f, 1.000000f }	},
	{	{ 0.597437f, 0.118731f, 0.029792f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.009400f, 0.000300f, 1.000000f }	},
	{	{ 0.575083f, 0.117884f, 0.022495f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.707700f, 0.001700f, 0.706500f }	},
	{	{ 0.575170f, 0.155656f, 0.022747f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.716900f, -0.017500f, 0.696900f }	},
	{	{ 0.619791f, 0.119577f, 0.022134f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.714100f, 0.017200f, 0.699800f }	},
	{	{ 0.619557f, -0.007305f, 0.022304f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.706500f, -0.001200f, 0.707700f }	},
	{	{ 0.597437f, 0.118731f, -0.030023f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.009400f, 0.000300f, -1.000000f }	},
	{	{ 0.619791f, 0.119577f, -0.022366f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.714100f, 0.017200f, -0.699800f }	},
	{	{ 0.619557f, -0.007305f, -0.022536f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.706500f, -0.001200f, -0.707700f }	},
	{	{ 0.575083f, 0.117884f, -0.022727f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.707700f, 0.001700f, -0.706500f }	},
	{	{ 0.575170f, 0.155656f, -0.022979f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.716900f, -0.017500f, -0.696900f }	},
	{	{ 0.597086f, -0.007305f, -0.030009f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.000200f, -0.000600f, -1.000000f }	},
	{	{ 0.627047f, -0.007305f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 1.000000f, -0.001400f, -0.000000f }	},
	{	{ 0.627242f, 0.119859f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.999600f, 0.026900f, -0.000000f }	},
	{	{ 0.567632f, 0.117602f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -1.000000f, 0.008000f, 0.000000f }	},
	{	{ 0.574615f, -0.007305f, -0.022536f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.707500f, 0.002000f, -0.706700f }	},
	{	{ 0.568104f, 0.154524f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.999900f, 0.016000f, 0.000000f }	},
	{	{ 0.567124f, -0.007305f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -1.000000f, 0.004100f, -0.000000f }	},
	{	{ 0.574615f, -0.007305f, 0.022304f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.707500f, 0.002000f, 0.706700f }	},
	{	{ 0.569162f, 0.196443f, 0.029918f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000800f, 0.048600f, 0.998800f }	},
	{	{ 0.570875f, 0.176131f, 0.023286f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.291000f, -0.582300f, 0.759100f }	},
	{	{ 0.473232f, 0.197601f, 0.029714f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000600f, 0.007200f, 1.000000f }	},
	{	{ 0.576205f, 0.216207f, 0.021908f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.155600f, 0.736800f, 0.658000f }	},
	{	{ 0.475239f, 0.219422f, 0.022082f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.011800f, 0.716700f, 0.697300f }	},
	{	{ 0.578553f, 0.222795f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.220200f, 0.975400f, -0.000000f }	},
	{	{ 0.475907f, 0.226696f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.019400f, 0.999800f, -0.000100f }	},
	{	{ 0.576205f, 0.216207f, -0.022140f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.155600f, 0.736700f, -0.658000f }	},
	{	{ 0.569162f, 0.196443f, -0.030149f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000800f, 0.048600f, -0.998800f }	},
	{	{ 0.473232f, 0.197601f, -0.029946f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.000500f, 0.007300f, -1.000000f }	},
	{	{ 0.475239f, 0.219422f, -0.022314f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.011000f, 0.716500f, -0.697500f }	},
	{	{ 0.570875f, 0.176131f, -0.023517f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.291000f, -0.582300f, -0.759100f }	},
	{	{ 0.568509f, 0.168981f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.922400f, -0.386300f, -0.000000f }	},
	{	{ 0.000000f, 0.177051f, -0.021961f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.000000f, -0.704700f, -0.709500f }	},
	{	{ 0.000000f, 0.199301f, 0.030198f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.000000f, 0.000700f, 1.000000f }	},
	{	{ 0.000000f, 0.199301f, -0.029412f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, 0.000700f, -1.000000f }	},
	{	{ 0.000000f, 0.229209f, 0.000393f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.000000f, 1.000000f, -0.006800f }	},
	{	{ 0.000000f, 0.221912f, 0.022747f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, 0.708800f, 0.705400f }	},
	{	{ 0.000000f, 0.221551f, -0.021961f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, 0.705500f, -0.708700f }	},
	{	{ 0.585026f, 0.106570f, 0.002316f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.000600f, -0.616600f, 0.787300f }	},
	{	{ 0.000000f, 0.107288f, 0.002400f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, -0.601800f, 0.798700f }	},
	{	{ 0.000000f, 0.106468f, 0.000707f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, -1.000000f, 0.000100f }	},
	{	{ 0.585026f, 0.105581f, -0.000049f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.001700f, -0.999900f, 0.011500f }	},
	{	{ 0.000000f, 0.107521f, -0.001465f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, -0.607900f, -0.794000f }	},
	{	{ 0.585026f, 0.118088f, 0.004108f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000700f, 0.011300f, 0.999900f }	},
	{	{ 0.000000f, 0.119866f, 0.004592f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, -0.000600f, 1.000000f }	},
	{	{ 0.000000f, 0.119866f, -0.003810f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, -0.000700f, -1.000000f }	},
	{	{ 0.585026f, 0.118086f, -0.004340f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.001200f, 0.011200f, -0.999900f }	},
	{	{ 0.585026f, 0.130802f, -0.000049f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.004300f, 0.999900f, 0.014300f }	},
	{	{ 0.000000f, 0.133312f, 0.000711f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, 1.000000f, 0.001400f }	},
	{	{ 0.000000f, 0.132476f, 0.002419f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, 0.600400f, 0.799700f }	},
	{	{ 0.585026f, 0.129778f, 0.002007f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.003200f, 0.599000f, 0.800700f }	},
	{	{ 0.000000f, 0.132243f, -0.001484f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000000f, 0.607500f, -0.794400f }	},
	{	{ 0.585026f, 0.129807f, -0.002203f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.001600f, 0.611600f, -0.791200f }	},
	{	{ -0.471225f, 0.175780f, 0.022431f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.003400f, -0.712900f, 0.701200f }	},
	{	{ -0.470556f, 0.168506f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.007500f, -1.000000f, -0.000200f }	},
	{	{ -0.562120f, 0.176679f, -0.023142f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.025900f, -0.729800f, -0.683200f }	},
	{	{ -0.559772f, 0.170091f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.058700f, -0.998300f, -0.000000f }	},
	{	{ -0.566509f, 0.170870f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.308900f, -0.951100f, -0.000000f }	},
	{	{ -0.471225f, 0.175780f, -0.022663f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.002500f, -0.712800f, -0.701300f }	},
	{	{ -0.562120f, 0.176679f, 0.022910f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.025900f, -0.729800f, 0.683100f }	},
	{	{ -0.610424f, 0.190795f, 0.021837f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.679400f, 0.340000f, 0.650200f }	},
	{	{ -0.616413f, 0.193912f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.893000f, 0.450000f, -0.000000f }	},
	{	{ -0.624632f, 0.163579f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.987600f, 0.156900f, -0.000000f }	},
	{	{ -0.597070f, 0.207692f, 0.021791f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.462200f, 0.608300f, 0.645300f }	},
	{	{ -0.601435f, 0.212952f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.610600f, 0.791900f, -0.000000f }	},
	{	{ -0.597070f, 0.207692f, -0.022023f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.462200f, 0.608300f, -0.645300f }	},
	{	{ -0.610424f, 0.190795f, -0.022069f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.679400f, 0.340000f, -0.650200f }	},
	{	{ -0.592461f, 0.181446f, -0.030242f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.071400f, 0.031600f, -0.996900f }	},
	{	{ -0.596368f, 0.159052f, -0.030085f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.026100f, 0.003100f, -0.999700f }	},
	{	{ -0.617566f, 0.162447f, -0.022206f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.727400f, 0.108800f, -0.677600f }	},
	{	{ -0.583972f, 0.191911f, -0.030321f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.049500f, 0.071400f, -0.996200f }	},
	{	{ -0.574496f, 0.172097f, -0.023352f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.604200f, -0.268000f, -0.750400f }	},
	{	{ -0.574496f, 0.172097f, 0.023121f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.604100f, -0.268000f, 0.750500f }	},
	{	{ -0.592461f, 0.181446f, 0.030010f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.071400f, 0.031600f, 0.996900f }	},
	{	{ -0.596368f, 0.159051f, 0.029853f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.026100f, 0.003100f, 0.999700f }	},
	{	{ -0.583973f, 0.191911f, 0.030090f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.049600f, 0.071400f, 0.996200f }	},
	{	{ -0.617566f, 0.162447f, 0.021975f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.727400f, 0.108800f, 0.677600f }	},
	{	{ -0.575083f, 0.117884f, 0.022495f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.707700f, 0.001700f, 0.706500f }	},
	{	{ -0.597437f, 0.118731f, 0.029792f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.009400f, 0.000300f, 1.000000f }	},
	{	{ -0.597086f, -0.007305f, 0.029777f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000200f, -0.000600f, 1.000000f }	},
	{	{ -0.575170f, 0.155656f, 0.022747f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.716900f, -0.017500f, 0.696900f }	},
	{	{ -0.619791f, 0.119577f, 0.022134f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.714100f, 0.017200f, 0.699800f }	},
	{	{ -0.619557f, -0.007305f, 0.022304f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.706500f, -0.001200f, 0.707700f }	},
	{	{ -0.597437f, 0.118731f, -0.030023f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.009400f, 0.000300f, -1.000000f }	},
	{	{ -0.597086f, -0.007305f, -0.030009f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000200f, -0.000600f, -1.000000f }	},
	{	{ -0.619557f, -0.007305f, -0.022536f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.706500f, -0.001200f, -0.707700f }	},
	{	{ -0.619791f, 0.119577f, -0.022366f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.714100f, 0.017200f, -0.699800f }	},
	{	{ -0.575170f, 0.155656f, -0.022979f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.716900f, -0.017500f, -0.696900f }	},
	{	{ -0.575083f, 0.117884f, -0.022727f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.707700f, 0.001700f, -0.706500f }	},
	{	{ -0.627242f, 0.119859f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.999600f, 0.026900f, -0.000000f }	},
	{	{ -0.627047f, -0.007305f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -1.000000f, -0.001400f, -0.000000f }	},
	{	{ -0.567632f, 0.117602f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 1.000000f, 0.008000f, 0.000000f }	},
	{	{ -0.567124f, -0.007305f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 1.000000f, 0.004100f, -0.000000f }	},
	{	{ -0.574615f, -0.007305f, -0.022536f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.707500f, 0.002000f, -0.706700f }	},
	{	{ -0.568104f, 0.154524f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.999900f, 0.016000f, -0.000000f }	},
	{	{ -0.574615f, -0.007305f, 0.022304f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.707500f, 0.002000f, 0.706700f }	},
	{	{ -0.569162f, 0.196443f, 0.029918f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.000800f, 0.048600f, 0.998800f }	},
	{	{ -0.570875f, 0.176131f, 0.023286f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.291000f, -0.582300f, 0.759100f }	},
	{	{ -0.473232f, 0.197601f, 0.029714f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.000600f, 0.007200f, 1.000000f }	},
	{	{ -0.475239f, 0.219422f, 0.022082f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.011800f, 0.716700f, 0.697300f }	},
	{	{ -0.576205f, 0.216207f, 0.021908f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.155600f, 0.736800f, 0.658000f }	},
	{	{ -0.578553f, 0.222795f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.220200f, 0.975400f, 0.000000f }	},
	{	{ -0.475907f, 0.226696f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.019400f, 0.999800f, -0.000100f }	},
	{	{ -0.576205f, 0.216207f, -0.022140f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.155600f, 0.736700f, -0.658000f }	},
	{	{ -0.569162f, 0.196443f, -0.030149f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.000800f, 0.048600f, -0.998800f }	},
	{	{ -0.475239f, 0.219422f, -0.022314f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.011000f, 0.716500f, -0.697500f }	},
	{	{ -0.473232f, 0.197601f, -0.029946f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000500f, 0.007300f, -1.000000f }	},
	{	{ -0.570875f, 0.176131f, -0.023517f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.291000f, -0.582300f, -0.759100f }	},
	{	{ -0.568509f, 0.168981f, -0.000116f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.922400f, -0.386300f, -0.000000f }	},
	{	{ -0.585026f, 0.106570f, 0.002316f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.000600f, -0.616600f, 0.787300f }	},
	{	{ -0.585026f, 0.105581f, -0.000049f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.001700f, -0.999900f, 0.011500f }	},
	{	{ -0.585026f, 0.118088f, 0.004108f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.000700f, 0.011300f, 0.999900f }	},
	{	{ -0.585026f, 0.106544f, -0.002515f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.002400f, -0.627000f, -0.779000f }	},
	{	{ -0.585026f, 0.118086f, -0.004340f },	{ 0.000000f, 1.000000f, 0.000000f },	{ 0.001200f, 0.011200f, -0.999900f }	},
	{	{ -0.585026f, 0.130802f, -0.000049f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.004300f, 0.999900f, 0.014200f }	},
	{	{ -0.585026f, 0.129778f, 0.002008f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.003200f, 0.599100f, 0.800700f }	},
	{	{ -0.585026f, 0.129807f, -0.002203f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.001600f, 0.611600f, -0.791200f }	},
	{	{ 0.585026f, 0.106544f, -0.002515f },	{ 0.000000f, 1.000000f, 0.000000f },	{ -0.002400f, -0.627000f, -0.779000f }	},
};
#define _Rail_Short_Cube_vertices_
#endif
#ifndef _Rail_Short_Cube_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int Rail_Short_Cube_indices[768] =
{
	 0, 1, 2,
	 3, 4, 5,
	 4, 2, 6,
	 4, 7, 8,
	 7, 4, 3,
	 9, 10, 11,
	 10, 12, 13,
	 10, 14, 15,
	 14, 10, 9,
	 16, 14, 17,
	 14, 16, 18,
	 18, 16, 19,
	 19, 16, 20,
	 21, 22, 23,
	 23, 22, 24,
	 24, 22, 11,
	 22, 21, 25,
	 26, 27, 28,
	 27, 21, 29,
	 21, 27, 30,
	 27, 26, 31,
	 32, 33, 34,
	 33, 32, 20,
	 32, 35, 36,
	 35, 32, 37,
	 38, 39, 30,
	 39, 9, 25,
	 39, 33, 17,
	 33, 39, 38,
	 40, 35, 41,
	 35, 40, 42,
	 42, 40, 28,
	 40, 43, 44,
	 45, 7, 46,
	 7, 45, 47,
	 45, 48, 49,
	 48, 45, 24,
	 50, 48, 13,
	 48, 50, 51,
	 51, 50, 52,
	 50, 12, 15,
	 18, 53, 52,
	 53, 54, 55,
	 54, 53, 5,
	 53, 18, 56,
	 57, 19, 36,
	 57, 3, 56,
	 57, 23, 46,
	 57, 42, 29,
	 2, 1, 58,
	 59, 0, 8,
	 6, 58, 60,
	 61, 62, 49,
	 62, 59, 47,
	 54, 60, 63,
	 55, 63, 61,
	 64, 65, 66,
	 67, 66, 68,
	 69, 70, 65,
	 68, 71, 72,
	 73, 74, 75,
	 76, 75, 70,
	 71, 77, 78,
	 77, 74, 73,
	 0, 79, 80,
	 81, 82, 83,
	 82, 81, 84,
	 82, 80, 79,
	 83, 82, 85,
	 86, 87, 88,
	 87, 86, 89,
	 87, 90, 91,
	 88, 87, 92,
	 93, 94, 95,
	 96, 93, 92,
	 97, 93, 96,
	 94, 93, 97,
	 98, 99, 100,
	 101, 99, 98,
	 86, 99, 101,
	 99, 86, 102,
	 103, 104, 105,
	 104, 103, 106,
	 107, 104, 100,
	 104, 107, 108,
	 109, 110, 111,
	 94, 109, 112,
	 109, 94, 113,
	 110, 109, 114,
	 107, 115, 116,
	 115, 107, 102,
	 115, 88, 95,
	 116, 115, 112,
	 117, 118, 119,
	 120, 117, 114,
	 103, 117, 120,
	 117, 103, 121,
	 122, 101, 123,
	 124, 122, 85,
	 122, 124, 125,
	 101, 122, 126,
	 127, 90, 89,
	 128, 127, 126,
	 129, 127, 128,
	 127, 129, 91,
	 129, 130, 96,
	 130, 129, 131,
	 81, 130, 132,
	 130, 81, 133,
	 134, 120, 113,
	 134, 97, 133,
	 134, 83, 123,
	 134, 98, 106,
	 58, 1, 80,
	 59, 124, 79,
	 60, 58, 84,
	 61, 128, 125,
	 62, 125, 124,
	 63, 60, 132,
	 61, 63, 131,
	 66, 65, 135,
	 68, 66, 136,
	 65, 70, 137,
	 68, 138, 139,
	 75, 74, 140,
	 70, 75, 141,
	 71, 139, 142,
	 77, 142, 140,
	 0, 2, 8,
	 3, 5, 56,
	 4, 6, 5,
	 4, 8, 2,
	 7, 3, 46,
	 9, 11, 25,
	 10, 13, 11,
	 10, 15, 12,
	 14, 9, 17,
	 16, 17, 20,
	 14, 18, 15,
	 18, 19, 56,
	 19, 20, 36,
	 21, 23, 29,
	 23, 24, 46,
	 24, 11, 13,
	 22, 25, 11,
	 26, 28, 44,
	 27, 29, 28,
	 21, 30, 25,
	 27, 31, 30,
	 32, 34, 37,
	 33, 20, 17,
	 32, 36, 20,
	 35, 37, 41,
	 38, 30, 31,
	 39, 25, 30,
	 39, 17, 9,
	 33, 38, 34,
	 40, 41, 43,
	 35, 42, 36,
	 42, 28, 29,
	 40, 44, 28,
	 45, 46, 24,
	 7, 47, 8,
	 45, 49, 47,
	 48, 24, 13,
	 50, 13, 12,
	 48, 51, 49,
	 51, 52, 55,
	 50, 15, 52,
	 18, 52, 15,
	 53, 55, 52,
	 54, 5, 6,
	 53, 56, 5,
	 57, 36, 42,
	 57, 56, 19,
	 57, 46, 3,
	 57, 29, 23,
	 2, 58, 6,
	 59, 8, 47,
	 6, 60, 54,
	 61, 49, 51,
	 62, 47, 49,
	 54, 63, 55,
	 55, 61, 51,
	 64, 66, 67,
	 67, 68, 143,
	 69, 65, 64,
	 68, 72, 143,
	 73, 75, 76,
	 76, 70, 69,
	 71, 78, 72,
	 77, 73, 78,
	 0, 80, 1,
	 81, 83, 133,
	 82, 84, 80,
	 82, 79, 85,
	 83, 85, 123,
	 86, 88, 102,
	 87, 89, 90,
	 87, 91, 92,
	 88, 92, 95,
	 93, 95, 92,
	 96, 92, 91,
	 97, 96, 133,
	 94, 97, 113,
	 98, 100, 106,
	 101, 98, 123,
	 86, 101, 89,
	 99, 102, 100,
	 103, 105, 121,
	 104, 106, 100,
	 107, 100, 102,
	 104, 108, 105,
	 109, 111, 112,
	 94, 112, 95,
	 109, 113, 114,
	 110, 114, 119,
	 107, 116, 108,
	 115, 102, 88,
	 115, 95, 112,
	 116, 112, 111,
	 117, 119, 114,
	 120, 114, 113,
	 103, 120, 106,
	 117, 121, 118,
	 122, 123, 85,
	 124, 85, 79,
	 122, 125, 126,
	 101, 126, 89,
	 127, 89, 126,
	 128, 126, 125,
	 129, 128, 131,
	 127, 91, 90,
	 129, 96, 91,
	 130, 131, 132,
	 81, 132, 84,
	 130, 133, 96,
	 134, 113, 97,
	 134, 133, 83,
	 134, 123, 98,
	 134, 106, 120,
	 58, 80, 84,
	 59, 79, 0,
	 60, 84, 132,
	 61, 125, 62,
	 62, 124, 59,
	 63, 132, 131,
	 61, 131, 128,
	 66, 135, 136,
	 68, 136, 138,
	 65, 137, 135,
	 68, 139, 71,
	 75, 140, 141,
	 70, 141, 137,
	 71, 142, 77,
	 77, 140, 74,
};
#define _Rail_Short_Cube_indices_
#endif
// Part of an OBJ_MATERIAL, the struct is 16 byte aligned so it is GPU register friendly.
#ifndef __OBJ_ATTRIBUTES__
typedef struct _OBJ_ATTRIBUTES_
{
	OBJ_VEC3    Kd; // diffuse reflectivity
	float	    d; // dissolve (transparency) 
	OBJ_VEC3    Ks; // specular reflectivity
	float       Ns; // specular exponent
	OBJ_VEC3    Ka; // ambient reflectivity
	float       sharpness; // local reflection map sharpness
	OBJ_VEC3    Tf; // transmission filter
	float       Ni; // optical density (index of refraction)
	OBJ_VEC3    Ke; // emissive reflectivity
	unsigned    illum; // illumination model
}OBJ_ATTRIBUTES;
#define __OBJ_ATTRIBUTES__
#endif
// This structure also has been made GPU register friendly so it can be transfered directly if desired.
// Note: Total struct size will vary depenedening on CPU processor architecture (string pointers).
#ifndef __OBJ_MATERIAL__
typedef struct _OBJ_MATERIAL_
{
	// The following items are typically used in a pixel/fragment shader, they are packed for GPU registers.
	OBJ_ATTRIBUTES attrib; // Surface shading characteristics & illumination model
	// All items below this line are not needed on the GPU and are generally only used during load time.
	const char* name; // the name of this material
	// If the model's materials contain any specific texture data it will be located below.
	const char* map_Kd; // diffuse texture
	const char* map_Ks; // specular texture
	const char* map_Ka; // ambient texture
	const char* map_Ke; // emissive texture
	const char* map_Ns; // specular exponent texture
	const char* map_d; // transparency texture
	const char* disp; // roughness map (displacement)
	const char* decal; // decal texture (lerps texture & material colors)
	const char* bump; // normal/bumpmap texture
	void* padding[2]; // 16 byte alignment on 32bit or 64bit
}OBJ_MATERIAL;
#define __OBJ_MATERIAL__
#endif
#ifndef _Rail_Short_Cube_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL Rail_Short_Cube_materials[1] =
{
	{
		{{ 0.800000f, 0.800000f, 0.800000f },
		1.000000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		0.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.450000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		1},
		"Black.009",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
	},
};
#define _Rail_Short_Cube_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _Rail_Short_Cube_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int Rail_Short_Cube_batches[1][2] =
{
	{ 768, 0 },
};
#define _Rail_Short_Cube_batches_
#endif
#ifndef __OBJ_MESH__
typedef struct _OBJ_MESH_
{
	const char* name;
	unsigned    indexCount;
	unsigned    indexOffset;
	unsigned    materialIndex;
}OBJ_MESH;
#define __OBJ_MESH__
#endif
#ifndef _Rail_Short_Cube_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH Rail_Short_Cube_meshes[1] =
{
	{
		"default",
		768,
		0,
		0,
	},
};
#define _Rail_Short_Cube_meshes_
#endif
