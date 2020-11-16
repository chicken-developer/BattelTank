// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyTankPlayerController.generated.h"

class ATank;
UCLASS()
class BATTELTANK_API AMyTankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ATank* GetControlledTank() const;
	
    virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere)
	float crossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float crossHairYLocation = 0.3333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;
private:
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;
	bool GetLookDirection(FVector2D screenLocation,FVector &lookDirection) const;
	bool GetLookVectorHitLocation(FVector lookDirection,FVector &hitLocation) const;
};
