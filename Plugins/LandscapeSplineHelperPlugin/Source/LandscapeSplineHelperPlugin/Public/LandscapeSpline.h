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
	TArray<ULandscapeControlPointWrapper*> ConnectedPoints;

	UPROPERTY(BlueprintReadWrite)
	TArray<USplineSegmentWrapper*> Segments;

	/* Returns all points on the spline. Notice! In most use cases, you'd only want connected points (points that have a segment associated with them). If this is true in your case, use get ConnectedPoints instead.*/
//	UFUNCTION(BlueprintCallable, BlueprintPure)
//	TArray<UBlueprintableLandscapeSplineControlPoint*> GetAllPoints();

	/* Copies landscape spline to a blueprint readable format. Returns true if successful, false if error. */
	bool Init(ULandscapeSplinesComponent* original, FTransform worldTransform);

	ULandscapeSpline()
	{
		
	}

private:
	ULandscapeSplinesComponent* original;

	static void ThrowBadPointerError();
};
