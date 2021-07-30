#pragma once
#include <vector>
#include "sdk/structs/entity.h"
#include "sdk/structs/glow_object.h"
#include "sdk/client.h"
#include "sdk/client_state.h"
#include "sdk/entity_list.h"

#include "hd.h"
#include "memory.h"

namespace {

	Client		g_client;
	ClientState g_client_state;
	EntityList	g_entity_list;

}