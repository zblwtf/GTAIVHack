#include "Classess.h"
#include "Ped.h"
#include "functions.h"

#include <math.h>
using namespace NativeCall;
using namespace GTAIV;
Ped::Ped(int32_t m_ped) :m_ped(m_ped)
{

}


vec3 Ped::get_position()
{
	vec3 ret;
	Char::GetCharCoordinates(this->m_ped, &ret.x, &ret.y, &ret.z);
	return ret;
}
void Ped::set_position(const vec3& coord)
{
	Char::SetCharCoordinates(this->m_ped, coord.x, coord.y, coord.z);
}

float Ped::get_heading()
{
	float tempHeading;
	Char::GetCharHeading(m_ped, &tempHeading);
	return tempHeading;
}
void Ped::set_heading(float& heading)
{
	Char::SetCharHeading(m_ped, heading);
}
vec3 Ped::get_direction()
{
	float m_heading = get_heading();
	float headingradian = m_heading / 180.0f * 3.1415926575;
	vec3 res;
	res.x = (float)sin(m_heading);
	res.y = (float)cos(m_heading);
	res.z = 0.0f;
	return res;
}

void Ped::set_visible(bool& v)
{
	Char::SetCharVisible(m_ped, v);
}
bool Ped::get_bfire()
{
	return Char::IsCharOnFire(m_ped);
}
void Ped::set_bfire(bool& value)
{

	if (value) {
		int fire = Char::StartCharFire(m_ped);
		if (fire == 0) return;
		
	}
	else {
		Char::ExtinguishCharFire(m_ped);

	}
}

vec3 Ped::get_velocity()
{
	vec3 ret;
	Char::GetCharVelocity(m_ped, &ret.x, &ret.y, &ret.z);
	return ret;
}
void Ped::set_velocity(vec3& veloc)
{
	Char::SetCharVelocity(m_ped,veloc.x, veloc.y, veloc.z);
}
int Ped::get_health()
{
	int m_health;
	Char::GetCharHealth(m_ped, &m_health);
	return m_health;
}
void Ped::set_health(int& m_health)
{
	Char::SetCharHealth(m_ped, m_health+100);
}
void Ped::set_maxhealth(int& max_health)
{
	Char::SetCharMaxHealth(m_ped, max_health + 100);
}
int Ped::get_armor()
{
	int m_armor;
	Char::GetCharArmour(m_ped, &m_armor);
	return m_armor;
}
void Ped::set_armor(int& m_armor)
{
	int narmor = get_armor();
	int diff = m_armor - narmor;
	if (diff == 0)return;
	Char::AddArmourToChar(m_ped, diff);
}
unsigned int Ped::get_money()
{
	
	return Char::GetCharMoney(m_ped);
	
}
void Ped::set_money(unsigned int& m_money)
{
	Char::SetCharMoney(m_ped, m_money);
}
bool Ped::get_balive()
{
	return !Char::IsCharDead(m_ped);
}
bool Ped::get_bdead()
{
	return Char::IsCharDead(m_ped);
}
bool Ped::get_bonscreen()
{
	return Char::IsCharOnScreen(m_ped);

}
bool Ped::get_shooting()
{
	return Char::IsCharShooting(m_ped);
}
bool Ped::get_bswimming()
{
	return Char::IsCharSwimming(m_ped);
}
PedType Ped::get_pedtype()
{
	int intPedType;
	Char::GetPedType(m_ped, &intPedType);
	return (PedType)intPedType;
}
vec3 Ped::get_bonepositon(PedBone boneId)
{

	


	vec3 m_bonePositon{ 0 };
	Char::GetPedBonePosition(m_ped, (uint32_t)boneId, 0,0,0, &m_bonePositon);
	return m_bonePositon;
}




#include "Player.h"
bool GTAIV::get_localplayer(Ped* pped)
{
	if (pped == nullptr) {
		return false;
	}

	auto id_LocalPlayer = NativeCall::Player::GetLocalPlayerId();
	if (id_LocalPlayer < 0) {
		return false;
	}
	auto char_niko = GTAIV::Player(id_LocalPlayer).get_char();
	if (char_niko < 0) {
		return false;
	}
	
	*pped = Ped(char_niko);
	return true;
}
bool GTAIV::get_localplayer_handle(int32_t* phandle)
{
	if (phandle == nullptr) {
		return false;
	}

	auto id_LocalPlayer = NativeCall::Player::GetLocalPlayerId();
	if (id_LocalPlayer < 0) {
		return false;
	}
	auto char_niko = GTAIV::Player(id_LocalPlayer).get_char();
	if (char_niko < 0) {
		return false;
	}

	*phandle = char_niko;
	return true;
}
bool GTAIV::get_localplayer_id(int* pid)
{
	if (pid == nullptr) {
		return false;
	}

	auto id_LocalPlayer = NativeCall::Player::GetLocalPlayerId();
	if (id_LocalPlayer < 0) {
		return false;
	}
	*pid = id_LocalPlayer;
	return true;
}