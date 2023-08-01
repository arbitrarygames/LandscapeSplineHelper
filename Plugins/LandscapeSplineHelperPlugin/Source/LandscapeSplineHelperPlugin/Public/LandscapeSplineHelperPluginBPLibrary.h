// Copyright 2023 Arbitrary Games. All rights reserved.

#pragma once

#include "LandscapeSpline.h"
#include "Landscape.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LandscapeSplineHelperPluginBPLibrary.generated.h"

UCLASS()
class ULandscapeSplineHelperPluginBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	
	/* Returns a representation of the splines given by the landscape. */
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Get Landscape Spline", Keywords = "LandscapeSpline"), Category = "LandscapeSplineHelper")
	static void GetLandscapeSpline(ULandscapeSpline*& landscapeSpline, bool& success, const ALandscapeProxy* landscape);
	
};
