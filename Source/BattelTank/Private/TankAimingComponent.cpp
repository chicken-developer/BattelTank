// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* barrelToSet){
	barrel = barrelToSet;
}


void UTankAimingComponent::AimAt(FVector worldObjectLocation, float lauchSpeed, FString objectName) {
	auto barrelLocation = barrel->GetComponentLocation().ToString();
	// UE_LOG(LogTemp, Warning, TEXT("%s from %s aiming at: %s"), *objectName,*barrelLocation, *worldObjectLocation.ToString());
	UE_LOG(LogTemp, Warning, TEXT("Firing at: %f"), lauchSpeed);

}


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

