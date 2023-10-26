// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include <fstream>
#include <string>
void hack()
{
    std::ofstream file;
    std::string path_log = R"(C:/Users/23035/Desktop/loaderlog.txt)";
    std::string path_proxy_dll = R"(C:\Users\23035\Desktop\Home\C++\ProxyScriptHook\Debug\ProxyScriptHook.dll)";
    std::string path_toload = R"(C:\Users\23035\Desktop\Home\C++\GTAIVHack\Debug\GTAIVHack.dll)";

    file.open(path_log, std::ios_base::app);
    HMODULE hLoad;
    HMODULE hProxy;
    hProxy = LoadLibraryA(path_proxy_dll.c_str());
    if (!hProxy)
    {
        file << "Proxy Failed Load\n";
    }
    else
    {
        file << "Proxy Success Load\n";
    }
    hLoad = LoadLibraryA(path_toload.c_str());
    if (!hLoad)
    {
        file << "ToLoad Failed Load\n";
    }
    else
    {
        file << "ToLoad Success Load\n";
    }
    file.flush();
    file.close();
}
BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        hack();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

