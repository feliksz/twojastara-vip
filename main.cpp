#include <iostream>
#include <thread>
#include "features.h"
#include "memory.h"
#include "sdk.h"

int main( ) {
	// this will find csgo process and find modules
	if ( memory.initialize( "csgo.exe" ) ) {

		std::thread misc_thread( features::misc );
		misc_thread.detach( );

		std::thread visuals_thread( features::visuals );
		visuals_thread.detach( );


	}
	
	std::cin.ignore( );

	return 0;
}