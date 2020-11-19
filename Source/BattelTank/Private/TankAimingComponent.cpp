// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "TankTurret.h"
#include "TankBarrel.h"
#include "Kismet/GameplayStatics.h"

void UTankAimingComponent::SetBarrelReference(UTankBarrel* barrelToSet){
	if(!barrelToSet){
		return;
	}
	MyTankBarrel = barrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* turretToSet){
	if(!turretToSet){
		return;
	}
	MyTankTurret = turretToSet;
}


void UTankAimingComponent::AimAt(FVector worldObjectLocation, float launchSpeed, FString objectName) {
	if(!MyTankBarrel){
		return;
	}
	FVector OutLaunchVelocity;
	FVector StartLocation = MyTankBarrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		worldObjectLocation,
		launchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if(bHaveAimSolution){
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		MoveBarrelTowards(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection){
	auto BarrelRotator = MyTankBarrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	MyTankBarrel->Elevate(5);
	MyTankTurret->Rotate(5);
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

