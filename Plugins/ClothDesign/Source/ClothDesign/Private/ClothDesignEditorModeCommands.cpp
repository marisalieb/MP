// Copyright Epic Games, Inc. All Rights Reserved.

#include "ClothDesignEditorModeCommands.h"
#include "ClothDesignEditorMode.h"
#include "EditorStyleSet.h"

#define LOCTEXT_NAMESPACE "ClothDesignEditorModeCommands"

FClothDesignEditorModeCommands::FClothDesignEditorModeCommands()
	: TCommands<FClothDesignEditorModeCommands>("ClothDesignEditorMode",
		NSLOCTEXT("ClothDesignEditorMode", "ClothDesignEditorModeCommands", "ClothDesign Editor Mode"),
		NAME_None,
		//FEditorStyle::GetStyleSetName())
		FAppStyle::GetAppStyleSetName())
{
}

void FClothDesignEditorModeCommands::RegisterCommands()
{
	TArray <TSharedPtr<FUICommandInfo>>& ToolCommands = Commands.FindOrAdd(NAME_Default);

	// UI_COMMAND(SimpleTool, "Show Actor Info", "Opens message box with info about a clicked actor", EUserInterfaceActionType::Button, FInputChord());
	// ToolCommands.Add(SimpleTool);

	// UI_COMMAND(InteractiveTool, "Measure Distance", "Measures distance between 2 points (click to set origin, shift-click to set end point)", EUserInterfaceActionType::ToggleButton, FInputChord());
	// ToolCommands.Add(InteractiveTool);

	UI_COMMAND(Open2DWindow, "Open 2D Window", "Opens the custom 2D editor window", EUserInterfaceActionType::Button, FInputChord());

}

TMap<FName, TArray<TSharedPtr<FUICommandInfo>>> FClothDesignEditorModeCommands::GetCommands()
{
	return FClothDesignEditorModeCommands::Get().Commands;
}

#undef LOCTEXT_NAMESPACE
