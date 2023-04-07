#include "BatchFileUtils.h"
#include "Windows/AllowWindowsPlatformTypes.h"
#include <Windows.h>
#include "Windows/HideWindowsPlatformTypes.h"

// Function to run a batch file with the option to run it in the background.
int32 UBatchFileUtils::RunBatchFile(FString BatchFilePath, bool bRunInBackground)
{
    STARTUPINFO StartupInfo;
    PROCESS_INFORMATION ProcessInfo;
    memset(&StartupInfo, 0, sizeof(StartupInfo));
    StartupInfo.cb = sizeof(StartupInfo);

    // Set the window visibility based on the bRunInBackground parameter.
    if (bRunInBackground)
    {
        StartupInfo.dwFlags |= STARTF_USESHOWWINDOW;
        StartupInfo.wShowWindow = SW_HIDE;
    }

    memset(&ProcessInfo, 0, sizeof(ProcessInfo));

    TCHAR CommandLine[MAX_PATH];
    _tcscpy_s(CommandLine, *BatchFilePath);

    // Create and run the process using the given batch file path.
    if (CreateProcess(nullptr, CommandLine, nullptr, nullptr, false, 0, nullptr, nullptr, &StartupInfo, &ProcessInfo))
    {
        CloseHandle(ProcessInfo.hThread);
        return ProcessInfo.dwProcessId;
    }
    return 0;
}

// Function to check if a process with a given process ID is still running.
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

    // Function to run a batch script given as a string and return the process ID.
    int32 UBatchFileUtils::RunBatchScript(FString BatchScript, bool bRunInBackground)
    {
        // Create a temporary file path for the batch script.
        FString TempBatchFilePath = FPaths::Combine(FPaths::ProjectTempDir(), TEXT("TempBatchScript.bat"));

        // Save the batch script to the temporary file.
        FFileHelper::SaveStringToFile(BatchScript, *TempBatchFilePath);

        // Run the temporary batch file and store the process ID.
        int32 ProcessID = RunBatchFile(TempBatchFilePath, bRunInBackground);

        // Delete the temporary batch file.
        IFileManager::Get().Delete(*TempBatchFilePath);

        return ProcessID;
    }
}