// copyright qileisong

using UnrealBuildTool;
using System.Collections.Generic;

public class AuraClientTarget : TargetRules
{
	public AuraClientTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Client;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "Aura" } );
	}
}
