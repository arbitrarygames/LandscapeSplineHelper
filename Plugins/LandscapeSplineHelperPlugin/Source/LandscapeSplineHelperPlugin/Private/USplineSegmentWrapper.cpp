#include "Overrides/USplineSegmentWrapper.h"

TArray<FBlueprintableSplineSegmentConnection> USplineSegmentWrapper::GetConnections(bool forceReload)
{
	// I don't think it's possible for the splines to change at runtime but just in case
	if (forceReload)
	{
		ConvertConnections();
	}
	return _connections;
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
		_connections.Add(FBlueprintableSplineSegmentConnection(_segment->Connections[i], WorldOffset));
	}
}

void USplineSegmentWrapper::ConvertMeshes()
{
	if(_segment)
	{
		_meshes.Empty();
		for (const auto mesh : _segment->SplineMeshes)
		{
			_meshes.Add(FBlueprintableSplineMeshEntry(mesh));
		}
	}
	else
	{
		
	}
}
