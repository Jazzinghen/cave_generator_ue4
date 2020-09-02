// Copyright (c) 2020 Michele "Jazzinghen" Bianchi

#pragma once

#include "Containers/Array.h"

#include "CaveLib.generated.h"

/**
 *
 */
UCLASS()
class CAVGEN_API UCaveLib : public UObject
{
	GENERATED_BODY()
public:
	UCaveLib() = default;
	~UCaveLib() = default;

	/** Generate cave system using the system presented in: https://kairumagames.com/blog/cavetutorial
	 *
	 * The first step is to generate a maze using Prim's algorithm
	 */
	UFUNCTION(Category = "CaveGen", BlueprintCallable)
	static TArray<bool> GenerateCave(int height, int width);
};