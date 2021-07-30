#pragma once
#include "structs/entity.h"
#include "../memory.h"

class EntityList {
public:
	Entity get_entity( int index ) {
		auto nigga = memory.read<uintptr_t>( memory.m_client_dll + signatures::dwEntityList + index * 0x10 );
		return Entity( nigga );
	}
};
