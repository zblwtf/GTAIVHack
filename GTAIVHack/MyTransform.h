#pragma once
#include "Classess.h"
#include <d3d9.h>
#include <D3dx9math.h>
namespace GTAIV
{
	class MyTransform
	{
	public:
		static void get_viewmatrix(D3DXMATRIX& pmatrix);
		static bool get_viewport(D3DVIEWPORT9* viewPort);
		static void get_projectmatrix(D3DXMATRIX& pmatrix, const D3DVIEWPORT9& viewport);
		static void get_vpmatrix(D3DXMATRIX& pmatrix, const D3DVIEWPORT9& viewport);
		static bool WorldToScreen(vec3&, vec2&);
		static void print_matrix(D3DXMATRIX& matrix);
	};
   	
}
