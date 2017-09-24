// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController not possesing a tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController possesing %s."), *(ControlledTank->GetName()));
	}

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank not possesing a tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank possesing %s."), *(PlayerTank->GetName()));
	}

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("Player tick."));

	if (GetPlayerTank())
	{
		if (!GetControlledTank()) { return; }

		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//Fire at player tank
	}
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if(PlayerPawn)
		return Cast<ATank>(PlayerPawn);

	return nullptr;
}
