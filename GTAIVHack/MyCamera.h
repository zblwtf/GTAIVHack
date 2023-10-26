#pragma once
#include "Classess.h"
#include <d3d9.h>
#include <d3dx9.h>

namespace ESP
{
	class MyCamera
	{
	public:
		MyCamera(D3DXVECTOR3 up = { 0.0f,1.0f,0.0f });
		D3DXMATRIX getViewMatrix();
	private:
		D3DXVECTOR3 Eye;
		D3DXVECTOR3 Up;
		D3DXVECTOR3 worldup;
		D3DXVECTOR3 camer_right;
		D3DXVECTOR3 camerFont;
		float pitch;
		float yaw;
		
		void updateCameraVectors();
	};
}