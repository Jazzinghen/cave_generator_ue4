// Copyright (c) 2020 Michele "Jazzinghen" Bianchi

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Containers/Array.h"
#include "CoreMinimal.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/Actor.h"

#include "CaveActor.generated.h"

UCLASS()
class CAVGEN_API ACaveActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACaveActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

#ifdef WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& event) override;
#endif

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Basic",
		meta = (ClampMin = "3.0", ClampMax = "128.0", UIMin = "3.0", UIMax = "128.0"))
	int width;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Basic",
		meta = (ClampMin = "3.0", ClampMax = "128.0", UIMin = "3.0", UIMax = "128.0"))
	int height;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Basic")
	UStaticMesh* wall_mesh;

private:
	UPROPERTY()
	TArray<UStaticMeshComponent*> walls_;
};
