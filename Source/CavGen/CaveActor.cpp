// Copyright (c) 2020 Michele "Jazzinghen" Bianchi

#include "CaveActor.h"

#include "Containers/Array.h"
#include "Math/Vector2D.h"
#include "cave_lib/CaveLib.h"

// Sets default values
ACaveActor::ACaveActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACaveActor::BeginPlay()
{
	Super::BeginPlay();
}

#ifdef WITH_EDITOR
void ACaveActor::PostEditChangeProperty(struct FPropertyChangedEvent& event)
{
	Super::PostEditChangeGroperty(event);

	TArray<bool> maze_data = UCaveLib::GenerateCave(height, width);

	// Next: check the amount of "false" in the maze to know how many walls we need
	// then update the components list accordingly

	FVector2D next_cell_location(0.0f);

	// Next: unroll the maze to position the various walls.
	for (int)
}
#endif

// Called every frame
void ACaveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
