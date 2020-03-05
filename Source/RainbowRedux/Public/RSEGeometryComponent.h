// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "RainbowRedux.h"

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"

#include "AutoProceduralMeshComponent.h"

#include "RSEGeometryComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RAINBOWREDUX_API URSEGeometryComponent : public UAutoProceduralMeshComponent
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RSE Flags")
	bool bCollisionOnly;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RSE Flags")
	bool bHasRSEGeometryFlags;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RSE Flags")
	bool bGF_Climbable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RSE Flags")
	bool bGF_NoCollide2D;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RSE Flags")
	bool bGF_Invisible;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RSE Flags")
	bool bGF_Unknown2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RSE Flags")
	bool bGF_FloorPolygon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RSE Flags")
	bool bGF_NoCollide3D;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RSE Flags")
	bool bGF_Unknown4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RSE Flags")
	bool bGF_NotShownInPlan;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RSE Flags")
	bool bGunPass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RSE Flags")
	bool bGrenadePass;

	UFUNCTION(BlueprintCallable)
	void SetRSEGeometryFlags(bool bNewHasRSEGeometryFlags,
								bool bNewGF_Climbable,
								bool bNewGF_NoCollide2D,
								bool bNewGF_Invisible,
								bool bNewGF_Unknown2,
								bool bNewGF_FloorPolygon,
								bool bNewGF_NoCollide3D,
								bool bNewGF_Unknown4,
								bool bNewGF_NotShownInPlan);

	UFUNCTION(BlueprintCallable)
	void SetProjectilePassFlags(bool bNewGunPass,
								bool bNewGrenadePass);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RSE debug Flags")
	//debug flag that can be toggled. This will turn on visibility for all collidables, and turn off anything that isn't collidable
	bool bShowCollisionOnly;

public:	

	UFUNCTION(BlueprintCallable)
	void UpdateRSEFlagSettings();

	UFUNCTION(BlueprintCallable)
	void SetShowCollisionOnlyFlag(bool bNewValue);

	//Set mesh to block everything
	void BlockAll();
	//set mesh to ignore everything
	void IgnoreAll();

};
