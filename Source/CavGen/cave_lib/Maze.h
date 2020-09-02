// Copyright (c) 2020 Michele "Jazzinghen" Bianchi

#pragma once

#include "Containers/Array.h"
#include "RandomWallQueue.h"

#include <cstdint>
#include <utility>

#include "Maze.generated.h"

/**
 *
 */
UCLASS()
class CAVGEN_API UMaze : public UObject
{
	GENERATED_BODY()
public:
	UMaze() = default;
	~UMaze() = default;

	void Generate(uint16 height, uint16 width);

	const TArray<TArray<bool>>& Get() const
	{
		return data_;
	}

private:
	TArray<TArray<bool>> data_;
	uint16 height_;
	uint16 width_;

	uint32 padded_height_;
	uint32 padded_width_;

	void AddWalls(const std::pair<std::uint32_t, std::uint32_t>& cell, URandomWallQueue& front) const;
};
