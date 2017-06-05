// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Beginning Play"));

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player Controller has no tank"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possessing: %s"), *ControlledTank->GetName());
	}
}


void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardCrosshair() {
	if (!GetControlledTank()) {return;}

	FVector HitLocation; // OutParameter

	if (GetSightRayHitLocation(HitLocation)) {
		GetControlledTank()->AimAt(HitLocation);
	}
}

//Get World Location of linetrace through crosshairs, true if it hit landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const {
	//Find the crosshiarpos
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {
	FVector CameraLocation; //Tobe discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const {
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + LookDirection*LineTraceRange;

	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
			)
	{
		HitLocation = HitResult.Location;
		return true;
	} else {
		return false;
	}
}