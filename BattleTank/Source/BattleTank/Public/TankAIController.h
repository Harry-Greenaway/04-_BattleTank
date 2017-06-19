// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float ProximityRadius = 2000.f; //How close the tank can get to the player


private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

};
