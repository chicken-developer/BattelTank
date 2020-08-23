// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyTankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTELTANK_API AMyTankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ATank* GetControlledTank() const;
	
    virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	void AimTowardsCrosshair();
};