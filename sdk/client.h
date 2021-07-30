#pragma once
#include "structs/entity.h"

class Client {
public:
	Entity get_local_player( ) 
	{
		return Entity( memory.read<uintptr_t>( memory.m_client_dll + signatures::dwLocalPlayer ) );
	}
};