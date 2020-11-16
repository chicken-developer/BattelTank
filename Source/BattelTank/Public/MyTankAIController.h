// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyTankAIController.generated.h"

class ATank;
UCLASS()
class BATTELTANK_API AMyTankAIController : public AAIController
{
public:
	GENERATED_BODY()
	void BeginPlay() override;
	void Tick(float DeltaSeconds) override;
	ATank* GetControlledTank() const;
private:
	ATank* GetPlayerControlledTank() const;
	FVector GetPlayerTankLocation() const;

};
