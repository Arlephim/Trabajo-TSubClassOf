// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NiagaraComponent.h"
#include "Teleporter.generated.h"

class UBoxComponent;

UCLASS()
class UTHUB_CPP_TRABAJO_API ATeleporter : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void EnableTeleport(UNiagaraComponent* PSystem);
	// Sets default values for this actor's properties
	ATeleporter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	UPROPERTY(EditAnywhere, Category="Teleporter")
	TSubclassOf<AActor> TeleportActorClass;

	UPROPERTY(EditAnywhere, Category="Teleporter")
	ATeleporter* OtherTeleport;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Teleporter")
	UBoxComponent* BoxCollision;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Teleporter")
	UStaticMeshComponent* TeleporterMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Teleporter")
	USceneComponent* SpawnPoint;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Teleporter")
	UNiagaraComponent* NiagaraComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Teleporter")
	UAudioComponent* AudioComp;

	UFUNCTION()
	void BoxCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void TeleportActor(AActor* TargetActor);

private:

	bool CanTeleport = true;
	
};
