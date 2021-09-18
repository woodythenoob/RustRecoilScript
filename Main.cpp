#include "Main.h"
#include <Windows.h>
#include "skCrypter.h"
#include "Weapons.h"
#include <iostream>
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#include <iostream>
#include "string.h"
#include <string>
#include <tchar.h>
#include <string.h>
#include <urlmon.h>
#include <Windows.h>
#include <Mmsystem.h>
#include "Windows.h"
#include <Windows.h>
#include <mmstream.h>
#include <fstream>
#include "skCrypter.h"
#include "Globals.h"
#include <iostream>
#include <tlhelp32.h>
#include <fstream>
#include <filesystem>
#include <iostream>
#include "string.h"
#include <string>
#include <tchar.h>
#include <string.h>
#include <urlmon.h>
#include <Windows.h>
#include <Mmsystem.h>
#include "Windows.h"
#include <Windows.h>
#include <mmstream.h>
#include <fstream>
#include <wingdi.h>

bool ishidden = false;

using namespace std;
using namespace KeyAuth;

typedef struct D3DXVECTOR2 {
    FLOAT x;
    FLOAT y;
} D3DXVECTOR2, * LPD3DXVECTOR2;

void DrawRectA(IDirect3DDevice9* Unidade, int baseX, int baseY, int baseW, int baseH, D3DCOLOR Cor)
{
    D3DRECT BarRect = { baseX, baseY, baseX + baseW, baseY + baseH };
    Unidade->Clear(1, &BarRect, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, Cor, 0, 0);
}

// Keybinds //
static const char* enable[]{ "None", "Insert", "Home", "Delete", "End", "Page Up", "Page Down", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "Up Arrow", "Down Arrow", "Right Arrow", "Left Arrow"};
static int selectedEnabled = 0;

static const char* reducerecoil[]{ "100%", "75%", "50%", "25%" };
static int selectedRecoil = 0;

static const char* hide[]{ "None", "Insert", "Home", "Delete", "End", "Page Up", "Page Down", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "Up Arrow", "Down Arrow", "Right Arrow", "Left Arrow" };
static int selectedHide = 0;

static const char* keybindak[]{ "None", "Insert", "Home", "Delete", "End", "Page Up", "Page Down", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "Up Arrow", "Down Arrow", "Right Arrow", "Left Arrow" };
static int selectedkeybindak = 0;

static const char* keybindlr[]{ "None", "Insert", "Home", "Delete", "End", "Page Up", "Page Down", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "Up Arrow", "Down Arrow", "Right Arrow", "Left Arrow" };
static int selectedkeybindlr = 0;

static const char* keybindmp5[]{ "None", "Insert", "Home", "Delete", "End", "Page Up", "Page Down", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "Up Arrow", "Down Arrow", "Right Arrow", "Left Arrow" };
static int selectedkeybindmp5 = 0;

static const char* keybindsmg[]{ "None", "Insert", "Home", "Delete", "End", "Page Up", "Page Down", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "Up Arrow", "Down Arrow", "Right Arrow", "Left Arrow" };
static int selectedkeybindsmg = 0;

static const char* keybindtommy[]{ "None", "Insert", "Home", "Delete", "End", "Page Up", "Page Down", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "Up Arrow", "Down Arrow", "Right Arrow", "Left Arrow" };
static int selectedkeybindtommy = 0;

static const char* keybindsar[]{ "None", "Insert", "Home", "Delete", "End", "Page Up", "Page Down", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "Up Arrow", "Down Arrow", "Right Arrow", "Left Arrow" };
static int selectedkeybindsar = 0;

static const char* keybindm2[]{ "None", "Insert", "Home", "Delete", "End", "Page Up", "Page Down", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "Up Arrow", "Down Arrow", "Right Arrow", "Left Arrow" };
static int selectedkeybindm2 = 0;

static const char* keybindlegitmode[]{ "None", "Insert", "Home", "Delete", "End", "Page Up", "Page Down", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "Up Arrow", "Down Arrow", "Right Arrow", "Left Arrow" };
static int selectedlegitmode = 0;
// End of key binds //

static const char* keybindholosight[]{ "None", "Insert", "Home", "Delete", "End", "Page Up", "Page Down", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "Up Arrow", "Down Arrow", "Right Arrow", "Left Arrow" };
static int selectedkeybindholosight = 0;

static const char* keybindsimplesight[]{ "None", "Insert", "Home", "Delete", "End", "Page Up", "Page Down", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "Up Arrow", "Down Arrow", "Right Arrow", "Left Arrow" };
static int selectedkeybindsimplesight = 0;

static const char* keybindx8[]{ "None", "Insert", "Home", "Delete", "End", "Page Up", "Page Down", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "Up Arrow", "Down Arrow", "Right Arrow", "Left Arrow" };
static int selectedkeybindx8 = 0;

static const char* keybindx16[]{ "None", "Insert", "Home", "Delete", "End", "Page Up", "Page Down", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "Up Arrow", "Down Arrow", "Right Arrow", "Left Arrow" };
static int selectedkeybindx16 = 0;

static const char* keybindsuppresor[]{ "None", "Insert", "Home", "Delete", "End", "Page Up", "Page Down", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "Up Arrow", "Down Arrow", "Right Arrow", "Left Arrow" };
static int selectedkeybindsuppresor = 0;

static const char* keybindnogun[]{ "None", "Insert", "Home", "Delete", "End", "Page Up", "Page Down", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "Up Arrow", "Down Arrow", "Right Arrow", "Left Arrow" };
static int selectedkeybindnogun = 0;

static const char* keybindnosight[]{ "None", "Insert", "Home", "Delete", "End", "Page Up", "Page Down", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "Up Arrow", "Down Arrow", "Right Arrow", "Left Arrow" };
static int selectedkeybindnosight = 0;

static const char* keybindnobarrel[]{ "None", "Insert", "Home", "Delete", "End", "Page Up", "Page Down", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "Up Arrow", "Down Arrow", "Right Arrow", "Left Arrow" };
static int selectedkeybindnobarrel = 0;

static const char* crosshair[]{ "None", "Dot", "+", "Collapse" };
static int selectedCrosshair = 0;

static const char* weapon[]{ "None", "AK-47", "LR-300", "MP5", "Custom", "Thompson", "Semi Auto Rifle", "M249" };
static int selectedWeapon = 0;

static const char* scope[]{ "None", "Holo Sight", "Simple Sight", "x8", "x16" };
static int selectedScope = 0;

static const char* barrel[]{ "None", "Silencer" };
static int selectedBarrel = 0;
int randomizer = 0;
int playerfov = 0;
float playersens = 0;
bool enabled = false;
int keycode = 0;
bool hidden = false;
bool hipfire = false;
bool autodetected = false;
bool crosshairEnable = false;
bool newconfig = false;
bool rememberme = 0;
bool antiafk = 0;
bool legitmode = 0;
int number = 0;
bool f3152tvfeg25y246thet = false;

using namespace KeyAuth;

char key[60] = "";

float Randomize(float val, int perc)
{
    if (selectedRecoil == 0)
    {
        return val;
    }
    if (selectedRecoil == 1)
    {
        return val * 0.75;
    }
    if (selectedRecoil == 2)
    {
        return val * 0.5;
    }
    if (selectedRecoil == 3)
    {
        return val * 0.25;
    }

}

void QuerySleep(int ms)
{
    LONGLONG timerResolution;
    LONGLONG wantedTime;
    LONGLONG currentTime;

    QueryPerformanceFrequency((LARGE_INTEGER*)&timerResolution);
    timerResolution /= 1000;

    QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
    wantedTime = currentTime / timerResolution + ms;
    currentTime = 0;
    while (currentTime < wantedTime)
    {
        QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
        currentTime /= timerResolution;
    }
}



void Smoothing(double delay, double control_time, float x, float y)
{
    int x_ = 0, y_ = 0, t_ = 0;
    for (int i = 1; i <= (int)control_time; ++i)
    {
        int xI = i * x / (int)control_time;
        int yI = i * y / (int)control_time;
        int tI = i * (int)control_time / (int)control_time;
        mouse_event(1, (int)xI - (int)x_, (int)yI - (int)y_, 0, 0);
        QuerySleep((int)tI - (int)t_);
        x_ = xI; y_ = yI; t_ = tI;
    }
    QuerySleep((int)delay - (int)control_time);
}

float getScope(float val)
{
    if (selectedWeapon == 1)   // AK-47
    {
        if (selectedScope == 1)   // Holo sight
        {
            if (selectedBarrel == 1)     /// Holo + silincer
            {
                return val * 0.97;      /// Holo + silincer
            }
            else
            {
                return val * 1.21;            //holo
            }
        }
        if (selectedScope == 2)   // 4x
        {
            if (selectedBarrel == 1)     // 4x + silincer
            {
                return val * 0.65; // 4x + silincer
            }
            else
            {
                return val * 0.81;  // 8x
            }
        }
        if (selectedScope == 3)   // 8x
        {
            if (selectedBarrel == 1)     // 8x + silincer
            {
                return val * 3.84; // 8x + silincer
            }
            else
            {
                return val * 3.84;  // 8x
            }
        }
        if (selectedScope == 4)   //simple
        {
            if (selectedBarrel == 1)     // simple + silincer
            {
                return val * 7.68; // simple + silincer
            }
            else
            {
                return val * 7.68;  //simple
            }
        }
        if (selectedBarrel == 1)  // Silencer
        {
            return val * 0.8125; // Silencer
        }
        else
        {
            return val * 1.00775;   // No attachments 
        }
    }


    if (selectedWeapon == 2)   // LR-300
    {
        if (selectedScope == 1)   // Holo sight
        {
            if (selectedBarrel == 1)     /// Holo + silincer
            {
                return val * 0.98;      /// Holo + silincer
            }
            else
            {
                return val * 1.24;            //holo
            }
        }
        if (selectedScope == 2)   // 4x
        {
            if (selectedBarrel == 1)     // 4x + silincer
            {
                return val * 0.65; // 4x + silincer
            }
            else
            {
                return val * 0.84;  // 4x
            }
        }
        if (selectedScope == 3)   // 8x
        {
            if (selectedBarrel == 1)     // 8x + silincer
            {
                return val * 3.9; // 8x + silincer
            }
            else
            {
                return val * 3.9;  // 8x
            }
        }
        if (selectedScope == 4)   //simple
        {
            if (selectedBarrel == 1)     // simple + silincer
            {
                return val * 7.8; // simple + silincer
            }
            else
            {
                return val * 7.8;  //simple
            }
        }
        if (selectedBarrel == 1)  // Silencer
        {
            return val * 0.8125; // Silencer
        }
        else
        {
            return val;   // No attachments 
        }
    }

    if (selectedWeapon == 3)   // mp5
    {
        if (selectedScope == 1)   // Holo sight
        {
            if (selectedBarrel == 1)     /// Holo + silincer
            {
                return val * 1;      /// Holo + silincer
            }
            else
            {
                return val * 1.25;            //holo
            }
        }
        if (selectedScope == 2)   // 4x
        {
            if (selectedBarrel == 1)     // 4x + silincer
            {
                return val * 0.71; // 4x + silincer
            }
            else
            {
                return val * 0.845;  // 4x
            }
        }
        if (selectedScope == 3)   // 8x
        {
            if (selectedBarrel == 1)     // 8x + silincer
            {
                return val * 3.95; // 8x + silincer
            }
            else
            {
                return val * 3.95;  // 8x
            }
        }
        if (selectedScope == 4)   //simple
        {
            if (selectedBarrel == 1)     // simple + silincer
            {
                return val * 7.9; // simple + silincer
            }
            else
            {
                return val * 7.9;  //simple
            }
        }
        if (selectedBarrel == 1)  // Silencer
        {
            return val * 0.8125; // Silencer
        }
        else
        {
            return val * 1.03;   // No attachments 
        }
    }

    if (selectedWeapon == 4)   // cuystom smg
    {
        if (selectedScope == 1)   // Holo sight
        {
            if (selectedBarrel == 1)     /// Holo + silincer
            {
                return val * 1.15;      /// Holo + silincer
            }
            else
            {
                return val * 1.45;            //holo
            }
        }
        if (selectedScope == 2)   // 4x
        {
            if (selectedBarrel == 1)     // 4x + silincer
            {
                return val * 0.71; // 4x + silincer
            }
            else
            {
                return val * 0.843;  // 4x
            }
        }
        if (selectedScope == 3)   // 8x
        {
            if (selectedBarrel == 1)     // 8x + silincer
            {
                return val * 4.56; // 8x + silincer
            }
            else
            {
                return val * 4.56;  // 8x
            }
        }
        if (selectedScope == 4)   //simple
        {
            if (selectedBarrel == 1)     // simple + silincer
            {
                return val * 9.12; // simple + silincer
            }
            else
            {
                return val * 9.12;  //simple
            }
        }
        if (selectedBarrel == 1)  // Silencer
        {
            return val * 0.8125; // Silencer
        }
        else
        {
            return val;   // No attachments 
        }
    }

    if (selectedWeapon == 5)   // Tommy
    {
        if (selectedScope == 1)   // Holo sight
        {
            if (selectedBarrel == 1)     /// Holo + silincer
            {
                return val * 1.15;      /// Holo + silincer
            }
            else
            {
                return val * 1.45;            //holo
            }
        }
        if (selectedScope == 2)   // 4x
        {
            if (selectedBarrel == 1)     // 4x + silincer
            {
                return val * 0.71; // 4x + silincer
            }
            else
            {
                return val * 0.843;  // 4x
            }
        }
        if (selectedScope == 3)   // 8x
        {
            if (selectedBarrel == 1)     // 8x + silincer
            {
                return val * 4.56; // 8x + silincer
            }
            else
            {
                return val * 4.56;  // 8x
            }
        }
        if (selectedScope == 4)   //simple
        {
            if (selectedBarrel == 1)     // simple + silincer
            {
                return val * 9.12; // simple + silincer
            }
            else
            {
                return val * 9.12;  //simple
            }
        }
        if (selectedBarrel == 1)  // Silencer
        {
            return val * 0.8125; // Silencer
        }
        else
        {
            return val * 0.985;   // No attachments 
        }
    }

    if (selectedWeapon == 6)   // SEMI RIFLE
    {
        if (selectedScope == 1)   // Holo sight
        {
            if (selectedBarrel == 1)     /// Holo + silincer
            {
                return val * 1;      /// Holo + silincer
            }
            else
            {
                return val * 1.25;            //holo
            }
        }
        if (selectedScope == 2)   // 4x
        {
            if (selectedBarrel == 1)     // 4x + silincer
            {
                return val * 0.67; // 4x + silincer
            }
            else
            {
                return val * 0.853;  // 4x
            }
        }
        if (selectedScope == 3)   // 8x
        {
            if (selectedBarrel == 1)     // 8x + silincer
            {
                return val * 3.95; // 8x + silincer
            }
            else
            {
                return val * 3.9;  // 8x
            }
        }
        if (selectedScope == 4)   //simple
        {
            if (selectedBarrel == 1)     // simple + silincer
            {
                return val * 7.9; // simple + silincer
            }
            else
            {
                return val * 7.7;  //simple
            }
        }
        if (selectedBarrel == 1)  // Silencer
        {
            return val * 0.815; // Silencer
        }
        else
        {
            return val * 1.078;   // No attachments 
        }
    }

    if (selectedWeapon == 7)   // m249
    {
        if (selectedScope == 1)   // Holo sight
        {
            if (selectedBarrel == 1)     /// Holo + silincer
            {
                return val * 1;      /// Holo + silincer
            }
            else
            {
                return val * 1.228;            //holo
            }
        }
        if (selectedScope == 2)   // 4x
        {
            if (selectedBarrel == 1)     // 4x + silincer
            {
                return val * 0.71; // 4x + silincer
            }
            else
            {
                return val * 0.825;  // 4x
            }
        }
        if (selectedScope == 3)   // 8x
        {
            if (selectedBarrel == 1)     // 8x + silincer
            {
                return val * 3.895; // 8x + silincer
            }
            else
            {
                return val * 3.895; //8x
            }
        }
        if (selectedScope == 4)   //simple
        {
            if (selectedBarrel == 1)     // simple + silincer
            {
                return val * 7.9; // simple + silincer
            }
            else
            {
                return val * 7.855;  //simple
            }
        }
        if (selectedBarrel == 1)  // Silencer
        {
            return val * 0.814; // Silencer
        }
        else
        {
            return val * 1.03;   // No attachments 
        }
    }
}

float tofovandsens(float sens, int fov, float val)
{
    float a = (0.5 * fov * val) / (sens * 90);

    return getScope(a);

}

void getsettings()
{
    LONG   lResult;
    HKEY   hKey;
    LPBYTE folder = new BYTE[MAX_PATH];
    DWORD  dwSize = sizeof(folder);
    char   value[64];
    DWORD  value_length = 64;
    DWORD  dwType = REG_SZ;

    lResult = RegOpenKey(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\"
            "Uninstall\\Steam App 252490"),
        &hKey);

    RegQueryValueExA(hKey, std::string(skCrypt("InstallLocation")).c_str(), NULL, &dwType,
        (LPBYTE)&value, &value_length);

    RegCloseKey(hKey);

    std::ifstream file;
    std::string line;
    int fileLine = 0;

    std::string client(skCrypt("\\cfg\\client.cfg"));

    file.open(std::string(value) + client); // path to rust

    while (std::getline(file, line))
    {
        fileLine++;

        if (line.find("graphics.fov") != std::string::npos) { // makes sure we read the correct line of the .cfg file
            std::string fovString = line;
            size_t pos = fovString.find(" ");
            fovString = fovString.substr(pos + 2);
            std::stringstream fovConv(fovString);

            fovConv >> playerfov;
        }
        else if (line.find("input.sensitivity") != std::string::npos) { // makes sure we read the correct line of the .cfg file

            std::string sensString = line;
            size_t pos = sensString.find(' ');

            sensString = sensString.substr(pos + 2);
            std::stringstream sensConv(sensString);

            sensConv >> playersens;
        }
    }
}

void gethide()
{
    LONG   lResult;
    HKEY   hKey;
    LPBYTE folder = new BYTE[MAX_PATH];
    DWORD  dwSize = sizeof(folder);
    char   value[64];
    DWORD  value_length = 64;
    DWORD  dwType = REG_SZ;

    lResult = RegOpenKey(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\"
            "Uninstall\\Steam App 252490"),
        &hKey);

    RegQueryValueExA(hKey, std::string(skCrypt("InstallLocation")).c_str(), NULL, &dwType,
        (LPBYTE)&value, &value_length);

    RegCloseKey(hKey);

    std::ifstream file;
    std::string line;
    int fileLine = 0;

    std::string client(skCrypt("\\cfg\\selectedhide.cfg"));

    file.open(std::string(value) + client); // path to rust

    while (std::getline(file, line))
    {
        fileLine++;
        if (line.find("selected.hide") != std::string::npos) { // makes sure we read the correct line of the .cfg file
            std::string fovString = line;
            size_t pos = fovString.find(" ");
            fovString = fovString.substr(pos + 2);
            std::stringstream fovConv(fovString);

            fovConv >> selectedHide;
        }
    }
}

void akkeybind()
{
    LONG   lResult;
    HKEY   hKey;
    LPBYTE folder = new BYTE[MAX_PATH];
    DWORD  dwSize = sizeof(folder);
    char   value[64];
    DWORD  value_length = 64;
    DWORD  dwType = REG_SZ;

    lResult = RegOpenKey(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\"
            "Uninstall\\Steam App 252490"),
        &hKey);

    RegQueryValueExA(hKey, std::string(skCrypt("InstallLocation")).c_str(), NULL, &dwType,
        (LPBYTE)&value, &value_length);

    RegCloseKey(hKey);

    std::ifstream file;
    std::string line;
    int fileLine = 0;

    std::string client(skCrypt("\\cfg\\selectedakbind.cfg"));

    file.open(std::string(value) + client); // path to rust

    while (std::getline(file, line))
    {
        fileLine++;
        if (line.find("selected.akbind") != std::string::npos) { // makes sure we read the correct line of the .cfg file
            std::string fovString = line;
            size_t pos = fovString.find(" ");
            fovString = fovString.substr(pos + 2);
            std::stringstream fovConv(fovString);

            fovConv >> selectedkeybindak;
        }
    }
}

void legitmodebind()
{
    LONG   lResult;
    HKEY   hKey;
    LPBYTE folder = new BYTE[MAX_PATH];
    DWORD  dwSize = sizeof(folder);
    char   value[64];
    DWORD  value_length = 64;
    DWORD  dwType = REG_SZ;

    lResult = RegOpenKey(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\"
            "Uninstall\\Steam App 252490"),
        &hKey);

    RegQueryValueExA(hKey, std::string(skCrypt("InstallLocation")).c_str(), NULL, &dwType,
        (LPBYTE)&value, &value_length);

    RegCloseKey(hKey);

    std::ifstream file;
    std::string line;
    int fileLine = 0;

    std::string client(skCrypt("\\cfg\\selectedkeybindlegitmode.cfg"));

    file.open(std::string(value) + client); // path to rust

    while (std::getline(file, line))
    {
        fileLine++;
        if (line.find("selected.legitmode") != std::string::npos) { // makes sure we read the correct line of the .cfg file
            std::string fovString = line;
            size_t pos = fovString.find(" ");
            fovString = fovString.substr(pos + 2);
            std::stringstream fovConv(fovString);

            fovConv >> selectedlegitmode;
        }
    }
}

void holokeybind()
{
    LONG   lResult;
    HKEY   hKey;
    LPBYTE folder = new BYTE[MAX_PATH];
    DWORD  dwSize = sizeof(folder);
    char   value[64];
    DWORD  value_length = 64;
    DWORD  dwType = REG_SZ;

    lResult = RegOpenKey(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\"
            "Uninstall\\Steam App 252490"),
        &hKey);

    RegQueryValueExA(hKey, std::string(skCrypt("InstallLocation")).c_str(), NULL, &dwType,
        (LPBYTE)&value, &value_length);

    RegCloseKey(hKey);

    std::ifstream file;
    std::string line;
    int fileLine = 0;

    std::string client(skCrypt("\\cfg\\selectedholosightbind.cfg"));

    file.open(std::string(value) + client); // path to rust

    while (std::getline(file, line))
    {
        fileLine++;
        if (line.find("selected.holosightbind") != std::string::npos) { // makes sure we read the correct line of the .cfg file
            std::string fovString = line;
            size_t pos = fovString.find(" ");
            fovString = fovString.substr(pos + 2);
            std::stringstream fovConv(fovString);

            fovConv >> selectedkeybindholosight;
        }
    }
}

void simplekeybind()
{
    LONG   lResult;
    HKEY   hKey;
    LPBYTE folder = new BYTE[MAX_PATH];
    DWORD  dwSize = sizeof(folder);
    char   value[64];
    DWORD  value_length = 64;
    DWORD  dwType = REG_SZ;

    lResult = RegOpenKey(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\"
            "Uninstall\\Steam App 252490"),
        &hKey);

    RegQueryValueExA(hKey, std::string(skCrypt("InstallLocation")).c_str(), NULL, &dwType,
        (LPBYTE)&value, &value_length);

    RegCloseKey(hKey);

    std::ifstream file;
    std::string line;
    int fileLine = 0;

    std::string client(skCrypt("\\cfg\\selectedsimplesightbind.cfg"));

    file.open(std::string(value) + client); // path to rust

    while (std::getline(file, line))
    {
        fileLine++;
        if (line.find("selected.simplesightbind") != std::string::npos) { // makes sure we read the correct line of the .cfg file
            std::string fovString = line;
            size_t pos = fovString.find(" ");
            fovString = fovString.substr(pos + 2);
            std::stringstream fovConv(fovString);

            fovConv >> selectedkeybindsimplesight;
        }
    }
}

void barrelskeybind()
{
    LONG   lResult;
    HKEY   hKey;
    LPBYTE folder = new BYTE[MAX_PATH];
    DWORD  dwSize = sizeof(folder);
    char   value[64];
    DWORD  value_length = 64;
    DWORD  dwType = REG_SZ;

    lResult = RegOpenKey(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\"
            "Uninstall\\Steam App 252490"),
        &hKey);

    RegQueryValueExA(hKey, std::string(skCrypt("InstallLocation")).c_str(), NULL, &dwType,
        (LPBYTE)&value, &value_length);

    RegCloseKey(hKey);

    std::ifstream file;
    std::string line;
    int fileLine = 0;

    std::string client(skCrypt("\\cfg\\selectedsuppressorbind.cfg"));

    file.open(std::string(value) + client); // path to rust

    while (std::getline(file, line))
    {
        fileLine++;
        if (line.find("selected.suppressorbind") != std::string::npos) { // makes sure we read the correct line of the .cfg file
            std::string fovString = line;
            size_t pos = fovString.find(" ");
            fovString = fovString.substr(pos + 2);
            std::stringstream fovConv(fovString);

            fovConv >> selectedkeybindsuppresor;
        }
    }
}

void x8keybind()
{
    LONG   lResult;
    HKEY   hKey;
    LPBYTE folder = new BYTE[MAX_PATH];
    DWORD  dwSize = sizeof(folder);
    char   value[64];
    DWORD  value_length = 64;
    DWORD  dwType = REG_SZ;

    lResult = RegOpenKey(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\"
            "Uninstall\\Steam App 252490"),
        &hKey);

    RegQueryValueExA(hKey, std::string(skCrypt("InstallLocation")).c_str(), NULL, &dwType,
        (LPBYTE)&value, &value_length);

    RegCloseKey(hKey);

    std::ifstream file;
    std::string line;
    int fileLine = 0;

    std::string client(skCrypt("\\cfg\\selectedx8bind.cfg"));

    file.open(std::string(value) + client); // path to rust

    while (std::getline(file, line))
    {
        fileLine++;
        if (line.find("selected.x8bind") != std::string::npos) { // makes sure we read the correct line of the .cfg file
            std::string fovString = line;
            size_t pos = fovString.find(" ");
            fovString = fovString.substr(pos + 2);
            std::stringstream fovConv(fovString);

            fovConv >> selectedkeybindx8;
        }
    }
}

void nobarrels()
{
    LONG   lResult;
    HKEY   hKey;
    LPBYTE folder = new BYTE[MAX_PATH];
    DWORD  dwSize = sizeof(folder);
    char   value[64];
    DWORD  value_length = 64;
    DWORD  dwType = REG_SZ;

    lResult = RegOpenKey(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\"
            "Uninstall\\Steam App 252490"),
        &hKey);

    RegQueryValueExA(hKey, std::string(skCrypt("InstallLocation")).c_str(), NULL, &dwType,
        (LPBYTE)&value, &value_length);

    RegCloseKey(hKey);

    std::ifstream file;
    std::string line;
    int fileLine = 0;

    std::string client(skCrypt("\\cfg\\selectednobarrelbind.cfg"));

    file.open(std::string(value) + client); // path to rust

    while (std::getline(file, line))
    {
        fileLine++;
        if (line.find("selected.nobarrelbind") != std::string::npos) { // makes sure we read the correct line of the .cfg file
            std::string fovString = line;
            size_t pos = fovString.find(" ");
            fovString = fovString.substr(pos + 2);
            std::stringstream fovConv(fovString);

            fovConv >> selectedkeybindnobarrel;
        }
    }
}

void nosights()
{
    LONG   lResult;
    HKEY   hKey;
    LPBYTE folder = new BYTE[MAX_PATH];
    DWORD  dwSize = sizeof(folder);
    char   value[64];
    DWORD  value_length = 64;
    DWORD  dwType = REG_SZ;

    lResult = RegOpenKey(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\"
            "Uninstall\\Steam App 252490"),
        &hKey);

    RegQueryValueExA(hKey, std::string(skCrypt("InstallLocation")).c_str(), NULL, &dwType,
        (LPBYTE)&value, &value_length);

    RegCloseKey(hKey);

    std::ifstream file;
    std::string line;
    int fileLine = 0;

    std::string client(skCrypt("\\cfg\\selectednosightbind.cfg"));

    file.open(std::string(value) + client); // path to rust

    while (std::getline(file, line))
    {
        fileLine++;
        if (line.find("selected.nosightbind") != std::string::npos) { // makes sure we read the correct line of the .cfg file
            std::string fovString = line;
            size_t pos = fovString.find(" ");
            fovString = fovString.substr(pos + 2);
            std::stringstream fovConv(fovString);

            fovConv >> selectedkeybindnosight;
        }
    }
}

void x16keybind()
{
    LONG   lResult;
    HKEY   hKey;
    LPBYTE folder = new BYTE[MAX_PATH];
    DWORD  dwSize = sizeof(folder);
    char   value[64];
    DWORD  value_length = 64;
    DWORD  dwType = REG_SZ;

    lResult = RegOpenKey(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\"
            "Uninstall\\Steam App 252490"),
        &hKey);

    RegQueryValueExA(hKey, std::string(skCrypt("InstallLocation")).c_str(), NULL, &dwType,
        (LPBYTE)&value, &value_length);

    RegCloseKey(hKey);

    std::ifstream file;
    std::string line;
    int fileLine = 0;

    std::string client(skCrypt("\\cfg\\selectedx16bind.cfg"));

    file.open(std::string(value) + client); // path to rust

    while (std::getline(file, line))
    {
        fileLine++;
        if (line.find("selected.x16bind") != std::string::npos) { // makes sure we read the correct line of the .cfg file
            std::string fovString = line;
            size_t pos = fovString.find(" ");
            fovString = fovString.substr(pos + 2);
            std::stringstream fovConv(fovString);

            fovConv >> selectedkeybindx16;
        }
    }
}

void m2keybind()
{
    LONG   lResult;
    HKEY   hKey;
    LPBYTE folder = new BYTE[MAX_PATH];
    DWORD  dwSize = sizeof(folder);
    char   value[64];
    DWORD  value_length = 64;
    DWORD  dwType = REG_SZ;

    lResult = RegOpenKey(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\"
            "Uninstall\\Steam App 252490"),
        &hKey);

    RegQueryValueExA(hKey, std::string(skCrypt("InstallLocation")).c_str(), NULL, &dwType,
        (LPBYTE)&value, &value_length);

    RegCloseKey(hKey);

    std::ifstream file;
    std::string line;
    int fileLine = 0;

    std::string client(skCrypt("\\cfg\\selectedm2bind.cfg"));

    file.open(std::string(value) + client); // path to rust

    while (std::getline(file, line))
    {
        fileLine++;
        if (line.find("selected.m2bind") != std::string::npos) { // makes sure we read the correct line of the .cfg file
            std::string fovString = line;
            size_t pos = fovString.find(" ");
            fovString = fovString.substr(pos + 2);
            std::stringstream fovConv(fovString);

            fovConv >> selectedkeybindm2;
        }
    }
}

void lrkeybind()
{
    LONG   lResult;
    HKEY   hKey;
    LPBYTE folder = new BYTE[MAX_PATH];
    DWORD  dwSize = sizeof(folder);
    char   value[64];
    DWORD  value_length = 64;
    DWORD  dwType = REG_SZ;

    lResult = RegOpenKey(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\"
            "Uninstall\\Steam App 252490"),
        &hKey);

    RegQueryValueExA(hKey, std::string(skCrypt("InstallLocation")).c_str(), NULL, &dwType,
        (LPBYTE)&value, &value_length);

    RegCloseKey(hKey);

    std::ifstream file;
    std::string line;
    int fileLine = 0;

    std::string client(skCrypt("\\cfg\\selectedlrbind.cfg"));

    file.open(std::string(value) + client); // path to rust

    while (std::getline(file, line))
    {
        fileLine++;
        if (line.find("selected.lrbind") != std::string::npos) { // makes sure we read the correct line of the .cfg file
            std::string fovString = line;
            size_t pos = fovString.find(" ");
            fovString = fovString.substr(pos + 2);
            std::stringstream fovConv(fovString);

            fovConv >> selectedkeybindlr;
        }
    }
}

void sarkeybind()
{
    LONG   lResult;
    HKEY   hKey;
    LPBYTE folder = new BYTE[MAX_PATH];
    DWORD  dwSize = sizeof(folder);
    char   value[64];
    DWORD  value_length = 64;
    DWORD  dwType = REG_SZ;

    lResult = RegOpenKey(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\"
            "Uninstall\\Steam App 252490"),
        &hKey);

    RegQueryValueExA(hKey, std::string(skCrypt("InstallLocation")).c_str(), NULL, &dwType,
        (LPBYTE)&value, &value_length);

    RegCloseKey(hKey);

    std::ifstream file;
    std::string line;
    int fileLine = 0;

    std::string client(skCrypt("\\cfg\\selectedsarbind.cfg"));

    file.open(std::string(value) + client); // path to rust

    while (std::getline(file, line))
    {
        fileLine++;
        if (line.find("selected.sarbind") != std::string::npos) { // makes sure we read the correct line of the .cfg file
            std::string fovString = line;
            size_t pos = fovString.find(" ");
            fovString = fovString.substr(pos + 2);
            std::stringstream fovConv(fovString);

            fovConv >> selectedkeybindsar;
        }
    }
}

void mp5keybind()
{
    LONG   lResult;
    HKEY   hKey;
    LPBYTE folder = new BYTE[MAX_PATH];
    DWORD  dwSize = sizeof(folder);
    char   value[64];
    DWORD  value_length = 64;
    DWORD  dwType = REG_SZ;

    lResult = RegOpenKey(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\"
            "Uninstall\\Steam App 252490"),
        &hKey);

    RegQueryValueExA(hKey, std::string(skCrypt("InstallLocation")).c_str(), NULL, &dwType,
        (LPBYTE)&value, &value_length);

    RegCloseKey(hKey);

    std::ifstream file;
    std::string line;
    int fileLine = 0;

    std::string client(skCrypt("\\cfg\\selectedmp5bind.cfg"));

    file.open(std::string(value) + client); // path to rust

    while (std::getline(file, line))
    {
        fileLine++;
        if (line.find("selected.mp5bind") != std::string::npos) { // makes sure we read the correct line of the .cfg file
            std::string fovString = line;
            size_t pos = fovString.find(" ");
            fovString = fovString.substr(pos + 2);
            std::stringstream fovConv(fovString);

            fovConv >> selectedkeybindmp5;
        }
    }
}

void smgkeybind()
{
    LONG   lResult;
    HKEY   hKey;
    LPBYTE folder = new BYTE[MAX_PATH];
    DWORD  dwSize = sizeof(folder);
    char   value[64];
    DWORD  value_length = 64;
    DWORD  dwType = REG_SZ;

    lResult = RegOpenKey(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\"
            "Uninstall\\Steam App 252490"),
        &hKey);

    RegQueryValueExA(hKey, std::string(skCrypt("InstallLocation")).c_str(), NULL, &dwType,
        (LPBYTE)&value, &value_length);

    RegCloseKey(hKey);

    std::ifstream file;
    std::string line;
    int fileLine = 0;

    std::string client(skCrypt("\\cfg\\selectedsmgbind.cfg"));

    file.open(std::string(value) + client); // path to rust

    while (std::getline(file, line))
    {
        fileLine++;
        if (line.find("selected.smgbind") != std::string::npos) { // makes sure we read the correct line of the .cfg file
            std::string fovString = line;
            size_t pos = fovString.find(" ");
            fovString = fovString.substr(pos + 2);
            std::stringstream fovConv(fovString);

            fovConv >> selectedkeybindsmg;
        }
    }
}

void tommykeybind()
{
    LONG   lResult;
    HKEY   hKey;
    LPBYTE folder = new BYTE[MAX_PATH];
    DWORD  dwSize = sizeof(folder);
    char   value[64];
    DWORD  value_length = 64;
    DWORD  dwType = REG_SZ;

    lResult = RegOpenKey(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\"
            "Uninstall\\Steam App 252490"),
        &hKey);

    RegQueryValueExA(hKey, std::string(skCrypt("InstallLocation")).c_str(), NULL, &dwType,
        (LPBYTE)&value, &value_length);

    RegCloseKey(hKey);

    std::ifstream file;
    std::string line;
    int fileLine = 0;

    std::string client(skCrypt("\\cfg\\selectedtommybind.cfg"));

    file.open(std::string(value) + client); // path to rust

    while (std::getline(file, line))
    {
        fileLine++;
        if (line.find("selected.tommybind") != std::string::npos) { // makes sure we read the correct line of the .cfg file
            std::string fovString = line;
            size_t pos = fovString.find(" ");
            fovString = fovString.substr(pos + 2);
            std::stringstream fovConv(fovString);

            fovConv >> selectedkeybindtommy;
        }
    }
}

void getenabled()
{
    LONG   lResult;
    HKEY   hKey;
    LPBYTE folder = new BYTE[MAX_PATH];
    DWORD  dwSize = sizeof(folder);
    char   value[64];
    DWORD  value_length = 64;
    DWORD  dwType = REG_SZ;

    lResult = RegOpenKey(HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\"
            "Uninstall\\Steam App 252490"),
        &hKey);

    RegQueryValueExA(hKey, std::string(skCrypt("InstallLocation")).c_str(), NULL, &dwType,
        (LPBYTE)&value, &value_length);

    RegCloseKey(hKey);

    std::ifstream file;
    std::string line;
    int fileLine = 0;

    std::string client(skCrypt("\\cfg\\selectedenabled.cfg"));

    file.open(std::string(value) + client); // path to rust

    while (std::getline(file, line))
    {
        fileLine++;
        if (line.find("selected.enabled") != std::string::npos) { // makes sure we read the correct line of the .cfg file
            std::string fovString = line;
            size_t pos = fovString.find(" ");
            fovString = fovString.substr(pos + 2);
            std::stringstream fovConv(fovString);

            fovConv >> selectedEnabled;
        }
    }
}

ImFont* Arial;
int APIENTRY WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    barrelskeybind();    holokeybind();   nosights();    nobarrels();
    simplekeybind();
    x16keybind();
    x8keybind();
    mp5keybind();
    smgkeybind();
    tommykeybind();
    sarkeybind();
    m2keybind();
    akkeybind();
    lrkeybind();
    getsettings();
    gethide();
    getenabled();
    legitmodebind();
    Beep(450, 300);
    std::string name = XorStr("Slotted");
    std::string ownerid = XorStr("V2GlEJ3YWG");
    std::string secret = XorStr("9600222864fb9ac01d836061c0bfb87cfedf5255c7baeee32e7ca95b79ec7107");
    std::string version = XorStr("2.4");

    api KeyAuthApp(name, ownerid, secret, version);

    //KeyAuthApp.init();

    // Create application window
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, LOADER_BRAND, NULL };
    RegisterClassEx(&wc);
    main_hwnd = CreateWindow(wc.lpszClassName, LOADER_BRAND, WS_POPUP, 0, 0, 5, 5, NULL, NULL, wc.hInstance, NULL);

    // Initialize Direct3D
    if (!CreateDeviceD3D(main_hwnd)) {
        CleanupDeviceD3D();
        UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    ShowWindow(main_hwnd, SW_HIDE);
    UpdateWindow(main_hwnd);

    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
    Arial = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Arial.ttf", 16);

    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    ImGui_ImplWin32_Init(main_hwnd);
    ImGui_ImplDX9_Init(g_pd3dDevice);

    DWORD window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse;
    RECT screen_rect;
    GetWindowRect(GetDesktopWindow(), &screen_rect);
    auto x = float(screen_rect.right - WINDOW_WIDTH) / 2.f;
    auto y = float(screen_rect.bottom - WINDOW_HEIGHT) / 2.f;

    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            continue;
        }
        static bool isSecondMenuOpen = false;
        static bool isFirstMenuOpen = true;

        switch (selectedkeybindnobarrel)
        {
        case 0:
            break;
        case 1:
            if (GetAsyncKeyState(VK_INSERT) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        case 2:
            if (GetAsyncKeyState(VK_HOME) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        case 3:
            if (GetAsyncKeyState(VK_DELETE) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        case 4:
            if (GetAsyncKeyState(VK_END) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        case 5:
            if (GetAsyncKeyState(VK_PRIOR) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        case 6:
            if (GetAsyncKeyState(VK_NEXT) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        case 7:
            if (GetAsyncKeyState(VK_F1) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        case 8:
            if (GetAsyncKeyState(VK_F2) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        case 9:
            if (GetAsyncKeyState(VK_F3) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        case 10:
            if (GetAsyncKeyState(VK_F4) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        case 11:
            if (GetAsyncKeyState(VK_F5) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        case 12:
            if (GetAsyncKeyState(VK_F6) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        case 13:
            if (GetAsyncKeyState(VK_F7) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        case 14:
            if (GetAsyncKeyState(VK_F8) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        case 15:
            if (GetAsyncKeyState(VK_F9) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        case 16:
            if (GetAsyncKeyState(VK_F10) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        case 17:
            if (GetAsyncKeyState(VK_F11) & 1)
            {
                selectedBarrel = 0;;
            }
            break;
        case 18:
            if (GetAsyncKeyState(VK_F12) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        case 19:
            if (GetAsyncKeyState(VK_UP) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        case 20:
            if (GetAsyncKeyState(VK_DOWN) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        case 21:
            if (GetAsyncKeyState(VK_RIGHT) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        case 22:
            if (GetAsyncKeyState(VK_LEFT) & 1)
            {
                selectedBarrel = 0;
            }
            break;
        }

        switch (selectedkeybindnosight)
        {
        case 0:
            break;
        case 1:
            if (GetAsyncKeyState(VK_INSERT) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 2:
            if (GetAsyncKeyState(VK_HOME) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 3:
            if (GetAsyncKeyState(VK_DELETE) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 4:
            if (GetAsyncKeyState(VK_END) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 5:
            if (GetAsyncKeyState(VK_PRIOR) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 6:
            if (GetAsyncKeyState(VK_NEXT) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 7:
            if (GetAsyncKeyState(VK_F1) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 8:
            if (GetAsyncKeyState(VK_F2) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 9:
            if (GetAsyncKeyState(VK_F3) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 10:
            if (GetAsyncKeyState(VK_F4) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 11:
            if (GetAsyncKeyState(VK_F5) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 12:
            if (GetAsyncKeyState(VK_F6) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 13:
            if (GetAsyncKeyState(VK_F7) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 14:
            if (GetAsyncKeyState(VK_F8) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 15:
            if (GetAsyncKeyState(VK_F9) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 16:
            if (GetAsyncKeyState(VK_F10) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 17:
            if (GetAsyncKeyState(VK_F11) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 18:
            if (GetAsyncKeyState(VK_F12) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 19:
            if (GetAsyncKeyState(VK_UP) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 20:
            if (GetAsyncKeyState(VK_DOWN) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 21:
            if (GetAsyncKeyState(VK_RIGHT) & 1)
            {
                selectedScope = 0;
            }
            break;
        case 22:
            if (GetAsyncKeyState(VK_LEFT) & 1)
            {
                selectedScope = 0;
            }
            break;
        }

        switch (selectedHide)
        {
        case 0:
            break;
        case 1:
            if (GetAsyncKeyState(VK_INSERT) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 2:
            if (GetAsyncKeyState(VK_HOME) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 3:
            if (GetAsyncKeyState(VK_DELETE) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 4:
            if (GetAsyncKeyState(VK_END) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 5:
            if (GetAsyncKeyState(VK_PRIOR) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 6:
            if (GetAsyncKeyState(VK_NEXT) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 7:
            if (GetAsyncKeyState(VK_F1) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 8:
            if (GetAsyncKeyState(VK_F2) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 9:
            if (GetAsyncKeyState(VK_F3) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 10:
            if (GetAsyncKeyState(VK_F4) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 11:
            if (GetAsyncKeyState(VK_F5) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 12:
            if (GetAsyncKeyState(VK_F6) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 13:
            if (GetAsyncKeyState(VK_F7) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 14:
            if (GetAsyncKeyState(VK_F8) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 15:
            if (GetAsyncKeyState(VK_F9) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 16:
            if (GetAsyncKeyState(VK_F10) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 17:
            if (GetAsyncKeyState(VK_F11) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 18:
            if (GetAsyncKeyState(VK_F12) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 19:
            if (GetAsyncKeyState(VK_UP) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 20:
            if (GetAsyncKeyState(VK_DOWN) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 21:
            if (GetAsyncKeyState(VK_RIGHT) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        case 22:
            if (GetAsyncKeyState(VK_LEFT) & 1)
            {
                isSecondMenuOpen = !isSecondMenuOpen;
            }
            break;
        }

        switch (selectedlegitmode)
        {
        case 0:
            break;
        case 1:
            if (GetAsyncKeyState(VK_INSERT) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 2:
            if (GetAsyncKeyState(VK_HOME) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 3:
            if (GetAsyncKeyState(VK_DELETE) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 4:
            if (GetAsyncKeyState(VK_END) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 5:
            if (GetAsyncKeyState(VK_PRIOR) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 6:
            if (GetAsyncKeyState(VK_NEXT) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 7:
            if (GetAsyncKeyState(VK_F1) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 8:
            if (GetAsyncKeyState(VK_F2) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 9:
            if (GetAsyncKeyState(VK_F3) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 10:
            if (GetAsyncKeyState(VK_F4) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 11:
            if (GetAsyncKeyState(VK_F5) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 12:
            if (GetAsyncKeyState(VK_F6) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 13:
            if (GetAsyncKeyState(VK_F7) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 14:
            if (GetAsyncKeyState(VK_F8) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 15:
            if (GetAsyncKeyState(VK_F9) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 16:
            if (GetAsyncKeyState(VK_F10) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 17:
            if (GetAsyncKeyState(VK_F11) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 18:
            if (GetAsyncKeyState(VK_F12) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 19:
            if (GetAsyncKeyState(VK_UP) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 20:
            if (GetAsyncKeyState(VK_DOWN) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 21:
            if (GetAsyncKeyState(VK_RIGHT) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        case 22:
            if (GetAsyncKeyState(VK_LEFT) & 1)
            {
                legitmode = !legitmode;
            }
            break;
        }

        switch (selectedkeybindx8)
        {
        case 0:
            break;
        case 1:
            if (GetAsyncKeyState(VK_INSERT) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 2:
            if (GetAsyncKeyState(VK_HOME) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 3:
            if (GetAsyncKeyState(VK_DELETE) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 4:
            if (GetAsyncKeyState(VK_END) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 5:
            if (GetAsyncKeyState(VK_PRIOR) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 6:
            if (GetAsyncKeyState(VK_NEXT) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 7:
            if (GetAsyncKeyState(VK_F1) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 8:
            if (GetAsyncKeyState(VK_F2) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 9:
            if (GetAsyncKeyState(VK_F3) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 10:
            if (GetAsyncKeyState(VK_F4) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 11:
            if (GetAsyncKeyState(VK_F5) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 12:
            if (GetAsyncKeyState(VK_F6) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 13:
            if (GetAsyncKeyState(VK_F7) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 14:
            if (GetAsyncKeyState(VK_F8) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 15:
            if (GetAsyncKeyState(VK_F9) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 16:
            if (GetAsyncKeyState(VK_F10) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 17:
            if (GetAsyncKeyState(VK_F11) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 18:
            if (GetAsyncKeyState(VK_F12) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 19:
            if (GetAsyncKeyState(VK_UP) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 20:
            if (GetAsyncKeyState(VK_DOWN) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 21:
            if (GetAsyncKeyState(VK_RIGHT) & 1)
            {
                selectedScope = 3;
            }
            break;
        case 22:
            if (GetAsyncKeyState(VK_LEFT) & 1)
            {
                selectedScope = 3;
            }
            break;
        }

        switch (selectedkeybindsimplesight)
        {
        case 0:
            break;
        case 1:
            if (GetAsyncKeyState(VK_INSERT) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 2:
            if (GetAsyncKeyState(VK_HOME) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 3:
            if (GetAsyncKeyState(VK_DELETE) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 4:
            if (GetAsyncKeyState(VK_END) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 5:
            if (GetAsyncKeyState(VK_PRIOR) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 6:
            if (GetAsyncKeyState(VK_NEXT) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 7:
            if (GetAsyncKeyState(VK_F1) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 8:
            if (GetAsyncKeyState(VK_F2) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 9:
            if (GetAsyncKeyState(VK_F3) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 10:
            if (GetAsyncKeyState(VK_F4) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 11:
            if (GetAsyncKeyState(VK_F5) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 12:
            if (GetAsyncKeyState(VK_F6) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 13:
            if (GetAsyncKeyState(VK_F7) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 14:
            if (GetAsyncKeyState(VK_F8) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 15:
            if (GetAsyncKeyState(VK_F9) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 16:
            if (GetAsyncKeyState(VK_F10) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 17:
            if (GetAsyncKeyState(VK_F11) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 18:
            if (GetAsyncKeyState(VK_F12) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 19:
            if (GetAsyncKeyState(VK_UP) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 20:
            if (GetAsyncKeyState(VK_DOWN) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 21:
            if (GetAsyncKeyState(VK_RIGHT) & 1)
            {
                selectedScope = 2;
            }
            break;
        case 22:
            if (GetAsyncKeyState(VK_LEFT) & 1)
            {
                selectedScope = 2;
            }
            break;
        }

        
        switch (selectedkeybindx16)
        {
        case 0:
            break;
        case 1:
            if (GetAsyncKeyState(VK_INSERT) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 2:
            if (GetAsyncKeyState(VK_HOME) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 3:
            if (GetAsyncKeyState(VK_DELETE) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 4:
            if (GetAsyncKeyState(VK_END) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 5:
            if (GetAsyncKeyState(VK_PRIOR) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 6:
            if (GetAsyncKeyState(VK_NEXT) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 7:
            if (GetAsyncKeyState(VK_F1) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 8:
            if (GetAsyncKeyState(VK_F2) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 9:
            if (GetAsyncKeyState(VK_F3) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 10:
            if (GetAsyncKeyState(VK_F4) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 11:
            if (GetAsyncKeyState(VK_F5) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 12:
            if (GetAsyncKeyState(VK_F6) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 13:
            if (GetAsyncKeyState(VK_F7) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 14:
            if (GetAsyncKeyState(VK_F8) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 15:
            if (GetAsyncKeyState(VK_F9) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 16:
            if (GetAsyncKeyState(VK_F10) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 17:
            if (GetAsyncKeyState(VK_F11) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 18:
            if (GetAsyncKeyState(VK_F12) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 19:
            if (GetAsyncKeyState(VK_UP) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 20:
            if (GetAsyncKeyState(VK_DOWN) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 21:
            if (GetAsyncKeyState(VK_RIGHT) & 1)
            {
                selectedScope = 4;
            }
            break;
        case 22:
            if (GetAsyncKeyState(VK_LEFT) & 1)
            {
                selectedScope = 4;
            }
            break;
           }

           switch (selectedkeybindsuppresor)
           {
           case 0:
               break;
           case 1:
               if (GetAsyncKeyState(VK_INSERT) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 2:
               if (GetAsyncKeyState(VK_HOME) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 3:
               if (GetAsyncKeyState(VK_DELETE) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 4:
               if (GetAsyncKeyState(VK_END) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 5:
               if (GetAsyncKeyState(VK_PRIOR) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 6:
               if (GetAsyncKeyState(VK_NEXT) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 7:
               if (GetAsyncKeyState(VK_F1) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 8:
               if (GetAsyncKeyState(VK_F2) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 9:
               if (GetAsyncKeyState(VK_F3) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 10:
               if (GetAsyncKeyState(VK_F4) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 11:
               if (GetAsyncKeyState(VK_F5) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 12:
               if (GetAsyncKeyState(VK_F6) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 13:
               if (GetAsyncKeyState(VK_F7) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 14:
               if (GetAsyncKeyState(VK_F8) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 15:
               if (GetAsyncKeyState(VK_F9) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 16:
               if (GetAsyncKeyState(VK_F10) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 17:
               if (GetAsyncKeyState(VK_F11) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 18:
               if (GetAsyncKeyState(VK_F12) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 19:
               if (GetAsyncKeyState(VK_UP) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 20:
               if (GetAsyncKeyState(VK_DOWN) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 21:
               if (GetAsyncKeyState(VK_RIGHT) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           case 22:
               if (GetAsyncKeyState(VK_LEFT) & 1)
               {
                   selectedBarrel = 1;
               }
               break;
           }

                switch (selectedkeybindholosight)
                {
                case 0:
                    break;
                case 1:
                    if (GetAsyncKeyState(VK_INSERT) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 2:
                    if (GetAsyncKeyState(VK_HOME) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 3:
                    if (GetAsyncKeyState(VK_DELETE) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 4:
                    if (GetAsyncKeyState(VK_END) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 5:
                    if (GetAsyncKeyState(VK_PRIOR) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 6:
                    if (GetAsyncKeyState(VK_NEXT) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 7:
                    if (GetAsyncKeyState(VK_F1) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 8:
                    if (GetAsyncKeyState(VK_F2) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 9:
                    if (GetAsyncKeyState(VK_F3) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 10:
                    if (GetAsyncKeyState(VK_F4) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 11:
                    if (GetAsyncKeyState(VK_F5) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 12:
                    if (GetAsyncKeyState(VK_F6) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 13:
                    if (GetAsyncKeyState(VK_F7) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 14:
                    if (GetAsyncKeyState(VK_F8) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 15:
                    if (GetAsyncKeyState(VK_F9) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 16:
                    if (GetAsyncKeyState(VK_F10) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 17:
                    if (GetAsyncKeyState(VK_F11) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 18:
                    if (GetAsyncKeyState(VK_F12) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 19:
                    if (GetAsyncKeyState(VK_UP) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 20:
                    if (GetAsyncKeyState(VK_DOWN) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 21:
                    if (GetAsyncKeyState(VK_RIGHT) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                case 22:
                    if (GetAsyncKeyState(VK_LEFT) & 1)
                    {
                        selectedScope = 1;
                    }
                    break;
                }

                switch (selectedkeybindmp5)
                {
                case 0:
                    break;
                case 1:
                    if (GetAsyncKeyState(VK_INSERT) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 2:
                    if (GetAsyncKeyState(VK_HOME) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 3:
                    if (GetAsyncKeyState(VK_DELETE) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 4:
                    if (GetAsyncKeyState(VK_END) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 5:
                    if (GetAsyncKeyState(VK_PRIOR) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 6:
                    if (GetAsyncKeyState(VK_NEXT) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 7:
                    if (GetAsyncKeyState(VK_F1) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 8:
                    if (GetAsyncKeyState(VK_F2) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 9:
                    if (GetAsyncKeyState(VK_F3) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 10:
                    if (GetAsyncKeyState(VK_F4) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 11:
                    if (GetAsyncKeyState(VK_F5) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 12:
                    if (GetAsyncKeyState(VK_F6) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 13:
                    if (GetAsyncKeyState(VK_F7) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 14:
                    if (GetAsyncKeyState(VK_F8) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 15:
                    if (GetAsyncKeyState(VK_F9) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 16:
                    if (GetAsyncKeyState(VK_F10) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 17:
                    if (GetAsyncKeyState(VK_F11) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 18:
                    if (GetAsyncKeyState(VK_F12) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 19:
                    if (GetAsyncKeyState(VK_UP) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 20:
                    if (GetAsyncKeyState(VK_DOWN) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 21:
                    if (GetAsyncKeyState(VK_RIGHT) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                case 22:
                    if (GetAsyncKeyState(VK_LEFT) & 1)
                    {
                        selectedWeapon = 3;
                    }
                    break;
                }

                switch (selectedkeybindlr)
                {
                case 0:
                    break;
                case 1:
                    if (GetAsyncKeyState(VK_INSERT) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 2:
                    if (GetAsyncKeyState(VK_HOME) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 3:
                    if (GetAsyncKeyState(VK_DELETE) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 4:
                    if (GetAsyncKeyState(VK_END) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 5:
                    if (GetAsyncKeyState(VK_PRIOR) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 6:
                    if (GetAsyncKeyState(VK_NEXT) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 7:
                    if (GetAsyncKeyState(VK_F1) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 8:
                    if (GetAsyncKeyState(VK_F2) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 9:
                    if (GetAsyncKeyState(VK_F3) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 10:
                    if (GetAsyncKeyState(VK_F4) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 11:
                    if (GetAsyncKeyState(VK_F5) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 12:
                    if (GetAsyncKeyState(VK_F6) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 13:
                    if (GetAsyncKeyState(VK_F7) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 14:
                    if (GetAsyncKeyState(VK_F8) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 15:
                    if (GetAsyncKeyState(VK_F9) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 16:
                    if (GetAsyncKeyState(VK_F10) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 17:
                    if (GetAsyncKeyState(VK_F11) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 18:
                    if (GetAsyncKeyState(VK_F12) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 19:
                    if (GetAsyncKeyState(VK_UP) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 20:
                    if (GetAsyncKeyState(VK_DOWN) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 21:
                    if (GetAsyncKeyState(VK_RIGHT) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                case 22:
                    if (GetAsyncKeyState(VK_LEFT) & 1)
                    {
                        selectedWeapon = 2;
                    }
                    break;
                }



                switch (selectedkeybindsar)
                {
                case 0:
                    break;
                case 1:
                    if (GetAsyncKeyState(VK_INSERT) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 2:
                    if (GetAsyncKeyState(VK_HOME) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 3:
                    if (GetAsyncKeyState(VK_DELETE) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 4:
                    if (GetAsyncKeyState(VK_END) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 5:
                    if (GetAsyncKeyState(VK_PRIOR) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 6:
                    if (GetAsyncKeyState(VK_NEXT) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 7:
                    if (GetAsyncKeyState(VK_F1) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 8:
                    if (GetAsyncKeyState(VK_F2) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 9:
                    if (GetAsyncKeyState(VK_F3) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 10:
                    if (GetAsyncKeyState(VK_F4) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 11:
                    if (GetAsyncKeyState(VK_F5) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 12:
                    if (GetAsyncKeyState(VK_F6) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 13:
                    if (GetAsyncKeyState(VK_F7) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 14:
                    if (GetAsyncKeyState(VK_F8) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 15:
                    if (GetAsyncKeyState(VK_F9) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 16:
                    if (GetAsyncKeyState(VK_F10) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 17:
                    if (GetAsyncKeyState(VK_F11) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 18:
                    if (GetAsyncKeyState(VK_F12) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 19:
                    if (GetAsyncKeyState(VK_UP) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 20:
                    if (GetAsyncKeyState(VK_DOWN) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 21:
                    if (GetAsyncKeyState(VK_RIGHT) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                case 22:
                    if (GetAsyncKeyState(VK_LEFT) & 1)
                    {
                        selectedWeapon = 6;
                    }
                    break;
                }

                switch (selectedkeybindm2)
                {
                case 0:
                    break;
                case 1:
                    if (GetAsyncKeyState(VK_INSERT) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 2:
                    if (GetAsyncKeyState(VK_HOME) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 3:
                    if (GetAsyncKeyState(VK_DELETE) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 4:
                    if (GetAsyncKeyState(VK_END) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 5:
                    if (GetAsyncKeyState(VK_PRIOR) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 6:
                    if (GetAsyncKeyState(VK_NEXT) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 7:
                    if (GetAsyncKeyState(VK_F1) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 8:
                    if (GetAsyncKeyState(VK_F2) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 9:
                    if (GetAsyncKeyState(VK_F3) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 10:
                    if (GetAsyncKeyState(VK_F4) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 11:
                    if (GetAsyncKeyState(VK_F5) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 12:
                    if (GetAsyncKeyState(VK_F6) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 13:
                    if (GetAsyncKeyState(VK_F7) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 14:
                    if (GetAsyncKeyState(VK_F8) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 15:
                    if (GetAsyncKeyState(VK_F9) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 16:
                    if (GetAsyncKeyState(VK_F10) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 17:
                    if (GetAsyncKeyState(VK_F11) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 18:
                    if (GetAsyncKeyState(VK_F12) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 19:
                    if (GetAsyncKeyState(VK_UP) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 20:
                    if (GetAsyncKeyState(VK_DOWN) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 21:
                    if (GetAsyncKeyState(VK_RIGHT) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                case 22:
                    if (GetAsyncKeyState(VK_LEFT) & 1)
                    {
                        selectedWeapon = 7;
                    }
                    break;
                }

                switch (selectedkeybindak)
                {
                case 0:
                    break;
                case 1:
                    if (GetAsyncKeyState(VK_INSERT) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 2:
                    if (GetAsyncKeyState(VK_HOME) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 3:
                    if (GetAsyncKeyState(VK_DELETE) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 4:
                    if (GetAsyncKeyState(VK_END) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 5:
                    if (GetAsyncKeyState(VK_PRIOR) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 6:
                    if (GetAsyncKeyState(VK_NEXT) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 7:
                    if (GetAsyncKeyState(VK_F1) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 8:
                    if (GetAsyncKeyState(VK_F2) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 9:
                    if (GetAsyncKeyState(VK_F3) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 10:
                    if (GetAsyncKeyState(VK_F4) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 11:
                    if (GetAsyncKeyState(VK_F5) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 12:
                    if (GetAsyncKeyState(VK_F6) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 13:
                    if (GetAsyncKeyState(VK_F7) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 14:
                    if (GetAsyncKeyState(VK_F8) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 15:
                    if (GetAsyncKeyState(VK_F9) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 16:
                    if (GetAsyncKeyState(VK_F10) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 17:
                    if (GetAsyncKeyState(VK_F11) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 18:
                    if (GetAsyncKeyState(VK_F12) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 19:
                    if (GetAsyncKeyState(VK_UP) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 20:
                    if (GetAsyncKeyState(VK_DOWN) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 21:
                    if (GetAsyncKeyState(VK_RIGHT) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                case 22:
                    if (GetAsyncKeyState(VK_LEFT) & 1)
                    {
                        selectedWeapon = 1;
                    }
                    break;
                }

                switch (selectedkeybindtommy)
                {
                case 0:
                    break;
                case 1:
                    if (GetAsyncKeyState(VK_INSERT) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 2:
                    if (GetAsyncKeyState(VK_HOME) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 3:
                    if (GetAsyncKeyState(VK_DELETE) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 4:
                    if (GetAsyncKeyState(VK_END) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 5:
                    if (GetAsyncKeyState(VK_PRIOR) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 6:
                    if (GetAsyncKeyState(VK_NEXT) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 7:
                    if (GetAsyncKeyState(VK_F1) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 8:
                    if (GetAsyncKeyState(VK_F2) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 9:
                    if (GetAsyncKeyState(VK_F3) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 10:
                    if (GetAsyncKeyState(VK_F4) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 11:
                    if (GetAsyncKeyState(VK_F5) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 12:
                    if (GetAsyncKeyState(VK_F6) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 13:
                    if (GetAsyncKeyState(VK_F7) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 14:
                    if (GetAsyncKeyState(VK_F8) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 15:
                    if (GetAsyncKeyState(VK_F9) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 16:
                    if (GetAsyncKeyState(VK_F10) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 17:
                    if (GetAsyncKeyState(VK_F11) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 18:
                    if (GetAsyncKeyState(VK_F12) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 19:
                    if (GetAsyncKeyState(VK_UP) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 20:
                    if (GetAsyncKeyState(VK_DOWN) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 21:
                    if (GetAsyncKeyState(VK_RIGHT) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                case 22:
                    if (GetAsyncKeyState(VK_LEFT) & 1)
                    {
                        selectedWeapon = 5;
                    }
                    break;
                }

                switch (selectedkeybindsmg)
                {
                case 0:
                    break;
                case 1:
                    if (GetAsyncKeyState(VK_INSERT) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 2:
                    if (GetAsyncKeyState(VK_HOME) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 3:
                    if (GetAsyncKeyState(VK_DELETE) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 4:
                    if (GetAsyncKeyState(VK_END) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 5:
                    if (GetAsyncKeyState(VK_PRIOR) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 6:
                    if (GetAsyncKeyState(VK_NEXT) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 7:
                    if (GetAsyncKeyState(VK_F1) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 8:
                    if (GetAsyncKeyState(VK_F2) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 9:
                    if (GetAsyncKeyState(VK_F3) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 10:
                    if (GetAsyncKeyState(VK_F4) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 11:
                    if (GetAsyncKeyState(VK_F5) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 12:
                    if (GetAsyncKeyState(VK_F6) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 13:
                    if (GetAsyncKeyState(VK_F7) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 14:
                    if (GetAsyncKeyState(VK_F8) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 15:
                    if (GetAsyncKeyState(VK_F9) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 16:
                    if (GetAsyncKeyState(VK_F10) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 17:
                    if (GetAsyncKeyState(VK_F11) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 18:
                    if (GetAsyncKeyState(VK_F12) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 19:
                    if (GetAsyncKeyState(VK_UP) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 20:
                    if (GetAsyncKeyState(VK_DOWN) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 21:
                    if (GetAsyncKeyState(VK_RIGHT) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                case 22:
                    if (GetAsyncKeyState(VK_LEFT) & 1)
                    {
                        selectedWeapon = 4;
                    }
                    break;
                }

                switch (selectedEnabled)
                {
                case 0:
                    break;
                case 1:
                    if (GetAsyncKeyState(VK_INSERT) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 2:
                    if (GetAsyncKeyState(VK_HOME) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 3:
                    if (GetAsyncKeyState(VK_DELETE) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 4:
                    if (GetAsyncKeyState(VK_END) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 5:
                    if (GetAsyncKeyState(VK_PRIOR) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 6:
                    if (GetAsyncKeyState(VK_NEXT) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 7:
                    if (GetAsyncKeyState(VK_F1) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 8:
                    if (GetAsyncKeyState(VK_F2) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 9:
                    if (GetAsyncKeyState(VK_F3) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 10:
                    if (GetAsyncKeyState(VK_F4) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 11:
                    if (GetAsyncKeyState(VK_F5) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 12:
                    if (GetAsyncKeyState(VK_F6) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 13:
                    if (GetAsyncKeyState(VK_F7) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 14:
                    if (GetAsyncKeyState(VK_F8) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 15:
                    if (GetAsyncKeyState(VK_F9) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 16:
                    if (GetAsyncKeyState(VK_F10) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 17:
                    if (GetAsyncKeyState(VK_F11) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 18:
                    if (GetAsyncKeyState(VK_F12) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 19:
                    if (GetAsyncKeyState(VK_UP) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 20:
                    if (GetAsyncKeyState(VK_DOWN) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 21:
                    if (GetAsyncKeyState(VK_RIGHT) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                case 22:
                    if (GetAsyncKeyState(VK_LEFT) & 1)
                    {
                        enabled = !enabled;
                    }
                    break;
                }
        
        
        int count = 0;

        if (enabled)
        {
            while (GetAsyncKeyState(VK_RBUTTON))
            {
                if (GetAsyncKeyState(VK_LBUTTON) && GetAsyncKeyState(VK_RBUTTON))
                {
                    switch (selectedWeapon)
                    {
                    case 1:
                        if (legitmode == true)
                        {
                            if (count < LegitWeapons::aklegit::pattern.size())
                            {
                                Smoothing(LegitWeapons::aklegit::delay, LegitWeapons::aklegit::controltime.at(count), Randomize(tofovandsens(playersens, playerfov, LegitWeapons::aklegit::pattern.at(count).x), randomizer), Randomize(tofovandsens(playersens, playerfov, LegitWeapons::aklegit::pattern.at(count).y), randomizer));
                                count++;
                            }
                        }
                        else
                        {
                            if (count < Weapons::ak::pattern.size())
                            {
                                Smoothing(Weapons::ak::delay, Weapons::ak::controltime.at(count), Randomize(tofovandsens(playersens, playerfov, Weapons::ak::pattern.at(count).x), randomizer), Randomize(tofovandsens(playersens, playerfov, Weapons::ak::pattern.at(count).y), randomizer));
                                count++;
                            }
                        }
                        break;
                    case 5:
                        if (legitmode == true)
                        {

                        }
                        else
                        {
                            if (count < Weapons::thompson::pattern.size())
                            {
                                Smoothing(Weapons::thompson::delay, Weapons::thompson::delay, Randomize(tofovandsens(playersens, playerfov, Weapons::thompson::pattern.at(count).x), randomizer), Randomize(tofovandsens(playersens, playerfov, Weapons::thompson::pattern.at(count).y), randomizer));
                                count++;
                            }
                        }
                        break;
                    case 4:
                        if (legitmode == true)
                        {

                        }
                        else
                        {
                            if (count < Weapons::smg::pattern.size())
                            {
                                Smoothing(Weapons::smg::delay, Weapons::smg::delay, Randomize(tofovandsens(playersens, playerfov, Weapons::smg::pattern.at(count).x), randomizer), Randomize(tofovandsens(playersens, playerfov, Weapons::smg::pattern.at(count).y), randomizer));
                                count++;
                            }
                        }
                        break;
                    case 2:
                        if (legitmode == true)
                        {

                        }
                        else
                        {
                            if (count < Weapons::lr::pattern.size())
                            {
                                Smoothing(Weapons::lr::delay, Weapons::lr::delay, Randomize(tofovandsens(playersens, playerfov, Weapons::lr::pattern.at(count).x), randomizer), Randomize(tofovandsens(playersens, playerfov, Weapons::lr::pattern.at(count).y), randomizer));
                                count++;
                            }
                        }
                        break;
                    case 3:
                        if (legitmode == true)
                        {

                        }
                        else
                        {
                            if (count < Weapons::mp5::pattern.size())
                            {
                                Smoothing(Weapons::mp5::delay, Weapons::mp5::delay, Randomize(tofovandsens(playersens, playerfov, Weapons::mp5::pattern.at(count).x), randomizer), Randomize(tofovandsens(playersens, playerfov, Weapons::mp5::pattern.at(count).y), randomizer));
                                count++;
                            }
                        }
                        break;
                    case 6:
                        if (legitmode == true)
                        {

                        }
                        else
                        {
                            if (GetAsyncKeyState(VK_LCONTROL))
                            {
                                if (count < Special::Ssemi::pattern.size())
                                {
                                    Smoothing(Special::Ssemi::delay, Special::Ssemi::delay, Randomize(tofovandsens(playersens, playerfov, Special::Ssemi::pattern.at(count).x), randomizer), Randomize(tofovandsens(playersens, playerfov, Special::Ssemi::pattern.at(count).y), randomizer));
                                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                                }
                            }
                            else
                            {
                                if (count < Weapons::semi::pattern.size())
                                {
                                    Smoothing(Weapons::semi::delay, Weapons::semi::delay, Randomize(tofovandsens(playersens, playerfov, Weapons::semi::pattern.at(count).x), randomizer), Randomize(tofovandsens(playersens, playerfov, Weapons::semi::pattern.at(count).y), randomizer));
                                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                                }
                            }
                        }
                        break;
                    case 7:
                        if (GetAsyncKeyState(VK_LCONTROL))
                        {
                            if (count < Weapons::m249::pattern.size())
                            {
                                Smoothing(Weapons::m249::delay, Weapons::m249::delay, Randomize(tofovandsens(playersens, playerfov, Weapons::m249::pattern.at(count).x), randomizer), Randomize(tofovandsens(playersens, playerfov, Weapons::m249::pattern.at(count).y), randomizer));
                            }
                            
                            
                        }
                        else
                        {
                            if (count < Special::Sm249::pattern.size())
                            {
                                Smoothing(Special::Sm249::delay, Special::Sm249::delay, Randomize(tofovandsens(playersens, playerfov, Special::Sm249::pattern.at(count).x), randomizer), Randomize(tofovandsens(playersens, playerfov, Special::Sm249::pattern.at(count).y), randomizer));
                            }
                            
                        }

                        break;
                    default:
                        break;
                    }
                }
                else
                    count = 0;
            }
        }

        if (f3152tvfeg25y246thet == false)
        {
            // Start the Dear ImGui frame
            ImGui_ImplDX9_NewFrame();
            ImGui_ImplWin32_NewFrame();
            ImGui::NewFrame();
            {

                if (isFirstMenuOpen) {
                    /*Style Colors*/
                    ImGuiStyle& Style = ImGui::GetStyle();
                    Style.WindowBorderSize = 0;
                    Style.FrameRounding = 5;
                    Style.WindowRounding = 0;
                    Style.WindowTitleAlign = ImVec2(0.5, 0.5);
                    Style.Colors[ImGuiCol_WindowBg] = ImColor(28, 29, 31);
                    Style.Colors[ImGuiCol_TitleBg] = ImColor(51, 52, 54);
                    Style.Colors[ImGuiCol_TitleBgActive] = ImColor(51, 52, 54);
                    Style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(51, 52, 54);
                    Style.Colors[ImGuiCol_Button] = ImColor(51, 52, 54);
                    Style.Colors[ImGuiCol_ButtonActive] = ImColor(51, 52, 54);
                    Style.Colors[ImGuiCol_ButtonHovered] = ImColor(255, 52, 54);
                    Style.Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
                    Style.Colors[ImGuiCol_TextDisabled] = ImColor(255, 255, 255);
                    Style.Colors[ImGuiCol_TextSelectedBg] = ImColor(255, 255, 255);
                    Style.Colors[ImGuiCol_FrameBg] = ImColor(51, 52, 54);
                    Style.Colors[ImGuiCol_FrameBgActive] = ImColor(51, 52, 54);
                    Style.Colors[ImGuiCol_FrameBgHovered] = ImColor(51, 52, 54);
                    Style.Colors[ImGuiCol_CheckMark] = ImColor(255, 255, 255);
                    ImGui::PushFont(Arial); {
                        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(4, 6));
                        ImGui::Begin("Evil Side", &loader_active, window_flags); {
                            ImGui::PopStyleVar();
                            ImGui::SetWindowSize(ImVec2(339, 400));
                            ImGui::BeginChild("##TopChild", ImVec2(0, ImGui::GetWindowHeight() / 2.5)); {
                                ImGui::SameLine((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize("Login").x / 2));
                                ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(10, 6));
                                ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing();
                                ImGui::SetCursorPosX((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize("Key goes here!").x / 0.93f));
                                ImGui::InputTextWithHint("", "              License Key", key, sizeof(key));
                                ImGui::PopStyleVar();
                                ImGui::SetCursorPosY((ImGui::GetWindowSize().y / 1.6));
                                ImGui::Text("                             ");
                                ImGui::SameLine();
                        /*        if (ImGui::Button("Login", ImVec2(70, 27))) {
                                    if (KeyAuthApp.license(key)) {
                                        isSecondMenuOpen = true;
                                        isFirstMenuOpen = false;

                                    }

                                } */

                                isSecondMenuOpen = true;
                                isFirstMenuOpen = false;

                                ImGui::EndChild();
                            }
                            ImGui::BeginChild("##BottomChild", ImVec2(0, 0)); {
                                ImGui::Separator();
                                ImGui::Spacing();
                                ImGui::Spacing();
                                ImGui::SameLine((ImGui::GetContentRegionAvail().x / 2) - (ImGui::CalcTextSize("Patchnotes").x / 2));
                                ImGui::Text("Patchnotes");
                                ImGui::Spacing();
                                ImGui::Separator();
                                ImGui::Spacing();
                                ImGui::BulletText("Added New Configs");
                                ImGui::BulletText("Added Hide Script");
                                ImGui::BulletText("Added All Keybinds and full configs");
                                ImGui::BulletText("Added Legit Mode (Only working with ak atm)");
                                ImGui::BulletText("Added Fully Working Anti-AFK");
                                ImGui::EndChild();
                            }
                            ImGui::End();
                        }
                        ImGui::PopFont();
                    }
                }

                if (isSecondMenuOpen) {

                    ImGuiStyle& Style = ImGui::GetStyle();
                    Style.WindowBorderSize = 0;
                    Style.FrameRounding = 5;
                    Style.WindowRounding = 0;
                    Style.WindowTitleAlign = ImVec2(0.5, 0.5);
                    Style.Colors[ImGuiCol_WindowBg] = ImColor(28, 29, 31);
                    Style.Colors[ImGuiCol_TitleBg] = ImColor(51, 52, 54);
                    Style.Colors[ImGuiCol_TitleBgActive] = ImColor(51, 52, 54);
                    Style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(51, 52, 54);
                    Style.Colors[ImGuiCol_Button] = ImColor(51, 52, 54);
                    Style.Colors[ImGuiCol_ButtonActive] = ImColor(255, 52, 54);
                    Style.Colors[ImGuiCol_ButtonHovered] = ImColor(255, 52, 54);
                    Style.Colors[ImGuiCol_Text] = ImColor(255, 255, 255);
                    Style.Colors[ImGuiCol_TextDisabled] = ImColor(255, 255, 255);
                    Style.Colors[ImGuiCol_TextSelectedBg] = ImColor(255, 255, 255);
                    Style.Colors[ImGuiCol_FrameBg] = ImColor(51, 52, 54);
                    Style.Colors[ImGuiCol_FrameBgActive] = ImColor(51, 52, 54);
                    Style.Colors[ImGuiCol_FrameBgHovered] = ImColor(51, 52, 54);
                    Style.Colors[ImGuiCol_CheckMark] = ImColor(255, 255, 255);
                    Style.Colors[ImGuiCol_DragDropTarget] = ImColor(255, 255, 255);
                    Style.Colors[ImGuiCol_ScrollbarBg] = ImColor(31, 31, 31, 255);
                    Style.Colors[ImGuiCol_ScrollbarGrab] = ImColor(255, 255, 255, 255);
                    Style.Colors[ImGuiCol_ScrollbarGrabActive] = ImColor(255, 255, 255, 255);
                    Style.Colors[ImGuiCol_ChildBg] = ImColor(26, 26, 26, 255);
                    Style.Colors[ImGuiCol_ResizeGrip] = ImColor(30, 30, 30, 255);
                    Style.Colors[ImGuiCol_ResizeGripActive] = ImColor(30, 30, 30, 255);
                    Style.Colors[ImGuiCol_ResizeGripHovered] = ImColor(30, 30, 30, 255);

                    Style.Colors[ImGuiCol_ChildBg] = ImColor(26, 26, 26, 255);

                    Style.Colors[ImGuiCol_ScrollbarBg] = ImColor(31, 31, 31, 255);
                    Style.Colors[ImGuiCol_ScrollbarGrab] = ImColor(255, 255, 255, 255);
                    Style.Colors[ImGuiCol_ScrollbarGrabActive] = ImColor(255, 255, 255, 255);

                    Style.Colors[ImGuiCol_Header] = ImColor(39, 39, 39, 255);
                    Style.Colors[ImGuiCol_HeaderActive] = ImColor(39, 39, 39, 255);
                    Style.Colors[ImGuiCol_HeaderHovered] = ImColor(39, 39, 39, 255);
                    Style.Colors[ImGuiCol_CheckMark] = ImColor(255, 255, 255, 255);
                    ImGui::Begin("Evil Side", &loader_active, window_flags);
                    ImGui::SetWindowSize(ImVec2(339, 400));
                    static int Tab = 0;


                    switch (Tab)
                    {
                    case 0:

                        //if (ImGui::BeginChild("##LeftSideSettingsTabOne", ImVec2(ImGui::GetContentRegionAvail().x / 2, ImGui::GetContentRegionAvail().y / 1))) {
                        ImGui::Checkbox("###Enabled?", &enabled);
                        ImGui::SameLine();
                        ImGui::Text("Enable", *io.Fonts);

                        ImGui::Spacing();
                        ImGui::Text("Weapons");
                        ImGui::Combo("###Weapons", &selectedWeapon, weapon, IM_ARRAYSIZE(weapon), 4);

                        ImGui::Spacing();
                        ImGui::Text("Scopes");
                        ImGui::Combo("###Scopes", &selectedScope, scope, IM_ARRAYSIZE(scope), 4);

                        ImGui::Spacing();
                        ImGui::Text("Barrel");
                        ImGui::Combo("###Barrels", &selectedBarrel, barrel, IM_ARRAYSIZE(barrel));

                        ImGui::Spacing();
                        ImGui::Text("Recoil Assistance");
                        ImGui::Combo("###Recoil", &selectedRecoil, reducerecoil, IM_ARRAYSIZE(reducerecoil), 4);

                        ImGui::Spacing();
                        ImGui::Checkbox("###Legitmode", &legitmode);
                        ImGui::SameLine();
                        ImGui::Text("Legitmode");

                        ImGui::Spacing(); ImGui::Spacing(); ImGui::Spacing();
                        // ImGui::Checkbox("###AutoDetect", &autodetected);
                        ImGui::SameLine();
                        // ImGui::Text("Auto Detect (Beta)");
                        ImGui::Spacing();
                        //ImGui::Checkbox("###Hipfire", &hipfire);
                        ImGui::SameLine();
                        //ImGui::Text("HipFire");
                    //}
                   // ImGui::EndChild();
                        break;
                    case 1:
                        if (ImGui::Button("Refresh Settings", ImVec2(120, 30)))
                        {
                            getsettings();
                        }
                        
                        break;
                    case 2:
                        if (ImGui::BeginChild("##LeftSideSettingsTabOne", ImVec2(ImGui::GetContentRegionAvail().x / 1, ImGui::GetContentRegionAvail().y / 1.26))) {
                        ImGui::Combo("###Enable", &selectedEnabled, enable, IM_ARRAYSIZE(enable), 4);
                        ImGui::SameLine();
                        ImGui::Text("Enable");

                        ImGui::Combo("###HideMenu", &selectedHide, hide, IM_ARRAYSIZE(hide), 4);
                        ImGui::SameLine();
                        ImGui::Text("Hide Menu");

                        ImGui::Combo("###LegitMode", &selectedlegitmode, keybindlegitmode, IM_ARRAYSIZE(keybindlegitmode), 4);
                        ImGui::SameLine();
                        ImGui::Text("Legitmode");

                        ImGui::Combo("###AKbind", &selectedkeybindak, keybindak, IM_ARRAYSIZE(keybindak), 4);
                        ImGui::SameLine();
                        ImGui::Text("Ak-47 Bind");

                        ImGui::Combo("###lr300", &selectedkeybindlr, keybindlr, IM_ARRAYSIZE(keybindlr), 4);
                        ImGui::SameLine();
                        ImGui::Text("Lr-300 Bind");

                        ImGui::Combo("###mp5", &selectedkeybindmp5, keybindmp5, IM_ARRAYSIZE(keybindmp5), 4);
                        ImGui::SameLine();
                        ImGui::Text("Mp5 Bind");

                        ImGui::Combo("###smg", &selectedkeybindsmg, keybindsmg, IM_ARRAYSIZE(keybindsmg), 4);
                        ImGui::SameLine();
                        ImGui::Text("Custom Bind");

                        ImGui::Combo("###tommy", &selectedkeybindtommy, keybindtommy, IM_ARRAYSIZE(keybindtommy), 4);
                        ImGui::SameLine();
                        ImGui::Text("Tommy Bind");

                        ImGui::Combo("###sar", &selectedkeybindsar, keybindsar, IM_ARRAYSIZE(keybindsar), 4);
                        ImGui::SameLine();
                        ImGui::Text("Semi Bind");

                        ImGui::Combo("###m2", &selectedkeybindm2, keybindm2, IM_ARRAYSIZE(keybindm2), 4);
                        ImGui::SameLine();
                        ImGui::Text("M249 Bind");

                        ImGui::Combo("###Holo sight", &selectedkeybindholosight, keybindholosight, IM_ARRAYSIZE(keybindholosight), 4);
                        ImGui::SameLine();
                        ImGui::Text("Holo Bind");

                        ImGui::Combo("###Simple sight", &selectedkeybindsimplesight, keybindsimplesight, IM_ARRAYSIZE(keybindsimplesight), 4);
                        ImGui::SameLine();
                        ImGui::Text("Simple Bind");

                        ImGui::Combo("###x8 sight", &selectedkeybindx8, keybindx8, IM_ARRAYSIZE(keybindx8), 4);
                        ImGui::SameLine();
                        ImGui::Text("X8 Bind");

                        ImGui::Combo("###x16 sight", &selectedkeybindx16, keybindx16, IM_ARRAYSIZE(keybindx16), 4);
                        ImGui::SameLine();
                        ImGui::Text("X16 Bind");

                        ImGui::Combo("###suppressor sight", &selectedkeybindsuppresor, keybindsuppresor, IM_ARRAYSIZE(keybindsuppresor), 4);
                        ImGui::SameLine();
                        ImGui::Text("Silencer Bind");

                        ImGui::Combo("###no sight", &selectedkeybindnosight, keybindnosight, IM_ARRAYSIZE(keybindnosight), 4);
                        ImGui::SameLine();
                        ImGui::Text("No Scope Bind");

                        ImGui::Combo("###no barrel", &selectedkeybindnobarrel, keybindnobarrel, IM_ARRAYSIZE(keybindnobarrel), 4);
                        ImGui::SameLine();
                        ImGui::Text("No Barrel Bind");

                    }
                    ImGui::EndChild();
                        

                        if (selectedHide == 0)
                        {
                            ishidden = false;
                        }
                        else
                        {
                            ishidden = true;
                        }

                        if (ImGui::Button("Save", ImVec2(103, 32))) {
                            {
                                remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedhide.cfg");//
                                string ferd = "selected.hide '";
                                string ign = "selectedhide.cfg";
                                std::ofstream OutFile("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\" + ign, std::ios::out);
                                OutFile << ferd;
                                OutFile << selectedHide;
                                OutFile << "'";
                                OutFile.close();
                            }
                            {
                                remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedenabled.cfg");//
                                string ferd = "selected.enabled '";
                                string ign = "selectedenabled.cfg";
                                std::ofstream OutFile("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\" + ign, std::ios::out);
                                OutFile << ferd;
                                OutFile << selectedEnabled;
                                OutFile << "'";
                                OutFile.close();
                            }
                            {
                                remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedakbind.cfg");//
                                string ferd = "selected.akbind '";
                                string ign = "selectedakbind.cfg";
                                std::ofstream OutFile("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\" + ign, std::ios::out);
                                OutFile << ferd;
                                OutFile << selectedkeybindak;
                                OutFile << "'";
                                OutFile.close();
                            }
                            {
                                remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedlrbind.cfg");//
                                string ferd = "selected.lrbind '";
                                string ign = "selectedlrbind.cfg";
                                std::ofstream OutFile("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\" + ign, std::ios::out);
                                OutFile << ferd;
                                OutFile << selectedkeybindlr;
                                OutFile << "'";
                                OutFile.close();
                            }
                            {
                                remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedmp5bind.cfg");//
                                string ferd = "selected.mp5bind '";
                                string ign = "selectedmp5bind.cfg";
                                std::ofstream OutFile("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\" + ign, std::ios::out);
                                OutFile << ferd;
                                OutFile << selectedkeybindmp5;
                                OutFile << "'";
                                OutFile.close();
                            }
                            {
                                remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedsmgbind.cfg");//
                                string ferd = "selected.smgbind '";
                                string ign = "selectedsmgbind.cfg";
                                std::ofstream OutFile("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\" + ign, std::ios::out);
                                OutFile << ferd;
                                OutFile << selectedkeybindsmg;
                                OutFile << "'";
                                OutFile.close();
                            }
                            {
                                remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedtommybind.cfg");//
                                string ferd = "selected.tommybind '";
                                string ign = "selectedtommybind.cfg";
                                std::ofstream OutFile("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\" + ign, std::ios::out);
                                OutFile << ferd;
                                OutFile << selectedkeybindtommy;
                                OutFile << "'";
                                OutFile.close();
                            }
                            {
                                remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedsarbind.cfg");//
                                string ferd = "selected.sarbind '";
                                string ign = "selectedsarbind.cfg";
                                std::ofstream OutFile("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\" + ign, std::ios::out);
                                OutFile << ferd;
                                OutFile << selectedkeybindsar;
                                OutFile << "'";
                                OutFile.close();
                            }
                            {
                                remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedm2bind.cfg");//
                                string ferd = "selected.m2bind '";
                                string ign = "selectedm2bind.cfg";
                                std::ofstream OutFile("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\" + ign, std::ios::out);
                                OutFile << ferd;
                                OutFile << selectedkeybindm2;
                                OutFile << "'";
                                OutFile.close();
                            }
                            {
                                remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedx16bind.cfg");//
                                string ferd = "selected.x16bind '";
                                string ign = "selectedx16bind.cfg";
                                std::ofstream OutFile("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\" + ign, std::ios::out);
                                OutFile << ferd;
                                OutFile << selectedkeybindx16;
                                OutFile << "'";
                                OutFile.close();
                            }
                            {
                                remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedx8bind.cfg");//
                                string ferd = "selected.x8bind '";
                                string ign = "selectedx8bind.cfg";
                                std::ofstream OutFile("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\" + ign, std::ios::out);
                                OutFile << ferd;
                                OutFile << selectedkeybindx8;
                                OutFile << "'";
                                OutFile.close();
                            }
                            {
                                remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedsimplesightbind.cfg");//
                                string ferd = "selected.simplesightbind '";
                                string ign = "selectedsimplesightbind.cfg";
                                std::ofstream OutFile("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\" + ign, std::ios::out);
                                OutFile << ferd;
                                OutFile << selectedkeybindsimplesight;
                                OutFile << "'";
                                OutFile.close();
                            }
                            {
                                remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedholosightbind.cfg");//
                                string ferd = "selected.holosightbind '";
                                string ign = "selectedholosightbind.cfg";
                                std::ofstream OutFile("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\" + ign, std::ios::out);
                                OutFile << ferd;
                                OutFile << selectedkeybindholosight;
                                OutFile << "'";
                                OutFile.close();
                            }
                            {
                                remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedsuppressorbind.cfg");//
                                string ferd = "selected.suppressorbind '";
                                string ign = "selectedsuppressorbind.cfg";
                                std::ofstream OutFile("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\" + ign, std::ios::out);
                                OutFile << ferd;
                                OutFile << selectedkeybindsuppresor;
                                OutFile << "'";
                                OutFile.close();
                            }
                            {
                                remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectednobarrelbind.cfg");//
                                string ferd = "selected.nobarrelbind '";
                                string ign = "selectednobarrelbind.cfg";
                                std::ofstream OutFile("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\" + ign, std::ios::out);
                                OutFile << ferd;
                                OutFile << selectedkeybindnobarrel;
                                OutFile << "'";
                                OutFile.close();
                            }
                            {
                                remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectednosightbind.cfg");//
                                string ferd = "selected.nosightbind '";
                                string ign = "selectednosightbind.cfg";
                                std::ofstream OutFile("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\" + ign, std::ios::out);
                                OutFile << ferd;
                                OutFile << selectedkeybindnosight;
                                OutFile << "'";
                                OutFile.close();
                            }
                            {
                                remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedkeybindlegitmode.cfg");//
                                string ferd = "selected.legitmode '";
                                string ign = "selectedkeybindlegitmode.cfg";
                                std::ofstream OutFile("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\" + ign, std::ios::out);
                                OutFile << ferd;
                                OutFile << selectedlegitmode;
                                OutFile << "'";
                                OutFile.close();
                            }
                        } ImGui::SameLine();
                        if (ImGui::Button("Delete", ImVec2(103, 32)))
                        {
                            remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedhide.cfg");
                            remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedenabled.cfg");
                            remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedakbind.cfg");
                            remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedlrbind.cfg");
                            remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedmp5bind.cfg");
                            remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedsmgbind.cfg");
                            remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedtommybind.cfg");
                            remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedsarbind.cfg");
                            remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedm2bind.cfg");
                            remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedx16bind.cfg");
                            remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedx8bind.cfg");
                            remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedsimplesightbind.cfg");
                            remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedholosightbind.cfg");
                            remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedsuppressorbind.cfg");
                            remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectednosightbind.cfg");
                            remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectednobarrelbind.cfg");
                            remove("C:\\Program Files (x86)\\Steam\\steamapps\\common\\Rust\\cfg\\selectedkeybindlegitmode.cfg");
                            
                        } ImGui::SameLine();
                        if (ImGui::Button("Clear", ImVec2(103, 32))) 
                        {
                            selectedkeybindsuppresor = 0;
                            selectedkeybindholosight = 0;
                            selectedkeybindsimplesight = 0;
                            selectedkeybindx8 = 0;
                            selectedkeybindx16 = 0;
                            selectedkeybindm2 = 0;
                            selectedkeybindsar = 0;
                            selectedkeybindtommy = 0;
                            selectedkeybindsmg = 0;
                            selectedkeybindmp5 = 0;
                            selectedkeybindlr = 0;
                            selectedkeybindak = 0;
                            selectedHide = 0;
                            selectedEnabled = 0;
                            selectedkeybindnosight = 0;
                            selectedkeybindnobarrel = 0; 
                            selectedlegitmode = 0;
                        }

                        
                        break;
                    case 3:
                        ImGui::Checkbox("Anti-AFK", &antiafk);
                        if (antiafk == true)
                        {
                            if (number == 500)
                            {
                                keybd_event(0x57, 0, KEYEVENTF_EXTENDEDKEY, 0);
                                Sleep(500);
                                keybd_event(0x57, 0, KEYEVENTF_KEYUP, 0);
                            }
                            if (number == 1000)
                            {
                                keybd_event(0x44, 0, KEYEVENTF_EXTENDEDKEY, 0);
                                Sleep(500);
                                keybd_event(0x44, 0, KEYEVENTF_KEYUP, 0);
                            }
                            if (number == 1500)
                            {
                                keybd_event(0x53, 0, KEYEVENTF_EXTENDEDKEY, 0);
                                Sleep(500);
                                keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0);
                            }
                            if (number == 2000)
                            {
                                keybd_event(0x41, 0, KEYEVENTF_EXTENDEDKEY, 0);
                                Sleep(500);
                                keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0);
                                number = 0;
                            }
                            else
                            {
                                Sleep(10);
                                number = number + 1;
                            }

                        }

                        break;

                    }


                    ImGui::SetCursorPosY((ImGui::GetWindowSize().y / 1.115));
                    ImGui::Separator();
                    ImGui::Spacing(); 
                    if (ImGui::Button("Weapons", ImVec2(ImGui::GetContentRegionAvail().x / 4, 30))) { Tab = 0; }
                    ImGui::SameLine();
                    if (ImGui::Button("Settings", ImVec2(ImGui::GetContentRegionAvail().x / 3, 30))) { Tab = 1; }
                    ImGui::SameLine();
                    if (ImGui::Button("Keybinds", ImVec2(ImGui::GetContentRegionAvail().x / 2, 30))) { Tab = 2; }
                    ImGui::SameLine();
                    if (ImGui::Button("Misc", ImVec2(ImGui::GetContentRegionAvail().x / 1, 30))) { Tab = 3; }
                    ImGui::Spacing(); ImGui::Spacing();
                    ImGui::End();
                }
            }
            ImGui::EndFrame();
        }
        

        g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
        }

       if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }

        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);

        // Handle loss of D3D9 device
        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
            ResetDevice();
        }
        if (!loader_active) {
            msg.message = WM_QUIT;
        }
    }
    

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    DestroyWindow(main_hwnd);
    UnregisterClass(wc.lpszClassName, wc.hInstance);

    return 0;

}



LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            g_d3dpp.BackBufferWidth = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

