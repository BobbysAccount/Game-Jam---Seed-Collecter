// Fill out your copyright notice in the Description page of Project Settings.

#include "Seed.h"
#include "Components/BoxComponent.h"

// Sets default values
ASeed::ASeed()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(32.0f, 32.0f, 32.0f));
	CollisionBox->SetCollisionProfileName(TEXT("Trigger"));
	RootComponent = CollisionBox;
}

// Called when the game starts or when spawned
void ASeed::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASeed::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

