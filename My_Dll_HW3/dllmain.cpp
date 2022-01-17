// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"

//BOOL APIENTRY DllMain( HMODULE hModule,
//                       DWORD  ul_reason_for_call,
//                       LPVOID lpReserved
//                     )
//{
//    switch (ul_reason_for_call)
//    {
//    case DLL_PROCESS_ATTACH:
//    case DLL_THREAD_ATTACH:
//    case DLL_THREAD_DETACH:
//    case DLL_PROCESS_DETACH:
//        break;
//    }
//    return TRUE;
//}

extern "C" __declspec(dllexport) int Sum(int a, int b) {
    return a + b;
}
extern "C" __declspec(dllexport) bool Task2(int a, int b) {
    if ((Sum(a, b) == 10) || ((a == 10) && (b == 10))) { return true; }
    else { return false; }
}
    
extern "C" __declspec(dllexport) int Task3(int a, int* arrI) {
    int j = 0;
    for (int i = 1; i <= a; i++) {
        if (i % 2 != 0) {
            arrI[j] = i;
            j++;
        }
    }
    return 0;
}
