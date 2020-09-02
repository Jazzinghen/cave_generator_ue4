// Copyright (c) 2020 Michele "Jazzinghen" Bianchi

#include "CaveLib.h"

#include "Math/UnrealMathUtility.h"
#include "Maze.h"
#include "RandomWallQueue.h"

#include <algorithm>
#include <cstdint>
#include <utility>

TArray<bool> UCaveLib::GenerateCave(int height, int width)
{
	UMaze maze;
	maze.Generate(static_cast<uint16>(height), static_cast<uint16>(width));

	const TArray<TArray<bool>> raw_maze = maze.Get();

	TArray<bool> unrolled_data;

	for (const TArray<bool>& row : raw_maze)
	{
		unrolled_data.Append(row);
	}

	return unrolled_data;
}