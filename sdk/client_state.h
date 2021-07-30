#pragma once
#include "../memory.h"


class ClientState {
	uintptr_t get_client_state( ) {
		return memory.read<uintptr_t>( memory.m_engine_dll + signatures::dwClientState );
	}

public:
	int get_game_state( ) {
		return memory.read<int>( get_client_state( ) + signatures::dwClientState_State );
	}
};
