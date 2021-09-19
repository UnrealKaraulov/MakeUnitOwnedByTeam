/*

1. Если юнит союзник и юнит из списка то он общий.

*/


#pragma region Headers
#define _WIN32_WINNT 0x0501 
#define WINVER 0x0501 
#define NTDDI_VERSION 0x05010000
//#define BOTDEBUG
#define WIN32_LEAN_AND_MEAN
#include <stdexcept>
#include <Windows.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <time.h>
#include <thread>  
#pragma endregion

using namespace std;

int GameDll = 0;

typedef UINT( __cdecl * CreateUnit_p )( UINT id, int unitid, float *x, float *y, float *face );
CreateUnit_p CreateUnit_org;
CreateUnit_p CreateUnit_ptr;

UINT __cdecl  CreateUnit_my( UINT id, int unitid, float *x, float *y, float *face )
{
	UINT retval = CreateUnit_org( id, unitid, x, y, face );


	return retval;
}

typedef int( __fastcall * GetUnitRealByHandle_p )( UINT unithandle, int unused );
GetUnitRealByHandle_p GetUnitRealByHandle_org;
GetUnitRealByHandle_p GetUnitRealByHandle_ptr;
int __fastcall  GetUnitRealByHandle_my ( UINT unithandle, int unused )
{
	int retval = GetUnitRealByHandle_org( unithandle, unused );


	return retval;
}


BOOL WINAPI DllMain( HINSTANCE hDLL, UINT reason, LPVOID reserved )
{
	if ( reason == DLL_PROCESS_ATTACH )
	{
	
	}
	else if ( reason == DLL_PROCESS_DETACH )
	{
	
	}
	return TRUE;
}
