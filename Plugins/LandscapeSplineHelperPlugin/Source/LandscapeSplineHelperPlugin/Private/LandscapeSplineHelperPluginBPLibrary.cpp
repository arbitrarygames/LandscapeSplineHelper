// Copyright 2023 Arbitrary Games. All rights reserved.

#include "LandscapeSplineHelperPluginBPLibrary.h"

#include "Landscape.h"
#include "LandscapeSplineActor.h"
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
		if (const auto Spline = landscape->GetSplinesComponent())
		{
			landscapeSpline = NewObject<ULandscapeSpline>();
			const bool s = landscapeSpline->Init(Spline, landscape->GetTransform());
			success = s;
			return;
		}
		success = false;
	}
}

void ULandscapeSplineHelperPluginBPLibrary::WrapLandscapeSplineActor(ULandscapeSpline*& landscapeSpline, bool& success, const ALandscapeSplineActor* actor)
{
	if(actor)
	{
		if (const auto Spline = actor->GetSplinesComponent())
		{
			landscapeSpline = NewObject<ULandscapeSpline>();
			const bool s = landscapeSpline->Init(Spline, actor->GetTransform());
			success = s;
			return;
		}
		success = false;
	}
}


