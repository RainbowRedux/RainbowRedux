// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "AutoProceduralMeshComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class RAINBOWREDUX_API UAutoProceduralMeshComponent : public UProceduralMeshComponent
{
	GENERATED_BODY()
	
public:
	UAutoProceduralMeshComponent();

	/**
	 *	Create/replace a section for this procedural mesh component.
	 *	This function is deprecated for Blueprints because it uses the unsupported 'Color' type. Use new 'Create Mesh Section' function which uses LinearColor instead.
	 *	@param	SectionIndex		Index of the section to create or replace.
	 *	@param	Vertices			Vertex buffer of all vertex positions to use for this mesh section.
	 *	@param	Triangles			Index buffer indicating which vertices make up each triangle. Length must be a multiple of 3.
	 *	@param	Normals				Optional array of normal vectors for each vertex. If supplied, must be same length as Vertices array.
	 *	@param	UV0					Optional array of texture co-ordinates for each vertex. If supplied, must be same length as Vertices array.
	 *	@param	VertexColors		Optional array of colors for each vertex. If supplied, must be same length as Vertices array.
	 *	@param	Tangents			Optional array of tangent vector for each vertex. If supplied, must be same length as Vertices array.
	 *	@param	bCreateCollision	Indicates whether collision should be created for this section. This adds significant cost.
	 */
	UFUNCTION(BlueprintCallable, Category = "Components|ProceduralMesh", meta = (DisplayName = "Create Mesh Section FColor", AutoCreateRefTerm = "Normals,UV0,VertexColors,Tangents"))
		int32 AutoCreateMeshSection(const TArray<FVector>& Vertices, const TArray<int32>& Triangles, const TArray<FVector>& Normals, const TArray<FVector2D>& UV0, const TArray<FColor>& VertexColors, const TArray<FProcMeshTangent>& Tangents, bool bCreateCollision)
	{
		CreateMeshSection(NextMeshIdx, Vertices, Triangles, Normals, UV0, VertexColors, Tangents, bCreateCollision);
		NextMeshIdx++;

		return NextMeshIdx - 1;
	}

	UFUNCTION(BlueprintCallable)
		int32 GetLastCreatedMeshIndex()
	{
		return NextMeshIdx - 1;
	}

protected:
	int32 NextMeshIdx;
};
