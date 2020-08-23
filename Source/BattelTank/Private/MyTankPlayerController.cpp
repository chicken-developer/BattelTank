// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTankPlayerController.h"

ATank* AMyTankPlayerController::GetControlledTank() const {
	return static_cast<ATank*>(GetPawn());
}

void AMyTankPlayerController::AimTowardsCrosshair(){
	UE_LOG(LogTemp, Warning, TEXT("Tick of my tank controller"));
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
	// AimTowardsCrosshair();

	UE_LOG(LogTemp, Warning, TEXT("Tick of my tank controller"));

}
