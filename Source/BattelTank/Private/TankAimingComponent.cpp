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
		MoveBarrelTowards(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection){
	if (!MyTankBarrel) {
		return;
	}
	auto BarrelRotator = MyTankBarrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	MyTankBarrel->Elevate(DeltaRotator.Pitch);
	if (FMath::Abs(DeltaRotator.Yaw) < 180) {
		MyTankTurret->Rotate(DeltaRotator.Yaw);
	} else {
		MyTankTurret->Rotate(-DeltaRotator.Yaw);
	}
}


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent(){
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankAimingComponent::BeginPlay(){
	Super::BeginPlay();
}

void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

