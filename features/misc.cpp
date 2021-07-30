#include "../features.h"

void features::misc( ) {

	auto local = g_client.get_local_player( );

	while ( true ) {
		if ( g_client_state.get_game_state( ) == 6 ) {

			auto flags = local.get_flags( );

			if ( GetAsyncKeyState( VK_SPACE ) )
				memory.write( memory.m_client_dll + signatures::dwForceJump, flags == 256 ? 4 : 5 );

		}
		std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );
	}
}