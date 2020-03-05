// Fill out your copyright notice in the Description page of Project Settings.

#include "RSEGeometryComponent.h"


void URSEGeometryComponent::SetRSEGeometryFlags(bool bNewHasRSEGeometryFlags, bool bNewGF_Climbable, bool bNewGF_NoCollide2D, bool bNewGF_Invisible, bool bNewGF_Unknown2, bool bNewGF_FloorPolygon, bool bNewGF_NoCollide3D, bool bNewGF_Unknown4, bool bNewGF_NotShownInPlan)
{
	bHasRSEGeometryFlags = bNewHasRSEGeometryFlags;
	bGF_Climbable = bNewGF_Climbable;
	bGF_NoCollide2D = bNewGF_NoCollide2D;
	bGF_Invisible = bNewGF_Invisible;
	bGF_Unknown2 = bNewGF_Unknown2;
	bGF_FloorPolygon = bNewGF_FloorPolygon;
	bGF_NoCollide3D = bNewGF_NoCollide3D;
	bGF_Unknown4 = bNewGF_Unknown4;
	bGF_NotShownInPlan = bNewGF_NotShownInPlan;
}

void URSEGeometryComponent::SetProjectilePassFlags(bool bNewGunPass, bool bNewGrenadePass)
{
	bGunPass = bNewGunPass;
	bGrenadePass = bNewGrenadePass;
}

void URSEGeometryComponent::UpdateRSEFlagSettings()
{
	//The channels used for guns and grenades
	ECollisionChannel GunProjectileChannel = ECollisionChannel::ECC_GameTraceChannel2;
	ECollisionChannel GrenadeProjectileChannel = ECollisionChannel::ECC_GameTraceChannel1;

	if (bHasRSEGeometryFlags == false)
	{
		//no flags are set for this object, so force visibility back to true, and ignore all collisions
		SetVisibility(true);
		//IgnoreAll();
		if (bGunPass)
		{
			SetCollisionResponseToChannel(GunProjectileChannel, ECR_Ignore);
		}
		if (bGrenadePass)
		{
			SetCollisionResponseToChannel(GrenadeProjectileChannel, ECR_Ignore);
		}
		return;
	}

	//Visibility
	bool bShouldBeVisible = true;
	if (bCollisionOnly)
	{
		bShouldBeVisible = false;
	}
	else
	{
		if (bGF_Invisible)
		{
			bShouldBeVisible = false;
		}
	}

	SetVisibility(bShouldBeVisible);
	
	bool bCollide = true;
	if (bCollisionOnly)
	{
		if (bGF_Invisible) // This flag disables this object for collision only objects
		{
			bCollide = false;
		}
	}

	if (!bGF_FloorPolygon && !bGF_Climbable && bGF_NoCollide2D)
	{
		bCollide = false;
	}

	if (bCollide)
	{
		BlockAll();
	}
	else
	{
		IgnoreAll();
	}

	if (bCollisionOnly)
	{
		if (bGF_Invisible) // This flag disables this object for collision only objects
		{
			//No more settings to perform on these types of geometry
			return;
		}
	}

	//Set nuance for gunpass or grenade pass
	//NoCollide3D should also allow guns and grenades through
	//NoCollide3D seems to only be used correctly if the surface is also invisible
	bool bNo3DCollision = bGF_NoCollide3D && bGF_Invisible;
	if (bGF_Invisible)
	{
		//In Rainbow Six, I believe all  invisible geometry should be gunpass and grenade pass, it's only to block player movement
		//TODO: Verify this behavior for Rogue Spear
		//TODO: Maybe make this only apply for geometry with no material set
		bGunPass = true;
		bGrenadePass = true;
	}
	if (bNo3DCollision || bGunPass)
	{
		SetCollisionResponseToChannel(GunProjectileChannel, ECR_Ignore);
	}
	else
	{
		SetCollisionResponseToChannel(GunProjectileChannel, ECR_Block);
	}
	if (bNo3DCollision || bGrenadePass)
	{
		SetCollisionResponseToChannel(GrenadeProjectileChannel, ECR_Ignore);
	}
	else
	{
		SetCollisionResponseToChannel(GrenadeProjectileChannel, ECR_Block);
	}

	//TODO: Add support for making gunpass enabled on masked materials in the sherman engine games
}

void URSEGeometryComponent::SetShowCollisionOnlyFlag(bool bNewValue)
{
	bShowCollisionOnly = bNewValue;
	UpdateRSEFlagSettings();
}

void URSEGeometryComponent::BlockAll()
{

	SetCollisionResponseToAllChannels(ECR_Block);
	if (bShowCollisionOnly)
	{
		SetVisibility(true);
	}
}

void URSEGeometryComponent::IgnoreAll()
{
	SetCollisionResponseToAllChannels(ECR_Ignore);
	if (bShowCollisionOnly)
	{
		SetVisibility(false);
	}
}

