// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"

#include "Kismet/GameplayStatics.h"

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* barrelToSet){
	barrel = barrelToSet;
}


void UTankAimingComponent::AimAt(FVector worldObjectLocation, float launchSpeed, FString objectName) {
	if(!barrel){
		return;
	}
	FVector OutLaunchVelocity;
	FVector StartLocation = barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		worldObjectLocation,
		launchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if(bHaveAimSolution){
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		MoveBarrelTowards(AimDirection);
		UE_LOG(LogTemp, Warning, TEXT("%s aiming at: %s"),*TankName, *AimDirection.ToString());
	}
	

}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection){
	//TODO: Move barrel here
	auto BarrelRotator = barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	UE_LOG(LogTemp, Warning, TEXT("Aiming as rotator: %s"), *AimAsRotator.ToString());
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

