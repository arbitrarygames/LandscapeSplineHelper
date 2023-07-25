#pragma once
#include "FBlueprintableSplineSegmentConnection.h"
#include "FBlueprintableSplineMeshEntry.h"
#include "LandscapeSplineSegment.h"
#include "USplineSegmentWrapper.generated.h"

UCLASS()
class USplineSegmentWrapper : public UObject
{
	GENERATED_BODY()
public:
	// ------- Getters -------
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeDeformation)
	FName GetLayerName() {return GetOriginal()->LayerName;}

	/** Whether or not the terrain will raise to the level of the spline if the spline is above the terrain. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeDeformation)
	bool GetShouldRaiseTerrain() {return GetOriginal()->bRaiseTerrain;}

	/** Whether or not the terrain will lower to the level of the spline if the spline is below the terrain.  */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeDeformation)
	bool GetShouldLowerTerrain() {return GetOriginal()->bLowerTerrain;}
	
	/** Whether the Spline Meshes is set to cast shadows */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSplineMeshes)
	bool GetShouldCastShadow() {return GetOriginal()->bCastShadow;}

	/** Whether the mesh is hidden in game */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = LandscapeSplineMeshes)
	bool GetHiddenInGame() {return GetOriginal()->bHiddenInGame;}



	
	// ------- Stuff implemented in USplineSegmentWrapper.cpp -------
	void Init(ULandscapeSplineSegment* original, FTransform worldOffset);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSplineSegment)
	void GetConnections(bool forceReload, FBlueprintableSplineSegmentConnection& connection1, FBlueprintableSplineSegmentConnection& connection2);

	/** Spline meshes from this list are used in random order along the spline. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSplineMeshes)
	TArray<FBlueprintableSplineMeshEntry> GetSplineMeshes(bool forceReload);

	USplineSegmentWrapper() {}


private:
	ULandscapeSplineSegment* _segment = nullptr;
	void ConvertConnections();
	void ConvertMeshes();
	FTransform WorldOffset = FTransform::Identity;
	TArray<FBlueprintableSplineSegmentConnection> _connections;
	TArray<FBlueprintableSplineMeshEntry> _meshes;

	ULandscapeSplineSegment* GetOriginal()
	{
		if(_segment)
		{
			return _segment;
		}
		UE_LOG(LogTemp, Error, TEXT("Could not load segment from spline. Is the spline valid?"));
		return nullptr;
	}

};
