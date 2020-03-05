// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AutoProceduralMeshComponent.h"
#include "RSEPortalMeshComponent.generated.h"

/**
 * 
 */
UCLASS()
class RAINBOWREDUX_API URSEPortalMeshComponent : public UAutoProceduralMeshComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal")
	int32 roomA;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Portal")
	int32 roomB;
};
