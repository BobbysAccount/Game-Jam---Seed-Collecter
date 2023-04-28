// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/AudioComponent.h"

#include "MainPlantPot.generated.h"

UCLASS()
class SEEDCOLLECTOR_API AMainPlantPot : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMainPlantPot();

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
		TSubclassOf<AActor> ActorToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent* CollisionBox;

	UPROPERTY(EditAnywhere)
		class USoundBase* SpawnSound;

	UPROPERTY(EditAnywhere)
		class USoundBase* GameMusic;
	
	UFUNCTION()
		void SpawnSeeds();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Handles the delay between seeds spawning
	FTimerHandle SpawnerTimerHandle;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 TotalMoney;

	void Counter();

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:

	void MoveRight(float AxisValue);

	FVector MovementDirection; 

	UPROPERTY(EditAnywhere, Category = "Movement")
		float MovementSpeed = 500.0f; 
};
