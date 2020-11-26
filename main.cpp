#include <Windows.h>
#include <iostream>
#include <optional>
#include <string>
#include <thread>
#include <vector>

HWND createFullscreenWindow(HWND hwnd) {
    HMONITOR hmon = MonitorFromWindow(hwnd, MONITOR_DEFAULTTOPRIMARY);
    MONITORINFO mi = { sizeof(MONITORINFO) };
    BOOL success = GetMonitorInfo(hmon, &mi);
    if (!success) {
        std::cerr << "Could not GetMonitorInfo" << std::endl;
        return nullptr;
    }

    HWND res = CreateWindow(TEXT("static"), TEXT("Fireplace"), WS_POPUP | WS_VISIBLE,
        mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left,
        mi.rcMonitor.bottom - mi.rcMonitor.top, hwnd, nullptr, nullptr, nullptr);
    return res;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,
                   int nCmdShow)
{

//int main(int argc, char** argv) {
    //std::vector<std::string> args;
    //for (int i = 1; i < argc; ++i) {
    //    std::string arg = args[i];
    //    args.push_back(arg);
    //}

    HWND wnd = createFullscreenWindow*

    while (true) {
        SetThreadExecutionState(ES_SYSTEM_REQUIRED | ES_DISPLAY_REQUIRED | ES_CONTINUOUS);
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }

    SetThreadExecutionState(ES_CONTINUOUS);
}
