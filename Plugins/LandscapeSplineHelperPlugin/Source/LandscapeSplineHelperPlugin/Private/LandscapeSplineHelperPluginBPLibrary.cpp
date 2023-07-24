// Copyright Epic Games, Inc. All Rights Reserved.

#include "LandscapeSplineHelperPluginBPLibrary.h"

#include "Landscape.h"
#include "LandscapeSplineHelperPlugin.h"
#include "LandscapeSplinesComponent.h"
#include "Overrides/UBlueprintableLandscapeSplineSegment.h"

ULandscapeSplineHelperPluginBPLibrary::ULandscapeSplineHelperPluginBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

FLandsapeSpline ULandscapeSplineHelperPluginBPLibrary::GetLandscapeSpline(ALandscapeProxy* landscape)
{
	auto splines = landscape->GetSplinesComponent();
	auto segments = splines->GetSegments();
	auto points = splines->GetControlPoints();
	auto typedSegments = TArray<UBlueprintableLandscapeSplineSegment*>();
	for (auto segment : segments)
	{
		auto typedSegment = NewObject<UBlueprintableLandscapeSplineSegment>();
		typedSegment->Copy(segment);
		typedSegments.Add(typedSegment);
	}
	auto landscapeSpline = FLandsapeSpline();
	landscapeSpline.Segments = typedSegments;
	landscapeSpline.ControlPoints = points;
	return landscapeSpline;
}

