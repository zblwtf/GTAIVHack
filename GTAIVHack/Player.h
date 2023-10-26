#pragma once
#include <stdint.h>
#include <string>
namespace GTAIV
{
	class Player
	{
	public:
		Player(int id);

		inline int get_index() { return this->m_index; };
		inline int get_id() { return this->m_id; };
		inline int32_t get_char() { return this->m_char; };
		std::string get_name();












	private:
		int m_index;
		int m_id;
		int32_t m_char;
	};
}
