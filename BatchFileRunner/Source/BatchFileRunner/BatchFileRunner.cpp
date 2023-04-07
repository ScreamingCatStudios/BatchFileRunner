#include "BatchFileRunner.h"

// Define the namespace for localization macros.
#define LOCTEXT_NAMESPACE "FBatchFileRunnerModule"

// Implement the StartupModule method for the BatchFileRunner module.
void FBatchFileRunnerModule::StartupModule()
{
	// This method is intentionally left empty, as no specific actions are required during startup.
}

// Implement the ShutdownModule method for the BatchFileRunner module.
void FBatchFileRunnerModule::ShutdownModule()
{
	// This method is intentionally left empty, as no specific actions are required during shutdown.
}

// Undefine the namespace after the class implementation to avoid conflicts.
#undef LOCTEXT_NAMESPACE

// Implement the module for the BatchFileRunner plugin, using the FBatchFileRunnerModule class.
IMPLEMENT_MODULE(FBatchFileRunnerModule, BatchFileRunner)