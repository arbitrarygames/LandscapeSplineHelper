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

TArray<FBlueprintableSplineMeshEntry> USplineSegmentWrapper::GetSplineMeshes(bool forceReload)
{
	if (forceReload)
	{
		ConvertMeshes();
	}
	return _meshes;
}

void USplineSegmentWrapper::Init(ULandscapeSplineSegment* original, FTransform worldOffset)
{
	_segment = original;
	this->WorldOffset = worldOffset;
	ConvertConnections();
	ConvertMeshes();
}

void USplineSegmentWrapper::ConvertConnections()
{
	_connections.Empty();
	for (int i = 0; i < 2; i++)
	{
		_connections.Add(FBlueprintableSplineSegmentConnection(GetOriginal()->Connections[i], WorldOffset));
	}
}

void USplineSegmentWrapper::ConvertMeshes()
{
	_meshes.Empty();
	for (const auto mesh : GetOriginal()->SplineMeshes)
	{
		_meshes.Add(FBlueprintableSplineMeshEntry(mesh));
	}
}
