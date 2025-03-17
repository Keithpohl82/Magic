// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MPMagic : ModuleRules
{
	public MPMagic(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
