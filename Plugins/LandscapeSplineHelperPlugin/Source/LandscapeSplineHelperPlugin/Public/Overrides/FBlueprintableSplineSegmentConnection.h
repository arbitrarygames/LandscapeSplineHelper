#pragma once
#include "ULandscapeControlPointWrapper.h"
#include "FBlueprintableSplineSegmentConnection.generated.h"

USTRUCT(BlueprintType)
struct FBlueprintableSplineSegmentConnection
{
	GENERATED_BODY()

	// Control point connected to this end of the segment
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSplineSegmentConnection)
	ULandscapeControlPointWrapper* ControlPoint;

	// Tangent length of the connection
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSplineSegmentConnection)
	float TangentLen;

	// Socket on the control point that we are connected to
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSplineSegmentConnection)
	FName SocketName;
	

	FBlueprintableSplineSegmentConnection()
	{
		ControlPoint = nullptr;
		TangentLen = 0;
		SocketName = "";
	}
	
	FBlueprintableSplineSegmentConnection(FLandscapeSplineSegmentConnection original, FTransform worldOffset)
	{
		TangentLen = original.TangentLen;
		SocketName = original.SocketName;
		ControlPoint = NewObject<ULandscapeControlPointWrapper>();
		ControlPoint->Init(original.ControlPoint, worldOffset);
	}
};
