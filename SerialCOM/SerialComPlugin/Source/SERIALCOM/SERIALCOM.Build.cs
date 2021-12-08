using UnrealBuildTool;

public class SERIALCOM : ModuleRules
{
    public SERIALCOM(ReadOnlyTargetRules Target) : base(Target)
    {
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PrivateIncludePaths.AddRange(new string[] { "SERIALCOM/Private" });

        PrivateDependencyModuleNames.AddRange(
            new string[]
			{
                "Engine",
                "Core",
                "CoreUObject"
            }
        );
    }
}