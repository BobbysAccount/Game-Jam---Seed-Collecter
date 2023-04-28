// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlantPot.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AMainPlantPot::AMainPlantPot()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TheBoxComponent"));
	CollisionBox->SetBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	CollisionBox->SetCollisionProfileName(TEXT("Trigger"));
	RootComponent = CollisionBox;

	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AMainPlantPot::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &AMainPlantPot::OnOverlapEnd);

	TotalMoney = 0; 
}

// Called when the game starts or when spawned
void AMainPlantPot::BeginPlay()
{
	Super::BeginPlay();
	
	// Spawn Seeds timer
	GetWorld()->GetTimerManager().SetTimer(SpawnerTimerHandle, this, &AMainPlantPot::SpawnSeeds, 1.0f, true);

	// Play music 
	UGameplayStatics::PlaySound2D(GetWorld(), GameMusic);
}

// Called every frame
void AMainPlantPot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (!MovementDirection.IsZero())
	{
		const FVector NewLocation = GetActorLocation() + (MovementDirection * DeltaTime * MovementSpeed);
		SetActorLocation(NewLocation);
	}
}

// Called to bind functionality to input
void AMainPlantPot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMainPlantPot::MoveRight);
}

void AMainPlantPot::MoveRight(float AxisValue)
{
	MovementDirection.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f);
}

void AMainPlantPot::SpawnSeeds()
{
	// Generate a RandomNumber between -550 to 550
	float RandomY = FMath::FRandRange(-550.0f, 550.0f);

	FVector Loc = { 0.0f,RandomY,950.0f };
	FRotator Rot = { 0.0f,0.0f,0.0f };
	FActorSpawnParameters SpawnParams;
	AActor* SpawnActorRef = GetWorld()->SpawnActor<AActor>(ActorToSpawn, Loc, Rot, SpawnParams);

	UGameplayStatics::PlaySound2D(GetWorld(), SpawnSound);
	
}

void AMainPlantPot::Counter()
{
	TotalMoney++;
	UE_LOG(LogTemp, Warning, TEXT("Total money is: %i"), TotalMoney);
}

void AMainPlantPot::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FString ActorName = OtherActor->GetName();

	//UE_LOG(LogTemp, Warning, TEXT("Twat!! %s"), *ActorName);

	if (ActorName == "BP_MainPlantPot_C_0")
	{
		UE_LOG(LogTemp, Warning, TEXT("This is the FACKIN plant pot!!"));
	}

	else
	{
		Counter();
		OtherActor->Destroy();
	}

}

void AMainPlantPot::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//UE_LOG(LogTemp, Warning, TEXT("Fuckin WOOOOOW!!"));
}
