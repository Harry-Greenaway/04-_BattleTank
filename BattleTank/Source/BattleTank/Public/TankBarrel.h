// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//-1 is max down, and +1 is max up movement
	void Elavate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 10.0f;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElavation = -2.0f;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElavation = 30.0f;
	
};
