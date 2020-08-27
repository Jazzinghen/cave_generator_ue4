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
	static TArray<TArray<bool>> GenerateCave(uint16 height, uint16 width);
};