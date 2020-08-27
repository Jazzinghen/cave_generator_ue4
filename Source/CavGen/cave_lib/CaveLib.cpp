// Copyright (c) 2020 Michele "Jazzinghen" Bianchi

#include "CaveLib.h"

#include "Math/UnrealMathUtility.h"
#include "RandomQueue.h"

#include <cstdint>
#include <utility>

TArray<TArray<bool>> UCaveLib::GenerateCave(uint16 height, uint16 width)
{
	TArray<TArray<bool>> result;

	// Look what I have to do because they don't provide an useful constructor.
	// This will create a maze filled with walls (with space for them :3)
	TArray<bool> row;
	row.Init(false, (width * 2) + 1);
	for (uint32 row = 0; row < ((height * 2) + 1); ++row)
	{
		result.Push(row);
	}

	RandomQueue<std::pair<std::uint32_t, std::unit32_t>> exploration_front;

	const uint32 starting_row = Math::RandRange(1, (height * 2) - 1);
	const uint32 starting_col = Math::RandRange(1, (width * 2) - 1);

	return result;
}