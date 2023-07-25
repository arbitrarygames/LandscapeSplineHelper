// Fill out your copyright notice in the Description page of Project Settings.


#include "LandscapeSpline.h"

#include "Overrides/USplineSegmentWrapper.h"
/*
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
*/

bool ULandscapeSpline::Init(ULandscapeSplinesComponent* orig, FTransform worldTransform)
{
	this->original = orig;
	// It's better to parse through right away so that it doesn't happen multiple times. Further down the hierarchy, lazy loading is preferred.
	for(auto segment : original->GetSegments())
	{
		
		auto splineSegment = NewObject<USplineSegmentWrapper>();
		splineSegment->Init(segment, worldTransform);
		Segments.Add(splineSegment);
		auto connectedPoints = splineSegment->GetConnections(false);
		for(auto point : connectedPoints)
		{
			ConnectedPoints.Add(point.ControlPoint);
		}
	}
	return true;
}

void ULandscapeSpline::ThrowBadPointerError()
{
	UE_LOG(LogTemp, Error, TEXT("Could not load spline from landscape. Did you forget to plug in landscape?"));
}
