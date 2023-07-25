// Copyright Epic Games, Inc. All Rights Reserved.

#include "LandscapeSplineHelperPluginBPLibrary.h"

#include "Landscape.h"
#include "LandscapeSplinesComponent.h"
#include "Overrides/ULandscapeControlPointWrapper.h"
#include "Overrides/USplineSegmentWrapper.h"

ULandscapeSplineHelperPluginBPLibrary::ULandscapeSplineHelperPluginBPLibrary(
	const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void ULandscapeSplineHelperPluginBPLibrary::GetLandscapeSpline(ULandscapeSpline*& landscapeSpline, bool& success, const ALandscapeProxy* landscape)
{
	if (landscape)
	{
		auto spline = landscape->GetSplinesComponent();
		if (spline)
		{
			landscapeSpline = NewObject<ULandscapeSpline>();
			bool s = landscapeSpline->Init(spline, landscape->GetTransform());
			success = s;
			return;
		}
		success = false;
	}
}
