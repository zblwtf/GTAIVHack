
#include <d3d9.h>
#include <d3dx9math.h>
#include "MyTransform.h"
#include "global.h"
#include "MyCamera.h"
#include "Camera.h"
using namespace d3d9;
using namespace GTAIV;


void MyTransform::get_viewmatrix(D3DXMATRIX& ref_matrix)
{

	
	ESP::MyCamera my_camera;
	ref_matrix =  my_camera.getViewMatrix();
	
}
bool MyTransform::get_viewport(D3DVIEWPORT9* viewPort)
{
	if (viewPort == nullptr) {
		return false;
	}
	HRESULT hr = m_d3d9Device->GetViewport(viewPort);
	if (SUCCEEDED(hr)){
		return true;
	}
	else {
		return false;
	}
}
void MyTransform::get_projectmatrix(D3DXMATRIX& ref_matrix, const D3DVIEWPORT9& viewport)
{
	

	float fov = 70;
	
	

	float FOV_rad = fov  * M_PI / 180.0f;

	float aspect = window::width / window::height;
	float aspect_ = aspect + Menu::aspectcompensate;

	float fovyAngle = 2 * atan(tan(FOV_rad / 2) / aspect_);

	


	
	D3DXMatrixPerspectiveFovLH(&ref_matrix, fovyAngle, aspect, 0.01f, 100.0f);

	
	//XMMATRIX projectmatrix = XMMatrixPerspectiveFovLH(FovAngleY, aspect, 0.01f, 100.0f);

}
void MyTransform::get_vpmatrix(D3DXMATRIX& vpmatrix, const D3DVIEWPORT9& viewport)
{
	
	
	D3DXMATRIX view_matrix;
	D3DXMATRIX project_matrix;
	get_viewmatrix(view_matrix);
	get_projectmatrix(project_matrix,viewport);

	D3DXMatrixMultiply(&vpmatrix,  &view_matrix, &project_matrix);
	

}
bool MyTransform::WorldToScreen(vec3& world_pos, vec2& screen_pos)
{
	D3DVIEWPORT9 viewport;
	if (get_viewport(&viewport) == false) {
		logstream << "[-] get ViewPort failed!\n";
		logstream.flush();
		return false;
	}

	D3DXMATRIX vpmatrix;
	get_vpmatrix(vpmatrix,viewport);
	
	D3DXVECTOR3 v_totransform{ world_pos.x,world_pos.z,world_pos.y };
	D3DXVECTOR4 v_transformed;

	D3DXVec3Transform(&v_transformed, &v_totransform, &vpmatrix);
	if (v_transformed.w < 0.1f)
		return false;

	vec3 ndc;
	ndc.x = v_transformed.x / v_transformed.w;
	ndc.y = v_transformed.y / v_transformed.w;
	ndc.z = v_transformed.z / v_transformed.w;
	int window_width = viewport.Width;
	int window_height =viewport.Height;
	

	screen_pos.x = (window_width / 2.0f * ndc.x) + (ndc.x + window_width / 2.0f);
	screen_pos.y = -(window_height / 2.0f * ndc.y) + (ndc.y + window_height/ 2.0f);

	return true;
	
}
void MyTransform::print_matrix(D3DXMATRIX& matrix)
{
	D3DXMATRIX& vm = matrix;
	MyTransform::get_viewmatrix(vm);
	char sp_buf[1024];
	auto format_str = 
		"matrix:\n"
		"%0.2f	%0.2f	%0.2f	%0.2f\n"
		"%0.2f	%0.2f	%0.2f	%0.2f\n"
		"%0.2f	%0.2f	%0.2f	%0.2f\n"
		"%0.2f	%0.2f	%0.2f	%0.2f\n";

	sprintf_s(sp_buf, sizeof(sp_buf), format_str,
		vm.m[0][0], vm.m[1][0], vm.m[2][0], vm.m[3][0],
		vm.m[0][1], vm.m[1][1], vm.m[2][1], vm.m[3][1],
		vm.m[0][2], vm.m[1][2], vm.m[2][2], vm.m[3][2],
		vm.m[0][3], vm.m[1][3], vm.m[2][3], vm.m[3][3]);
	logstream << sp_buf;
	logstream.flush();

}