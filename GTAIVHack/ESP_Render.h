#pragma once
#include "render_data.h"
#include <memory>
class ESP_Render
{
public:
	//初始化顶点数组
	static HRESULT InitGeometry();

	static HRESULT UpdateGeometry(render_data* p_bonedata);
	//设置用到的矩阵
	static void SetupMatrices();
	static void StoreOriginStuff();
	static void RestoreOriginStuff();
	static void Render(render_data* p_bonedata);
	
	static void Cleanup();

};