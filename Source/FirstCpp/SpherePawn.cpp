// Fill out your copyright notice in the Description page of Project Settings.


#include "SpherePawn.h"

//#include "Classes/Components/InputComponent.h"
//#include "Classes/GameFramework/FloatingPawnMovement.h"
//#include "Classes/Camera/CameraComponent.h"

// Sets default values
ASpherePawn::ASpherePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	floatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");

	Camera = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	Camera->SetRelativeLocation(FVector(-500.f, 0.f, 0.f));
	Camera->SetupAttachment(StaticMesh);

	SetRootComponent(StaticMesh);

}

// Called when the game starts or when spawned
void ASpherePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpherePawn::MoveForward(float amount)
{
	floatingPawnMovement->AddInputVector(GetActorForwardVector() * amount);
}

void ASpherePawn::MoveRight(float amount)
{
	floatingPawnMovement->AddInputVector(GetActorRightVector() * amount);
}

// Called every frame
void ASpherePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpherePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASpherePawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASpherePawn::MoveRight);

}

