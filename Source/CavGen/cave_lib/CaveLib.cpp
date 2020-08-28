// Copyright (c) 2020 Michele "Jazzinghen" Bianchi

#include "CaveLib.h"

#include "Math/UnrealMathUtility.h"
#include "RandomQueue.h"

#include <algorithm>
#include <cstdint>
#include <utility>

TArray<TArray<bool>> UCaveLib::GenerateCave(uint16 height, uint16 width)
{
	TArray<TArray<bool>> result;

	// Look what I have to do because they don't provide an useful constructor.
	// This will create a maze filled with walls (with space for them :3)
	TArray<bool> wall_row;
	wall_row.Init(false, (width * 2) + 1);
	for (uint32 row = 0; row <= (height * 2ul); ++row)
	{
		result.Push(wall_row);
	}

	RandomQueue<std::pair<std::uint32_t, std::uint32_t>> exploration_front;

	// Pick a starting location at random to make it part of the labyrinth
	const uint32 starting_row = FMath::RandRange(0, height);
	const uint32 starting_col = FMath::RandRange(0, width);

	// These conversions will kill me
	const uint32 padded_row = (starting_row * 2) + 1;
	const uint32 padded_col = (starting_col * 2) + 1;

	result[padded_row][padded_col] = true;

	// Add all the walls that are adjacent to the chosen location
	if (starting_row > 0)
	{
		exploration_front.push(std::make_pair(padded_row - 1, starting_col));
	}
	if (starting_row < (height - 1ul))
	{
		exploration_front.push(std::make_pair(padded_row + 1, starting_col));
	}

	if (starting_col > 0)
	{
		exploration_front.push(std::make_pair(padded_row, starting_col - 1));
	}
	if (starting_col < (width - 1ul))
	{
		exploration_front.push(std::make_pair(padded_row, starting_col + 1));
	}

	// Time for the loop!
	while (!exploration_front.empty())
	{
		const auto next_wall = exploration_front.pop();
	}

	return result;
}