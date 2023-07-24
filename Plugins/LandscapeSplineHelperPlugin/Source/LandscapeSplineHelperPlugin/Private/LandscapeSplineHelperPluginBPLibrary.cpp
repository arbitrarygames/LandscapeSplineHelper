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

void ULandscapeSplineHelperPluginBPLibrary::GetLandscapeSpline(FLandsapeSpline& landscapeSpline, bool& success, const ALandscapeProxy* landscape)
{
	if(landscape)
	{
		auto spline = landscape->GetSplinesComponent();
		if(spline)
		{
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
	
			landscapeSpline = FLandsapeSpline();
			landscapeSpline.Segments = typedSegments;
			landscapeSpline.ControlPoints = typedPoints;
			success = true;
			return;
		}
		success = false;
		return;
	}
}


