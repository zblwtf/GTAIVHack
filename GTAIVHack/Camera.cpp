
#include "Camera.h"
#include "functions.h"

Camera::Camera()
{
	camera_handle temp_handle;
	//NativeCall::Camera::GetGameCamChild(&temp_handle);
	//NativeCall::Camera::GetRootCam(&temp_handle);
	NativeCall::Camera::GetGameCam(&temp_handle);
	this->m_handle = temp_handle;
}
Camera::~Camera()
{
	this->m_handle = -100;
}
bool Camera::get_positon(D3DXVECTOR3& positon)
{
	if (this->m_handle < 0) {
		return false;
	}
	NativeCall::Camera::GetCamPos(this->m_handle, &positon.x, &positon.y, &positon.z);
	if (positon != D3DXVECTOR3(0, 0, 0)){
		return true;
	}
	else {
		return false;
	}
}
bool Camera::get_rotation(D3DXVECTOR3& rotation)
{
	if (this->m_handle < 0) {
		return false;
	}
	NativeCall::Camera::GetCamRot(this->m_handle, &rotation.x, &rotation.y, &rotation.z);

	if (rotation != D3DXVECTOR3(0, 0, 0)) {
		return true;
	}
	else {
		return false;
	}
}

bool Camera::get_fov(float* pfov)
{
	if (this->m_handle < 0 || pfov == nullptr) {
		return false;
	}
	NativeCall::Camera::GetCamFov(this->m_handle, pfov);

	if (*pfov <= 0) {
		return false;
	}
	else {
		return true;
	}
}