/*
https://github.com/natesubra/runcalc-dll
*/

#pragma once

#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#include <shellapi.h> // shellexecute
#include <cstdlib> // system
#include <stdio.h> // _popen

extern "C" __declspec(dllexport) void empty(void){}

extern "C" __declspec(dllexport) void we(void)
{
	WinExec("C:\\Windows\\System32\\calc.exe", SW_SHOWNORMAL);
}

extern "C" __declspec(dllexport) void se(void)
{
	ShellExecuteA(NULL, "open", "C:\\Windows\\System32\\calc.exe", NULL, NULL, SW_SHOW);
}

extern "C" __declspec(dllexport) void sys(void)
{
	system("C:\\Windows\\System32\\calc.exe");
}

extern "C" __declspec(dllexport) void cp(void)
{
	STARTUPINFO startupinfo = { 0 };
	PROCESS_INFORMATION processInfo;

	ZeroMemory(&processInfo, sizeof(processInfo));

	if (CreateProcessW(L"C:\\Windows\\system32\\calc.exe", NULL, NULL, NULL, TRUE, 0, NULL, NULL, &startupinfo, &processInfo))
	{
		CloseHandle(processInfo.hProcess);
		CloseHandle(processInfo.hThread);
	}
}

extern "C" __declspec(dllexport) void ex(void)
{
	_popen("C:\\Windows\\System32\\calc.exe", NULL);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		cp();
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;

	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}