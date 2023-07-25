#pragma once
#include "FSplineSegmentConnectionWrapper.h"
#include "FBlueprintableSplineMeshEntry.h"
#include "LandscapeSplineSegment.h"
#include "UBlueprintableLandscapeSplineSegment.generated.h"

UCLASS()
class USplineSegmentWrapper : public ULandscapeSplineSegment
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSplineSegment)
	TArray<FSplineSegmentConnectionWrapper> GetConnections()
	{
		TArray<FSplineSegmentConnectionWrapper> ret;
		for (int i = 0; i < 2; i++)
		{
			auto connection = Connections[i];
			// Since this is a struct, we need to copy it because blueprints don't allow getters on structs.
			auto newConn = NewObject<FSplineSegmentConnectionWrapper>();
			newConn->Copy(connection);
			ret.Add(Connections[i]);
		}
		return ret;
	};
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeDeformation)
	FName LayerName;

	/** Whether or not the terrain will raise to the level of the spline if the spline is above the terrain. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeDeformation)
	bool ShouldRaiseTerrain;

	/** Whether or not the terrain will lower to the level of the spline if the spline is below the terrain.  */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeDeformation)
	bool ShouldLowerTerrain;

	/** Spline meshes from this list are used in random order along the spline. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSplineMeshes)
	TArray<FBlueprintableSplineMeshEntry> SplineMeshes;

	
	/** Whether the Spline Meshes is set to cast shadows */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category=LandscapeSplineMeshes)
	bool ShouldCastShadow;

	/** Whether the mesh is hidden in game */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = LandscapeSplineMeshes)
	bool HiddenInGame;

	void Init(FTransform worldOffset)
	{
		this->worldOffset = worldOffset;
	}
	USplineSegmentWrapper() {}

private:
	FTransform worldOffset = FTransform::Identity;
};
