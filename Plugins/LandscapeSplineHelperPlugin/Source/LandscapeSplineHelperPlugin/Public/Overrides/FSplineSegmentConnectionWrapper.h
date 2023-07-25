#pragma once
#include "UBlueprintableLandscapeSplineControlPoint.h"
USTRUCT(BlueprintType)
struct FSplineSegmentConnectionWrapper
{
	GENERATED_BODY()

	// Control point connected to this end of the segment
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSplineSegmentConnection)
	UBlueprintableLandscapeSplineControlPoint* ControlPoint;

	// Tangent length of the connection
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSplineSegmentConnection)
	float TangentLen;

	// Socket on the control point that we are connected to
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSplineSegmentConnection)
	FName SocketName;

	void Copy(FLandscapeSplineSegmentConnection original, FTransform worldOffset)
	{
		TangentLen = original.TangentLen;
		SocketName = original.SocketName;
		const auto controlPoint = NewObject<UBlueprintableLandscapeSplineControlPoint>();
		controlPoint->Init(original.ControlPoint, worldOffset.GetLocation(), worldOffset.GetRotation().Rotator());
	}
};
