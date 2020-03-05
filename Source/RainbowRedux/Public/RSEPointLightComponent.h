// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PointLightComponent.h"
#include "RSEPointLightComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, ClassGroup = (Lights, Common), hidecategories = (Object, LightShafts), editinlinenew, meta = (BlueprintSpawnableComponent))
class RAINBOWREDUX_API URSEPointLightComponent : public UPointLightComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Rendering|Lighting")
	void SetUseInverseSquaredFalloff(bool bNewUseInverseSquaredFalloff);

	UFUNCTION(BlueprintCallable, Category = "RSE Lights", meta = (WorldContext = "WorldContextObject"))
	static URSEPointLightComponent* CreateNewRSEPointLightComponent(UObject* WorldContextObject, AActor* ParentActor, FName LightName);
};
