#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

// Declare a class for the BatchFileRunner module, derived from IModuleInterface.
class FBatchFileRunnerModule : public IModuleInterface
{
public:

    // Declare the StartupModule method for the BatchFileRunner module.
    virtual void StartupModule() override;

    // Declare the ShutdownModule method for the BatchFileRunner module.
    virtual void ShutdownModule() override;
};