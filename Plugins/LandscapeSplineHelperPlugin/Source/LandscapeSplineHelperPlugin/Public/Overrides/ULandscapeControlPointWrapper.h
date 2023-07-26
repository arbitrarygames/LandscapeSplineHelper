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
	FVector GetWorldLocation() { return WorldTransform.TransformPositionNoScale(original->Location);}
	
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
