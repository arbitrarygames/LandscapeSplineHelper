#pragma once
#include "LandscapeSplineControlPoint.h"

#include "UBlueprintableLandscapeSplineControlPoint.generated.h"

UCLASS()
class UBlueprintableLandscapeSplineControlPoint : public ULandscapeSplineControlPoint
{
	GENERATED_BODY()
public:
	/** Location in Landscape-space */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSpline)
	FVector GetRelativeLocation() {return Location;}

	/** Rotation of tangent vector at this point (in landscape-space) */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSpline)
	FRotator GetRelativeRotation() {return Rotation;}

	/** Location in world space */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSpline)
	FVector GetWorldLocation() {return Location + WorldTransform.GetLocation();}

	/** Rotation of tangent vector at this point (in world-space) */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSpline)
	FRotator GetWorldRotation() {return Rotation + WorldTransform.GetRotation().Rotator();}
	
	/** Half-Width of the spline at this point. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSpline, meta = (DisplayName = "Half-Width"))
	float GetWidth() {return Width;}

	/** Layer Width ratio of the spline at this point. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = LandscapeSpline)
	float GetLayerWidthRatio() { return LayerWidthRatio; }

	/** Falloff at the sides of the spline at this point. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSpline)
	float GetSideFalloff() {return SideFalloff;}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = LandscapeSpline, meta=(UIMin = 0, ClampMin = 0, UIMax = 1, ClampMax = 1))
	float GetLeftSideFalloffFactor() { return LeftSideFalloffFactor; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = LandscapeSpline, meta = (UIMin = 0, ClampMin = 0, UIMax = 1, ClampMax = 1))
	float GetRightSideFalloffFactor() { return RightSideFalloffFactor; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = LandscapeSpline, meta = (UIMin = 0, ClampMin = 0, UIMax = 1, ClampMax = 1))
	float GetLeftSideLayerFalloffFactor() { return LeftSideLayerFalloffFactor; }

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = LandscapeSpline, meta = (UIMin = 0, ClampMin = 0, UIMax = 1, ClampMax = 1))
	float GetRightSideLayerFalloffFactor() { return RightSideLayerFalloffFactor; }

	/** Falloff at the start/end of the spline (if this point is a start or end point, otherwise ignored). */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSpline)
	float GetEndFalloff() {return EndFalloff;}
	
	/** Vertical offset of the spline segment mesh.  */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSpline, meta=(DisplayName="Mesh Vertical Offset"))
	float GetSegmentMeshOffset() {return SegmentMeshOffset;}
	
	/** Whether or not the terrain will raise to the level of the spline if the spline is above the terrain. */
	UFUNCTION(BlueprintCallable, BlueprintPure, BlueprintReadOnly, Category=LandscapeDeformation)
	bool GetShouldRaiseTerrain() {return bRaiseTerrain;}

	/** Whether or not the terrain will lower to the level of the spline if the spline is below the terrain.  */
	UFUNCTION(BlueprintCallable, BlueprintPure, BlueprintReadOnly, Category=LandscapeDeformation)
	bool GetShouldLowerTerrain() {return bLowerTerrain;}

	/** The mesh on this control point */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=Mesh)
	UStaticMesh* GetMesh() {return Mesh;}

	/** The mesh's material overrides.*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=Mesh)
	TArray<UMaterialInterface*> GetMaterialOverrides() {return MaterialOverrides;}

	/** Scale of the control point mesh */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=Mesh)
	FVector GetMeshScale() {return MeshScale;}
	
	/** Whether the control point mesh is set to cast shadows */
	UFUNCTION(BlueprintCallable, BlueprintPure, BlueprintReadOnly, Category=LandscapeSplineMeshes)
	bool GetShouldCastShadow() {return bCastShadow;}

	/** Whether the control point mesh is hidden in game */
	UFUNCTION(BlueprintCallable, BlueprintPure, BlueprintReadOnly, Category = LandscapeSplineMeshes)
	bool GetHiddenInGame() {return bHiddenInGame;}
	

	void Init(FTransform worldTransform) {WorldTransform = worldTransform;};

	UBlueprintableLandscapeSplineControlPoint() {}

private:
	FTransform WorldTransform = FTransform::Identity;
	
};
