#include "BatchFileUtils.h"
#include "Windows/AllowWindowsPlatformTypes.h"
#include <Windows.h>
#include "Windows/HideWindowsPlatformTypes.h"

int32 UBatchFileUtils::RunBatchFile(FString BatchFilePath, bool bRunInBackground)
{
    STARTUPINFO StartupInfo;
    PROCESS_INFORMATION ProcessInfo;
    memset(&StartupInfo, 0, sizeof(StartupInfo));
    StartupInfo.cb = sizeof(StartupInfo);

    // Set the window visibility based on the bRunInBackground parameter
    if (bRunInBackground)
    {
        StartupInfo.dwFlags |= STARTF_USESHOWWINDOW;
        StartupInfo.wShowWindow = SW_HIDE;
    }

    memset(&ProcessInfo, 0, sizeof(ProcessInfo));

    TCHAR CommandLine[MAX_PATH];
    _tcscpy_s(CommandLine, *BatchFilePath);

    if (CreateProcess(nullptr, CommandLine, nullptr, nullptr, false, 0, nullptr, nullptr, &StartupInfo, &ProcessInfo))
    {
        CloseHandle(ProcessInfo.hThread);
        return ProcessInfo.dwProcessId;
    }
    return 0;
}

bool UBatchFileUtils::IsProcessRunning(int32 ProcessID)
{
    HANDLE ProcessHandle = OpenProcess(PROCESS_QUERY_INFORMATION, false, ProcessID);
    if (ProcessHandle == nullptr)
    {
        return false;
    }

    DWORD ExitCode;
    if (!GetExitCodeProcess(ProcessHandle, &ExitCode))
    {
        CloseHandle(ProcessHandle);
        return false;
    }

    CloseHandle(ProcessHandle);
    return (ExitCode == STILL_ACTIVE);
}
