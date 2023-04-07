#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BatchFileUtils.generated.h"

UCLASS()
class BATCHFILERUNNER_API UBatchFileUtils : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    UFUNCTION(BlueprintCallable, Category = "Batch File Utils")
        static int32 RunBatchFile(FString BatchFilePath, bool bRunInBackground);


    UFUNCTION(BlueprintCallable, Category = "Batch File Utils")
        static bool IsProcessRunning(int32 ProcessID);
};
