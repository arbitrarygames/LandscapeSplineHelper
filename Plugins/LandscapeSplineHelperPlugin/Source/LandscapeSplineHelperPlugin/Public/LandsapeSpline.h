// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LandscapeSplineSegment.h"
#include "UObject/Object.h"
#include "LandsapeSpline.generated.h"

class UBlueprintableLandscapeSplineSegment;
class ULandscapeSplineControlPoint;
/**
 * 
 */
USTRUCT(BlueprintType)
struct LANDSCAPESPLINEHELPERPLUGIN_API FLandsapeSpline
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite)
	TArray<ULandscapeSplineControlPoint*> ControlPoints;

	UPROPERTY(BlueprintReadWrite)
	TArray<UBlueprintableLandscapeSplineSegment*> Segments;


	FLandsapeSpline()
	{
		
	}
};
