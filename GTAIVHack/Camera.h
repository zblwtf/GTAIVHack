#pragma once
#include <stdint.h>
#include <d3d9.h>
#include <d3dx9.h>
class Camera
{
public:
	typedef int32_t camera_handle;
	Camera();
	~Camera();
	bool get_positon(D3DXVECTOR3& positon);
	bool get_rotation(D3DXVECTOR3& rotation);
	bool get_fov(float* fov);
private:
	
	camera_handle m_handle;
};