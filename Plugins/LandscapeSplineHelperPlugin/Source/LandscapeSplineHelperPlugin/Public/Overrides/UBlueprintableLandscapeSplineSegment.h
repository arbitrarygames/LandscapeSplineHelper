#pragma once
#include "FBlueprintableSplineMeshEntry.h"
#include "LandscapeSplineSegment.h"
#include "UBlueprintableLandscapeSplineSegment.generated.h"

UCLASS()
class UBlueprintableLandscapeSplineSegment : public UObject
{
	GENERATED_BODY()
public:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeDeformation)
	FName LayerName;

	/** Whether or not the terrain will raise to the level of the spline if the spline is above the terrain. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeDeformation)
	bool ShouldRaiseTerrain;

	/** Whether or not the terrain will lower to the level of the spline if the spline is below the terrain.  */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeDeformation)
	bool ShouldLowerTerrain;

	/** Spline meshes from this list are used in random order along the spline. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSplineMeshes)
	TArray<FBlueprintableSplineMeshEntry> SplineMeshes;

	
	/** Whether the Spline Meshes is set to cast shadows */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=LandscapeSplineMeshes)
	bool ShouldCastShadow;

	/** Whether the mesh is hidden in game */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = LandscapeSplineMeshes)
	bool HiddenInGame;

	UBlueprintableLandscapeSplineSegment(ULandscapeSplineSegment* original)
	{
		Copy(original);
	}

	void Copy(ULandscapeSplineSegment* original)
	{
		// Copy all properties
		LayerName = original->LayerName;
		ShouldRaiseTerrain = original->bRaiseTerrain == 1;
		ShouldLowerTerrain = original->bLowerTerrain == 1;
		SplineMeshes = TranslateSplineMeshes(original->SplineMeshes);
		ShouldCastShadow = original->bCastShadow == 1;
		HiddenInGame = original->bHiddenInGame == 1;
	}
	UBlueprintableLandscapeSplineSegment() {}

private:
	TArray<FBlueprintableSplineMeshEntry> TranslateSplineMeshes(TArray<FLandscapeSplineMeshEntry> arr)
	{
		TArray<FBlueprintableSplineMeshEntry> ret;
		for (const auto mesh : arr)
		{
			ret.Add(FBlueprintableSplineMeshEntry(mesh));
		}
		return ret;
	}	
};
