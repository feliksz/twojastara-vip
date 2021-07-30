#pragma once
#include "hd.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <TlHelp32.h>


class Memory
{
	HANDLE m_handle	= NULL;
	DWORD  m_pid = NULL;

public:
	uintptr_t m_client_dll = NULL;
	uintptr_t m_engine_dll = NULL;

public:
	bool initialize( const std::string& process_name ) {
		if ( !get_process( process_name ) )
			return false;

		m_client_dll = get_module_address( "client.dll" );
		m_engine_dll = get_module_address( "engine.dll" );

		return true;
	}

	bool get_process( const std::string& process_name ) {
		auto snapshot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );

		PROCESSENTRY32 entry;
		entry.dwSize = sizeof( entry );

		do {
			if ( process_name.compare( entry.szExeFile ) == 0 ) {
				CloseHandle( snapshot );

				m_pid = entry.th32ProcessID;
				m_handle = OpenProcess( PROCESS_ALL_ACCESS, false, m_pid );
				printf( "[+] found %s (pid: %i)\n", process_name.c_str( ), m_pid );

				return true;
			}

		} while ( Process32Next( snapshot, &entry ) );

		printf( "%s is not launched", process_name.c_str( ) );
		return false;
	}

	DWORD get_module_address( const std::string& module_name ) {
		auto snapshot = CreateToolhelp32Snapshot( TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, m_pid );

		MODULEENTRY32 entry;
		entry.dwSize = sizeof( entry );

		do {
			if ( module_name.compare( entry.szModule ) == 0 ) {
				CloseHandle( snapshot );
				printf( "[+] found %s at 0x%X\n", module_name.c_str(), ( DWORD ) entry.modBaseAddr );
				return ( DWORD ) entry.modBaseAddr;
			}

		} while ( Module32Next( snapshot, &entry ) );

		printf( "[-] couldn't find %s\n", module_name.c_str( ) );
		CloseHandle( snapshot );
		return NULL;

	}

	template <typename t>
	t read( DWORD address ) {
		t ret_value;
		ReadProcessMemory( m_handle, ( void* ) address, &ret_value, sizeof( ret_value ), NULL );
		return ret_value;
	}

	template <typename t>
	bool write( DWORD address, t value ) {
		return WriteProcessMemory( m_handle, ( void* ) address, &value, sizeof( value ), NULL );
	}
};

inline Memory memory;