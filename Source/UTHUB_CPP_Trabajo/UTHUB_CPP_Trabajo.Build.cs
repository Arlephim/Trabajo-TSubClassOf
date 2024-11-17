// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UTHUB_CPP_Trabajo : ModuleRules
{
	public UTHUB_CPP_Trabajo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "Niagara" });
	}
}
