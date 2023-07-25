// Fill out your copyright notice in the Description page of Project Settings.


#include "LandscapeSpline.h"

#include "Overrides/USplineSegmentWrapper.h"

TArray<UBlueprintableLandscapeSplineControlPoint*> ULandscapeSpline::GetAllPoints()
{
	if(original)
	{
		
	}
	else
	{
		ThrowBadPointerError();
	}
}

bool ULandscapeSpline::Init(ULandscapeSplinesComponent* original, FTransform worldTransform)
{
	this->original = original;
	for(auto segment : original->GetSegments())
	{
		// This isn't pretty but it's efficient and lets us avoid making an entirely new UObject for every single segment
		auto casted = static_cast<USplineSegmentWrapper*>(segment);
		casted->Init(worldTransform);
		Segments.Add(casted);
	}
	return true;
}

void ULandscapeSpline::ThrowBadPointerError()
{
	UE_LOG(LogTemp, Error, TEXT("Could not load spline from landscape. Did you forget to plug in landscape?"));
}
