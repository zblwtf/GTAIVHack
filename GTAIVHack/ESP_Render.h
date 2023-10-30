#pragma once
#include "render_data.h"
#include <memory>
class ESP_Render
{
public:
	//��ʼ����������
	static HRESULT InitGeometry();

	static HRESULT UpdateGeometry(render_data* p_bonedata);
	//�����õ��ľ���
	static void SetupMatrices();
	static void StoreOriginStuff();
	static void RestoreOriginStuff();
	static void Render(render_data* p_bonedata);
	
	static void Cleanup();

};