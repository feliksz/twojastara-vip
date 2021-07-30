#pragma once
#include "../../memory.h"

constexpr int FL_ONGROUND = 257;

class Entity
{
	uintptr_t m_base;

public:
	Entity( uintptr_t base ) {
		m_base = base;
	}

	bool is_valid( ) {
		return m_base != NULL;
	}

	bool is_dormant( ) {
		return memory.read<bool>( m_base + signatures::m_bDormant );
	}

	int get_flags( ) {
		return memory.read<int>( m_base + netvars::m_fFlags );
	}

	int get_glow_index( ) {
		return memory.read<int>( m_base + netvars::m_iGlowIndex );
	}

	int get_team_num( ) {
		return memory.read<int>( m_base + netvars::m_iTeamNum );
	}

};