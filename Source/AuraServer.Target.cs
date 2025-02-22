// copyright qileisong

using UnrealBuildTool;
using System.Collections.Generic;

public class AuraServerTarget : TargetRules
{
	public AuraServerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Server;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "Aura" } );
	}
}
