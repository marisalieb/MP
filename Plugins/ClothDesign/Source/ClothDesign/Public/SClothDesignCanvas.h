#pragma once

#include "Widgets/SCompoundWidget.h"
#include "CompGeom/PolygonTriangulation.h"
#include "ProceduralMeshComponent.h"

// using namespace UE::Geometry;
#include "VectorTypes.h"


// Canvas state struct
struct FCanvasState
{
	TArray<FVector2D> Points;
	int32 SelectedPointIndex = INDEX_NONE;
	FVector2D PanOffset = FVector2D::ZeroVector;
	float ZoomFactor = 1.0f;

	// Optional equality operator
	bool operator==(const FCanvasState& Other) const
	{
		return Points == Other.Points &&
			   SelectedPointIndex == Other.SelectedPointIndex &&
			   PanOffset == Other.PanOffset &&
			   FMath::IsNearlyEqual(ZoomFactor, Other.ZoomFactor);
	}
};

class SClothDesignCanvas : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SClothDesignCanvas) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	
	virtual bool SupportsKeyboardFocus() const override { return true; }

	// --- Mouse handling ---
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	// --- Drawing logic ---
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry,
						  const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements,
						  int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;

	// Trigger mesh generation from drawn shape
	void TriangulateAndBuildMesh();
	
	float ZoomFactor = 1.0f;
	FVector2D PanOffset = FVector2D::ZeroVector;
	
	FVector2D TransformPoint(const FVector2D& Point) const;
	
	virtual FReply OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	// for selectable point and movement
	mutable int32 SelectedPointIndex = INDEX_NONE;
	mutable bool bIsDragging = false;
	
	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	// need different modes so button down isnt always just adding new points
	enum class EClothEditorMode
	{
		Draw,
		Select,
		Move
	};
	
	EClothEditorMode CurrentMode = EClothEditorMode::Draw;
	virtual FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply OnFocusReceived(const FGeometry& MyGeometry, const FFocusEvent& InFocusEvent) override;

	FVector2D InverseTransformPoint(const FVector2D& ScreenPoint) const;

	// Add some member state variables
	bool bIsDraggingPoint = false;
	bool bIsDraggingShape = false;
	bool bIsShapeSelected = false;
	bool IsPointNearLine(const FVector2D& P, const FVector2D& A, const FVector2D& B, float Threshold) const;

	TWeakObjectPtr<UTexture2D> BackgroundTexture;

protected:
	void CreateProceduralMesh(const TArray<FVector>& Vertices, const TArray<int32>& Indices);

	// Undo/Redo stacks
	TArray<FCanvasState> UndoStack;
	TArray<FCanvasState> RedoStack;

	// State management
	void SaveStateForUndo();
	FCanvasState GetCurrentCanvasState() const;
	void RestoreCanvasState(const FCanvasState& State);

	void Undo();
	void Redo();
	
private:
	TArray<FVector2D> Points;
};