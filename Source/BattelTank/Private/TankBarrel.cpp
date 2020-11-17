// Fill out your copyright notice in the Description page of Project Settings.
#include "Engine/World.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed){
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto deltaTime = GetWorld()->DeltaTimeSeconds;
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * deltaTime;
	auto RawNewElevation = GetRelativeRotation().Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation,0,0));
	UE_LOG(LogTemp, Warning, TEXT("Enter Elevate function"));

}
	