#include "../features.h"

void features::visuals( ) {

	uintptr_t glow_manager = memory.read<uintptr_t>( memory.m_client_dll + signatures::dwGlowObjectManager );
	
	// to-do: move it somewhere
	auto local = g_client.get_local_player( );

	while ( true ) {
		if ( g_client_state.get_game_state( ) == 6 ) {

			for ( int i = 0; i < 64; i++ ) {
				auto entity = g_entity_list.get_entity( i );

				if ( entity.is_dormant( ) || !entity.is_valid( ) )
					continue;

				if ( entity.get_team_num( ) == local.get_team_num( ) )
					continue;

				const auto glow_index = entity.get_glow_index( );

				GlowObject glow_definition = memory.read<GlowObject>(glow_manager + (glow_index * 0x38) + 0x8);

				glow_definition.m_color_r = 1.f;
				glow_definition.m_color_g = 0.f;
				glow_definition.m_color_b = 0.f;
				glow_definition.m_color_a = 1.f;

				glow_definition.m_render_occluded = true;
				glow_definition.m_render_unoccluded = false;
				glow_definition.m_glow_style = 1;

				memory.write<GlowObject>( glow_manager + ( glow_index * 0x38 ) + 0x8, glow_definition );
			}

		}

		std::this_thread::sleep_for( std::chrono::milliseconds( 10 ) );
	}
}