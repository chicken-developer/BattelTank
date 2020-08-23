// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTankAIController.h"

void AMyTankAIController::BeginPlay() {
	Super::BeginPlay();
	auto controlledTank = GetControlledTank();
	if (!controlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Not found a AI tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI tank: %s "), *controlledTank->GetName());
	}
	
	auto playerTankController = GetPlayerControlledTank();
	if (!playerTankController) {
		UE_LOG(LogTemp, Warning, TEXT("Not found player tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Found player tank from AI %s: %s "), *controlledTank->GetName(), *playerTankController->GetName());

	}
}


ATank* AMyTankAIController::GetControlledTank() const {
	return static_cast<ATank*>(GetPawn());
}

ATank* AMyTankAIController::GetPlayerControlledTank() const{
	//playerTankController -> that is  player controller, not a tank
	return static_cast<ATank*> (GetWorld()->GetFirstPlayerController()->GetPawn());
}

