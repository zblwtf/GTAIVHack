// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "ScriptHook/Game.h"
#include <fstream>
#include <string>
#include "Ped.h"
#include "Player.h"
#include "functions.h"
#include "bone_data_pool.h"
#include "global.h"
#include "Hook.h"
#include "MouseHook.h"
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
HANDLE hthread_hack = NULL;
HANDLE hthread_mousehook = NULL;

void hack_init()
{


    logstream << "[+] Logstream Created!\n";
    logstream.flush();
    
    module_base = (uintptr_t)GetModuleHandleA(NULL);
   
    ESP::sp_bone_data_pool.reset(new bone_data_pool());
    ESP::sp_myworkshop.reset(new bone_data_workshop(5));

#pragma region init NativeCall 
    
    
    HMODULE hLib = GetModuleHandleA("ScriptHook.dll");
    if (hLib == NULL) {
        logstream << "[-] LoadLibrary Failed\n";
        logstream.flush();
        logstream.close();
        return;
    }


    NativeCall::pGetNativeAddress = (NativeCall::fnGetNativeAddress)GetProcAddress((HMODULE)hLib, "?GetNativeAddress@Game@@SAPAXPBD@Z");

    if (!NativeCall::pGetNativeAddress)
    {
        logstream << "[-] GetProcAddress Failed\n";
        logstream.flush();
        logstream.close();
        return;
    }
#pragma endregion

    

   

       

#pragma region start Hook
    Hook::install_hook();
#pragma endregion

    
    
}

DWORD WINAPI thread_mousehook(HMODULE hModule)
{
    Hook::m_pMouseHook = new MouseHook();
    if (!Hook::m_pMouseHook->get_hook()) {
        delete Hook::m_pMouseHook;
        Hook::m_pMouseHook = nullptr;
    }
    else {
        logstream << "[+] Create MouseHook Success!\n";
        Hook::m_pMouseHook->push_msg();

        delete Hook::m_pMouseHook;
        Hook::m_pMouseHook = nullptr;
    }
    return 0;
}

DWORD WINAPI thread_hack(HMODULE hModule)
{
    hack_init();
    while (true) {
        if (Hook::end)break;
        Sleep(10);
    }
    
    Hook::clean_hook();

    logstream << "[+] Close Logstream\n";
    logstream.close();

    ESP::sp_bone_data_pool.~shared_ptr();
    ESP::sp_myworkshop.~shared_ptr();
    FreeLibraryAndExitThread(hModule, 0);
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:


#pragma region Init Logstream
     
        if (!logstream.is_open()) {
            return 0;
        }
#pragma endregion

#pragma region Create Threads
        hthread_hack = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)thread_hack, hModule, NULL, nullptr);
        hthread_mousehook = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)thread_mousehook, hModule, NULL, nullptr);
        if (hthread_hack) {
            CloseHandle(hthread_hack);
        }
        if (hthread_mousehook) {
            CloseHandle(hthread_mousehook);
        }
        
#pragma endregion

        


    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

