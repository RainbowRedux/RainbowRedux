// Fill out your copyright notice in the Description page of Project Settings.

#include "RSEPointLightComponent.h"
#include "RainbowRedux.h"

#include "EngineMinimal.h"
#include "Components/StaticMeshComponent.h"

void URSEPointLightComponent::SetUseInverseSquaredFalloff(bool bNewUseInverseSquaredFalloff)
{
	bUseInverseSquaredFalloff = bNewUseInverseSquaredFalloff;
}

URSEPointLightComponent* URSEPointLightComponent::CreateNewRSEPointLightComponent(UObject* WorldContextObject, AActor* ParentActor, FName LightName)
{
	if (ParentActor == nullptr)
	{
		UE_LOG(RSEComponents, Error, TEXT("Failed to spawn new RSE point light - parent not valid"));
		return nullptr;
	}

	UE_LOG(RSEComponents, Error, TEXT("Parent root component: %s"), *(ParentActor->GetRootComponent()->GetFullName()));

	UStaticMeshComponent* newComponent = NewObject<UStaticMeshComponent>(ParentActor, LightName);
	if (newComponent == nullptr)
	{
		UE_LOG(RSEComponents, Error, TEXT("Failed to spawn new RSE point light"));
		return nullptr;
	}
	
	newComponent->SetMobility(EComponentMobility::Movable);
	FAttachmentTransformRules newRules(EAttachmentRule::KeepRelative, true);
	newComponent->AttachTo(ParentActor->GetRootComponent());

	newComponent->RegisterComponent();

	UE_LOG(RSEComponents, Warning, TEXT("Light spawned 2"));

	return nullptr;
}
