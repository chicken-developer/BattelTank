// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"

#include "MyTankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTELTANK_API AMyTankAIController : public AAIController
{
public:
	GENERATED_BODY()
	void BeginPlay() override;
	ATank* GetControlledTank() const;
private:
	ATank* GetPlayerControlledTank() const;

};
