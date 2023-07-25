#pragma once
#include "LandscapeSplineControlPoint.h"

#include "ULandscapeControlPointWrapper.generated.h"

UCLASS()
class ULandscapeControlPointWrapper : public UObject
{
	GENERATED_BODY()
public:
	/** Location in Landscape-space */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSpline)
	FVector GetRelativeLocation() {return original->Location;}

	/** Rotation of tangent vector at this point (in landscape-space) */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSpline)
	FRotator GetRelativeRotation() {return original->Rotation;}

	/** Location in world space */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSpline)
	FVector GetWorldLocation() {return WorldTransform.GetLocation() + original->Location;}

	/** Rotation of tangent vector at this point (in world-space) */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSpline)
	FRotator GetWorldRotation() {return WorldTransform.GetRotation().Rotator() + original->Rotation;}
	
	/** Half-Width of the spline at this point. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSpline, meta = (DisplayName = "Half-Width"))
	float GetWidth() {return original->Width;}

	/** Layer Width ratio of the spline at this point. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = LandscapeSpline)
	float GetLayerWidthRatio() { return original->LayerWidthRatio; }

	/** Falloff at the sides of the spline at this point. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSpline)
	float GetSideFalloff() {return original->SideFalloff;}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = LandscapeSpline, meta=(UIMin = 0, ClampMin = 0, UIMax = 1, ClampMax = 1))
	float GetLeftSideFalloffFactor() { return original->LeftSideFalloffFactor; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = LandscapeSpline, meta = (UIMin = 0, ClampMin = 0, UIMax = 1, ClampMax = 1))
	float GetRightSideFalloffFactor() { return original->RightSideFalloffFactor; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = LandscapeSpline, meta = (UIMin = 0, ClampMin = 0, UIMax = 1, ClampMax = 1))
	float GetLeftSideLayerFalloffFactor() { return original->LeftSideLayerFalloffFactor; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = LandscapeSpline, meta = (UIMin = 0, ClampMin = 0, UIMax = 1, ClampMax = 1))
	float GetRightSideLayerFalloffFactor() { return original->RightSideLayerFalloffFactor; }

	/** Falloff at the start/end of the spline (if this point is a start or end point, otherwise ignored). */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSpline)
	float GetEndFalloff() {return original->EndFalloff;}
	
	/** Vertical offset of the spline segment mesh.  */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSpline, meta=(DisplayName="Mesh Vertical Offset"))
	float GetSegmentMeshOffset() {return original->SegmentMeshOffset;}
	
	/** Whether or not the terrain will raise to the level of the spline if the spline is above the terrain. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeDeformation)
	bool GetShouldRaiseTerrain() {return original->bRaiseTerrain;}

	/** Whether or not the terrain will lower to the level of the spline if the spline is below the terrain.  */
	UFUNCTION(BlueprintCallable, BlueprintPure,  Category=LandscapeDeformation)
	bool GetShouldLowerTerrain() {return original->bLowerTerrain;}

	/** The mesh on this control point */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=Mesh)
	UStaticMesh* GetMesh() {return original->Mesh;}

	/** The mesh's material overrides.*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=Mesh)
	TArray<UMaterialInterface*> GetMaterialOverrides() {return original->MaterialOverrides;}

	/** Scale of the control point mesh */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=Mesh)
	FVector GetMeshScale() {return original->MeshScale;}
	
	/** Whether the control point mesh is set to cast shadows */
	UFUNCTION(BlueprintCallable, BlueprintPure,  Category=LandscapeSplineMeshes)
	bool GetShouldCastShadow() {return original->bCastShadow;}

	/** Whether the control point mesh is hidden in game */
	UFUNCTION(BlueprintCallable, BlueprintPure,  Category = LandscapeSplineMeshes)
	bool GetHiddenInGame() {return original->bHiddenInGame;}
	

	void Init(ULandscapeSplineControlPoint* orig, FTransform worldTransform)
	{
		this->original = orig;
		WorldTransform = worldTransform;
	};

	ULandscapeControlPointWrapper() {}

private:
	ULandscapeSplineControlPoint* original = nullptr;
	FTransform WorldTransform = FTransform::Identity;
	
	
};
