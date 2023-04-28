// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantPot.h"

// Sets default values
APlantPot::APlantPot()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlantPot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlantPot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlantPot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}
