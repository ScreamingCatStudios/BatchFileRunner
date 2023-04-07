using UnrealBuildTool;

// Define a new module for the BatchFileRunner plugin.
public class BatchFileRunner : ModuleRules
{
    // Constructor for the BatchFileRunner module, taking a ReadOnlyTargetRules object as input.
    public BatchFileRunner(ReadOnlyTargetRules Target) : base(Target)
    {
        // Set the Precompiled Header (PCH) usage mode for this module.
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // Declare public dependencies for this module, making them available to other modules that depend on this one.
    PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        // Declare private dependencies for this module, which are only used internally and not exposed to other modules.
        PrivateDependencyModuleNames.AddRange(new string[] { });

        // Check if the current target platform is Windows 64-bit.
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            // If the platform is Windows 64-bit, add the "WindowsPlatformFeatures" module as a private dependency.
            PrivateDependencyModuleNames.AddRange(new string[] { "WindowsPlatformFeatures" });
        }
    }
}