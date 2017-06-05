// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elavate(float RelativeSpeed) {
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed,-1,1);
	auto ElavationChange = RelativeSpeed *MaxDegreesPerSecond *GetWorld()->DeltaTimeSeconds;
	auto RawNewElavation = RelativeRotation.Pitch + ElavationChange;
	auto Elavation = FMath::Clamp<float>(RawNewElavation, MinElavation, MaxElavation);
	SetRelativeRotation(FRotator(Elavation, 0, 0));

}


