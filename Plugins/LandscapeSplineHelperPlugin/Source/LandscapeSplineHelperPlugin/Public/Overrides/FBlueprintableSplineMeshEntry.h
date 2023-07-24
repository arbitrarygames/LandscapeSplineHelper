#pragma once
#include "LandscapeSplineSegment.h"
#include "FBlueprintableSplineMeshEntry.generated.h"

USTRUCT(BlueprintType)
struct FBlueprintableSplineMeshEntry
{
	GENERATED_BODY()

	/** Mesh in use by the spline.*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSplineMeshEntry)
	UStaticMesh* Mesh;

	/** Mesh's material overrides. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSplineMeshEntry, AdvancedDisplay)
	TArray<TObjectPtr<UMaterialInterface>> MaterialOverrides;

	/** Whether the mesh has been centered horizontally on the spline */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSplineMeshEntry, meta=(DisplayName="Is Centered Horizontally"))
	bool IsCenteredHorizontally;

	/** The mesh's center offset. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSplineMeshEntry, AdvancedDisplay, meta=(DisplayName="Center Adjust"))
	FVector2D CenterAdjust;

	/** Whether the mesh has been scaled to fit the width of the spline */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSplineMeshEntry)
	bool IsScaledToWidth;

	/** Scale of the spline mesh, (Z=Forwards) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSplineMeshEntry)
	FVector Scale;

	/** The forward axis of the spline mesh orientation */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSplineMeshEntry)
	TEnumAsByte<ESplineMeshAxis::Type> ForwardAxis;

	/** The up axis for the spline mesh orientation */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSplineMeshEntry)
	TEnumAsByte<ESplineMeshAxis::Type> UpAxis;
	
	FBlueprintableSplineMeshEntry(FLandscapeSplineMeshEntry original)
	{
		// Set all properties to the original's properties
		Mesh = original.Mesh;
		MaterialOverrides = original.MaterialOverrides;
		IsCenteredHorizontally = original.bCenterH == 1;
		CenterAdjust = original.CenterAdjust;
		IsScaledToWidth = original.bScaleToWidth == 1;
		Scale = original.Scale;
		ForwardAxis = original.ForwardAxis;
		UpAxis = original.UpAxis;
	}
	FBlueprintableSplineMeshEntry() {}
};
