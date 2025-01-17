// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank Track is used to set maximum driving force , and to apply forces to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Input")
		void SetThrottle(float Throttle);
	
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 400000;

	//Assume 40 tonne tank and 1 g acceleration

private:
	UTankTrack();
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction) override;
	void ApplySidewaysForce();
	virtual void BeginPlay() override;
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	void DriveTrack();
	float CurrentThrottle = 0;
};
