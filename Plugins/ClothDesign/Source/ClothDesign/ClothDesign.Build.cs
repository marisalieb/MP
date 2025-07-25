// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ClothDesign : ModuleRules
{
	public ClothDesign(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"GeometryFramework", 
				"MeshDescription", 
				"StaticMeshDescription",
				"ProceduralMeshComponent",
				"GeometryCore",

				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"InputCore",
				"EditorFramework",
				"EditorStyle",
				"UnrealEd",
				"LevelEditor",
				"InteractiveToolsFramework",
				"EditorInteractiveToolsFramework",
				"ToolMenus", // for 2d window
				"PropertyEditor",
				"Projects",
				"GeometryCore",
				"GeometryAlgorithms",
				"GeometryFramework", 
				"DynamicMesh",      // for FDynamicMesh3
				"GeometryCore",        // Core geometry types
				"MeshModelingTools", // Optional but useful
				"ContentBrowser",
				"PropertyEditor",
				"EditorStyle"

				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
