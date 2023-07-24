// Copyright Epic Games, Inc. All Rights Reserved.

#include "LandscapeSplineHelperPluginBPLibrary.h"

#include "Landscape.h"
#include "LandscapeSplineHelperPlugin.h"
#include "LandscapeSplinesComponent.h"
#include "Overrides/UBlueprintableLandscapeSplineControlPoint.h"
#include "Overrides/UBlueprintableLandscapeSplineSegment.h"

ULandscapeSplineHelperPluginBPLibrary::ULandscapeSplineHelperPluginBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

FLandsapeSpline ULandscapeSplineHelperPluginBPLibrary::GetLandscapeSpline(ALandscapeProxy* landscape)
{
	auto spline = landscape->GetSplinesComponent();
	
	// Turn segments into blueprint readable format (Kinda inefficient. Perhaps improve later)
	auto typedSegments = TArray<UBlueprintableLandscapeSplineSegment*>();
	for (auto segment : spline->GetSegments())
	{
		auto typedSegment = NewObject<UBlueprintableLandscapeSplineSegment>();
		typedSegment->Copy(segment);
		typedSegments.Add(typedSegment);
	}
	
	// Turn points into blueprint readable format.
	auto typedPoints = TArray<UBlueprintableLandscapeSplineControlPoint*>();
	for (auto point : spline->GetControlPoints())
	{
		auto typedPoint = NewObject<UBlueprintableLandscapeSplineControlPoint>();
		typedPoint->Copy(point);
		typedPoints.Add(typedPoint);
	}
	
	auto landscapeSpline = FLandsapeSpline();
	landscapeSpline.Segments = typedSegments;
	landscapeSpline.ControlPoints = typedPoints;
	return landscapeSpline;
}


