// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SlateDemo : ModuleRules
{
	public SlateDemo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "InputCore" });
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore"});
	}
}
