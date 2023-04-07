#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BatchFileUtils.generated.h"

// Declare a UClass derived from UBlueprintFunctionLibrary for batch file-related utilities.
UCLASS()
class BATCHFILERUNNER_API UBatchFileUtils : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    // Declare a UFUNCTION to run a batch file with the option to run it in the background.
    UFUNCTION(BlueprintCallable, Category = "Batch File Utils")
        static int32 RunBatchFile(FString BatchFilePath, bool bRunInBackground);

    // Declare a UFUNCTION to check if a process with a given process ID is still running.
    UFUNCTION(BlueprintCallable, Category = "Batch File Utils")
        static bool IsProcessRunning(int32 ProcessID);

    // Declare a UFUNCTION to run a batch script given as a string and return the process ID.
    UFUNCTION(BlueprintCallable, Category = "Batch File Utils")
        static int32 RunBatchScript(FString BatchScript, bool bRunInBackground);
};
