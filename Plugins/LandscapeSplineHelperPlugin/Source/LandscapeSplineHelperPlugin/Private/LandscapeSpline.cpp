﻿// Copyright 2023 Arbitrary Games. All rights reserved.


#include "LandscapeSpline.h"

#include "Overrides/USplineSegmentWrapper.h"



bool ULandscapeSpline::Init(ULandscapeSplinesComponent* orig, FTransform worldTransform)
{
	this->original = orig;
	// It's better to parse through right away so that it doesn't happen multiple times. Further down the hierarchy, lazy loading is preferred.
	for(auto segment : original->GetSegments())
	{
		auto splineSegment = NewObject<USplineSegmentWrapper>();
		splineSegment->Init(segment, worldTransform);
		Segments.Add(splineSegment);
	}
	for(auto point : original->GetControlPoints())
	{
		auto wrapper = NewObject<ULandscapeControlPointWrapper>();
		wrapper->Init(point, original->GetComponentTransform());
		ControlPoints.Add(wrapper);
	}
	
	return true;
}

void ULandscapeSpline::ThrowBadPointerError()
{
	UE_LOG(LogTemp, Error, TEXT("Could not load spline from landscape. Did you forget to plug in landscape?"));
}
