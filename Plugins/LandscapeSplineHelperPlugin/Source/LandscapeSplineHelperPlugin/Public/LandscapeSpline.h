// Copyright 2023 Arbitrary Games. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Overrides/ULandscapeControlPointWrapper.h"
#include "UObject/Object.h"
#include "LandscapeSpline.generated.h"


class USplineSegmentWrapper;
class ULandscapeSplineControlPoint;
/**
 * 
 */
UCLASS(BlueprintType)
class LANDSCAPESPLINEHELPERPLUGIN_API ULandscapeSpline : public UObject
{
	GENERATED_BODY()
public:
	/* The control points that make up the spline. */
	UPROPERTY(BlueprintReadWrite, Category = "Landscape Spline")
	TArray<ULandscapeControlPointWrapper*> ControlPoints;

	/* The segments that make up the spline. */
	UPROPERTY(BlueprintReadWrite, Category = "Landscape Spline")
	TArray<USplineSegmentWrapper*> Segments;

	/* Copies landscape spline to a blueprint readable format. Returns true if successful, false if error. */
	bool Init(ULandscapeSplinesComponent* original, FTransform worldTransform);

	ULandscapeSpline() { }

private:
	ULandscapeSplinesComponent* original;

	static void ThrowBadPointerError();
};
