#include "Player.h"
#include "functions.h"

#include <string>

GTAIV::Player::Player(int id):m_id(id)
{
	this->m_index = NativeCall::Player::ConvertIntToPlayerIndex(id);
	NativeCall::Player::GetPlayerChar(this->m_index, &this->m_char);

}
std::string GTAIV::Player::get_name()
{
	return NativeCall::Player::GetPlayerName(this->m_index);
}

