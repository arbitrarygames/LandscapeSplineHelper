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
	UPROPERTY(BlueprintReadWrite)
	TArray<ULandscapeControlPointWrapper*> ControlPoints;

	UPROPERTY(BlueprintReadWrite)
	TArray<USplineSegmentWrapper*> Segments;

	/* Copies landscape spline to a blueprint readable format. Returns true if successful, false if error. */
	bool Init(ULandscapeSplinesComponent* original, FTransform worldTransform);

	ULandscapeSpline() { }

private:
	ULandscapeSplinesComponent* original;

	static void ThrowBadPointerError();
};
