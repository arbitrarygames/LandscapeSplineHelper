#pragma once
#include "LandscapeSplineControlPoint.h"

#include "UBlueprintableLandscapeSplineControlPoint.generated.h"

UCLASS()
class UBlueprintableLandscapeSplineControlPoint : public UObject
{
	GENERATED_BODY()
public:
	/** Location in Landscape-space */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSpline)
	FVector Location;

	/** Rotation of tangent vector at this point (in landscape-space) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSpline)
	FRotator Rotation;

	/** Half-Width of the spline at this point. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSpline, meta = (DisplayName = "Half-Width"))
	float Width;

	/** Layer Width ratio of the spline at this point. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = LandscapeSpline)
	float LayerWidthRatio = 1.f;

	/** Falloff at the sides of the spline at this point. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSpline)
	float SideFalloff;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = LandscapeSpline, meta=(UIMin = 0, ClampMin = 0, UIMax = 1, ClampMax = 1))
	float LeftSideFalloffFactor = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = LandscapeSpline, meta = (UIMin = 0, ClampMin = 0, UIMax = 1, ClampMax = 1))
	float RightSideFalloffFactor = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = LandscapeSpline, meta = (UIMin = 0, ClampMin = 0, UIMax = 1, ClampMax = 1))
	float LeftSideLayerFalloffFactor = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = LandscapeSpline, meta = (UIMin = 0, ClampMin = 0, UIMax = 1, ClampMax = 1))
	float RightSideLayerFalloffFactor = 0.5f;

	/** Falloff at the start/end of the spline (if this point is a start or end point, otherwise ignored). */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSpline)
	float EndFalloff;
	
	/** Vertical offset of the spline segment mesh.  */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSpline, meta=(DisplayName="Mesh Vertical Offset"))
	float SegmentMeshOffset;
	
	/** Whether or not the terrain will raise to the level of the spline if the spline is above the terrain. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, BlueprintReadOnly, Category=LandscapeDeformation)
	bool ShouldRaiseTerrain;

	/** Whether or not the terrain will lower to the level of the spline if the spline is below the terrain.  */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, BlueprintReadOnly, Category=LandscapeDeformation)
	bool ShouldLowerTerrain;

	/** The mesh on this control point */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Mesh)
	UStaticMesh* Mesh;

	/** The mesh's material overrides.*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Mesh)
	TArray<UMaterialInterface*> MaterialOverrides;

	/** Scale of the control point mesh */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Mesh)
	FVector MeshScale;
	
	/** Whether the control point mesh is set to cast shadows */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, BlueprintReadOnly, Category=LandscapeSplineMeshes)
	bool ShouldCastShadow;

	/** Whether the control point mesh is hidden in game */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, BlueprintReadOnly, Category = LandscapeSplineMeshes)
	bool HiddenInGame;


	void Copy(ULandscapeSplineControlPoint* original)
	{
		// Copy properties
		Location = original->Location;
		Rotation = original->Rotation;
		Width = original->Width;
		LayerWidthRatio = original->LayerWidthRatio;
		SideFalloff = original->SideFalloff;
		LeftSideFalloffFactor = original->LeftSideFalloffFactor;
		RightSideFalloffFactor = original->RightSideFalloffFactor;
		LeftSideLayerFalloffFactor = original->LeftSideLayerFalloffFactor;
		RightSideLayerFalloffFactor = original->RightSideLayerFalloffFactor;
		EndFalloff = original->EndFalloff;
		SegmentMeshOffset = original->SegmentMeshOffset;
		ShouldRaiseTerrain = original->bRaiseTerrain == 1;
		ShouldLowerTerrain = original->bLowerTerrain == 1;
		Mesh = original->Mesh;
		MaterialOverrides = original->MaterialOverrides;
		MeshScale = original->MeshScale;
		ShouldCastShadow = original->bCastShadow == 1;
		HiddenInGame = original->bHiddenInGame == 1;
		
	}

	UBlueprintableLandscapeSplineControlPoint() {}
	
};
