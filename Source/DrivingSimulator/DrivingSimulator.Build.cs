using UnrealBuildTool;

public class DrivingSimulator : ModuleRules
{
	public DrivingSimulator(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "ChaosVehicles" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
