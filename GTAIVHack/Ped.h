#pragma once
#include "Classess.h"
#include "enums.h"
#include <stdint.h>

namespace GTAIV
{
	

	class Ped
	{
	private:
		int m_ped;
	public:
		Ped(int);

		
		vec3 get_position();
		void set_position(const vec3&);

		float get_heading();
		void set_heading(float&);

		vec3 get_direction();
		
		void set_visible(bool&);
		//
		bool get_bfire();
		void set_bfire(bool&);


		vec3 get_velocity();
		void set_velocity(vec3&);

		int get_health();
		void set_health(int&);

		void set_maxhealth(int&);

		int get_armor();
		void set_armor(int&);

		unsigned int get_money();
		void set_money(unsigned int&);

		bool get_balive();
		bool get_bdead();

		bool get_bonscreen();
		
		bool get_shooting();


		bool get_bswimming();

		PedType get_pedtype();

		vec3 get_bonepositon(PedBone boneid);
		
	};

	bool get_localplayer(Ped* ppedd);

	bool get_localplayer_handle(int32_t* phandle);
	
	bool get_localplayer_id(int* pid);
}