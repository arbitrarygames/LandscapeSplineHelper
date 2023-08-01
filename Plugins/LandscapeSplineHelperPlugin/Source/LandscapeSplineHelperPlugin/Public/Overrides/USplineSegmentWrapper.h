// Copyright 2023 Arbitrary Games. All rights reserved.
#pragma once
#include "FBlueprintableSplineSegmentConnection.h"
#include "LandscapeSplineSegment.h"
#include "USplineSegmentWrapper.generated.h"

UCLASS()
class USplineSegmentWrapper : public UObject
{
	GENERATED_BODY()
public:
	// ------- Stuff implemented in USplineSegmentWrapper.cpp -------
	void Init(ULandscapeSplineSegment* original, FTransform worldOffset);

	/* Get the connections on this segment. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSplineSegment)
	void GetConnections(bool forceReload, FBlueprintableSplineSegmentConnection& connection1, FBlueprintableSplineSegmentConnection& connection2);
	
	USplineSegmentWrapper() {}


private:
	ULandscapeSplineSegment* _segment = nullptr;
	void ConvertConnections();
	FTransform WorldOffset = FTransform::Identity;
	TArray<FBlueprintableSplineSegmentConnection> _connections;

	ULandscapeSplineSegment* GetOriginal() const
	{
		if(_segment)
		{
			return _segment;
		}
		UE_LOG(LogTemp, Error, TEXT("Could not load segment from spline. Is the spline valid?"));
		return nullptr;
	}

};
