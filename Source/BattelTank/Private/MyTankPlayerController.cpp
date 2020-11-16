// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTankPlayerController.h"
#include "Tank.h"

ATank* AMyTankPlayerController::GetControlledTank() const {
	return static_cast<ATank*>(GetPawn());
}

void AMyTankPlayerController::AimTowardsCrosshair(){
	if(!GetControlledTank()){
		return ; // If not found the tank 
	}
	FVector outHitLocation;
	if(GetSightRayHitLocation(outHitLocation)){
		GetControlledTank()->AimAt(outHitLocation);
	}

}

bool AMyTankPlayerController::GetSightRayHitLocation(FVector& outHitLocation) const{
	int32 screenXLocation, screenYLocation;
	GetViewportSize(screenXLocation, screenYLocation);
	auto screenSizeLocation = FVector2D(screenXLocation * crossHairXLocation, screenYLocation * crossHairYLocation);
	FVector  worldDirection;
	if(GetLookDirection(screenSizeLocation, worldDirection)){
		GetLookVectorHitLocation(worldDirection, outHitLocation);
	}
	return true;
}

bool AMyTankPlayerController::GetLookDirection(FVector2D screenLocation, FVector& lookDirection) const{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(
		screenLocation.X,
		screenLocation.Y,
		CameraWorldLocation,
		lookDirection);
}

bool AMyTankPlayerController::GetLookVectorHitLocation(FVector lookDirection, FVector &outHitLocation) const{
	FHitResult hitResult;
	auto startLocation = PlayerCameraManager->GetCameraLocation();
	auto endLocation = startLocation + (lookDirection * LineTraceRange);

	if(GetWorld()->LineTraceSingleByChannel(
		hitResult,
		startLocation,
		endLocation,
		ECollisionChannel::ECC_Visibility)){
		
		outHitLocation = hitResult.Location;
		return true;
	}
	outHitLocation = FVector(0);
	return false;
}


void AMyTankPlayerController::BeginPlay() {
	Super::BeginPlay();
	auto controlledTank = GetControlledTank();
	if (!controlledTank){
		UE_LOG(LogTemp, Warning, TEXT("Not found a player tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Controlled player tank: %s "), *controlledTank->GetName());
	}
}

void AMyTankPlayerController::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
	 AimTowardsCrosshair();

}
