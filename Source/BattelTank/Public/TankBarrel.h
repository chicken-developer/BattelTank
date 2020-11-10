// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTELTANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
		void Elevate(float DegreesPerSecond);
private:
	UPROPERTY(EditAnywhere, Category=SetUp)
	float MaxDegreesPerSecond = 20;

	UPROPERTY(EditAnywhere, Category = SetUp)
	float MaxElevationDegrees = 40; //TODO: Set 

	UPROPERTY(EditAnywhere, Category = SetUp)
	float MinElevationDegrees = 0; //TODO: Set
};
