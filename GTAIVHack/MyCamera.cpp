#include "MyCamera.h"
#include <Windows.h>
#include "global.h"
#include "Camera.h"
#include <corecrt_math_defines.h>
#include "offset.h"
using namespace d3d9;
using namespace ESP;
float dtor(float d)
{
	return d * M_PI / 180.0f ;
}
MyCamera::MyCamera(D3DXVECTOR3 up) :camerFont(D3DXVECTOR3(0.0f, 0.0f, -1.0f))
{

	worldup = up;
	updateCameraVectors();

}
D3DXMATRIX MyCamera::getViewMatrix()
{
	D3DXMATRIX viewmatrix;
	D3DXVECTOR3 At = this->Eye + this->camerFont;

	updateCameraVectors();
	D3DXMatrixLookAtLH(&viewmatrix, &Eye, &At, &this->Up);

	return viewmatrix;
	//XMMatrixLookAtLH(thisEye, Eye + camerFont, Up);
}
void MyCamera::updateCameraVectors()
{
	Camera game_camera;
	uintptr_t gtabase;
	D3DXVECTOR3 camera_positon(0, 0, 0);
	D3DXVECTOR3 camera_rotation(0, 0, 0);
	
	game_camera.get_positon(camera_positon);
	//GTA��Y����ǰ�� Z�������� X�����ұ�
	//ת��������������ϵ
	Eye = D3DXVECTOR3(camera_positon.x, camera_positon.z, camera_positon.y);

	if (module_base == NULL){
		gtabase = (uintptr_t)GetModuleHandle(NULL);
	}
	else {
		gtabase = module_base;
	}


	uintptr_t pcamera = READ_PTR(gtabase, offset::m_camera);

	if (pcamera == NULL){
		
		
		game_camera.get_rotation(camera_rotation);
		pitch = dtor(camera_rotation.x);
		yaw = M_PI_2 + dtor(camera_rotation.z);
	}
	else {
		pitch = *(float*)(pcamera + offset::m_camera_pitch);
		yaw = M_PI_2 +*(float*)(pcamera + offset::m_camera_yaw);
	}
	
	


	
	
	

	//GTAIV ����ϵ���� yaw����x��ֱ ��z����yaw�ķ���
	

	

	camerFont.x = cos(yaw) * cos(pitch);
	camerFont.y = sin(pitch);
	camerFont.z = sin(yaw) * cos(pitch);
	D3DXVec3Normalize(&camerFont, &camerFont);

	//Font->worldUp
	// right->camerFont
	


	D3DXVec3Cross(&this->camer_right, &camerFont, &this->worldup);
	D3DXVec3Normalize(&this->camer_right, &this->camer_right);

	D3DXVec3Cross(&this->Up, &camer_right, &camerFont);
	D3DXVec3Normalize(&this->Up, &this->Up);


	

}

