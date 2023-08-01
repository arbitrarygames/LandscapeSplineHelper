// Copyright 2023 Arbitrary Games. All rights reserved.
#include "Overrides/USplineSegmentWrapper.h"

void USplineSegmentWrapper::GetConnections(bool forceReload, FBlueprintableSplineSegmentConnection& connection1, FBlueprintableSplineSegmentConnection& connection2)
{
	// I don't think it's possible for the splines to change at runtime but just in case
	if (forceReload)
	{
		ConvertConnections();
	}
	connection1 = _connections[0];
	connection2 = _connections[1];
}


void USplineSegmentWrapper::Init(ULandscapeSplineSegment* original, FTransform worldOffset)
{
	_segment = original;
	this->WorldOffset = worldOffset;
	ConvertConnections();
}

void USplineSegmentWrapper::ConvertConnections()
{
	_connections.Empty();
	for (int i = 0; i < 2; i++)
	{
		_connections.Add(FBlueprintableSplineSegmentConnection(GetOriginal()->Connections[i], WorldOffset));
	}
}

