// Copyright (c) 2020 Michele "Jazzinghen" Bianchi

#include "CaveLib.h"

#include "Math/UnrealMathUtility.h"
#include "Maze.h"
#include "RandomWallQueue.h"

#include <algorithm>
#include <cstdint>
#include <utility>

TArray<TArray<bool>> UCaveLib::GenerateCave(uint16 height, uint16 width)
{
	UMaze maze();
	maze.Generate(height, width);

	return maze.Get();
}