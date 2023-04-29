using UnrealBuildTool;

public class GameFeatureUtil : ModuleRules
{
    public GameFeatureUtil(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] {"Core"});

        PrivateDependencyModuleNames.AddRange(new string[] {
                "CoreUObject",
                "Engine",
				"GameFeatures",
                "ModularGameplay",
        });
    }
}
