// Fill out your copyright notice in the Description page of Project Settings.


#include "UTHUB_CPP_Trabajo/Public/Teleporter.h"
#include "Components/AudioComponent.h"
#include "Components/BoxComponent.h"

void ATeleporter::BoxCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(TeleportActorClass))
	{
		TeleportActor(OtherActor);
	}
}

void ATeleporter::EnableTeleport(UNiagaraComponent* PSystem)
{
	CanTeleport = true;
	OtherTeleport->CanTeleport = true;
}

// Sets default values
ATeleporter::ATeleporter()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Creo el componente de la mesh
	TeleporterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Teleporter Mesh"));
	RootComponent = TeleporterMesh;

	// Creo la zona de deteccion del jugador
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Detection Zone"));
	BoxCollision->SetupAttachment(TeleporterMesh);
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::BoxCollisionBeginOverlap);

	// Punto exacto donde el jugador aparecera al teletransportarse
	SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Point"));
	SpawnPoint->SetupAttachment(TeleporterMesh);

	// Creo el componente de particulas
	NiagaraComp = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Teleport Particles"));
	NiagaraComp->SetupAttachment(TeleporterMesh);
	NiagaraComp->OnSystemFinished.AddDynamic(this, &ThisClass::EnableTeleport);

	// Creo el componente de audio
	AudioComp = CreateDefaultSubobject<UAudioComponent>(TEXT("Teleport Sound"));
	AudioComp->SetupAttachment(TeleporterMesh);
}

// Called when the game starts or when spawned
void ATeleporter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATeleporter::TeleportActor(AActor* TargetActor)
{
	if (TargetActor && OtherTeleport && CanTeleport)
	{
		// Impido teletransportarme para no quedarme en un bucle
		CanTeleport = false;
		OtherTeleport->CanTeleport = false;

		// Hago el teleport del actor
		TargetActor->SetActorLocation(OtherTeleport->SpawnPoint->GetComponentLocation());

		// Activo las particulas
		NiagaraComp->Activate();
		OtherTeleport->NiagaraComp->Activate();

		// Reproduzco el sonido
		AudioComp->Play();
	}
}

