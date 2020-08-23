// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTankPlayerController.h"

ATank* AMyTankPlayerController::GetControlledTank() const {
	return static_cast<ATank*>(GetPawn());
}

void AMyTankPlayerController::AimTowardsCrosshair(){
	if(!GetControlledTank()){
		return ; // If not found the tank 
	}
	FVector HitLocation;
	if(GetSightRayHitLocation(HitLocation)){
		// UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString());
	}

}

bool AMyTankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const{
	OutHitLocation = FVector(1.0);
	int32 screenXLocation, screenYLocation;
	GetViewportSize(screenXLocation, screenYLocation);
	auto screenSizeLocation = FVector2D(screenXLocation * crossHairXLocation, screenYLocation * crossHairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("Screen location: %s"), *screenSizeLocation.ToString());
	return true;
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
