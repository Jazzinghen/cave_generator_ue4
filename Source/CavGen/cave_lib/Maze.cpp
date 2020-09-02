// Copyright (c) 2020 Michele "Jazzinghen" Bianchi

#include "Maze.h"

#include "Containers/Array.h"
#include "RandomWallQueue.h"

#include <cstdint>
#include <utility>

void UMaze::Generate(uint16 height, uint16 width)
{
	height_ = height;
	width_ = width;

	padded_height_ = height * 2 + 1;
	padded_width_ = width * 2 + 1;
	// Look what I have to do because they don't provide an useful constructor.
	// This will create a maze filled with walls (with space for them :3)
	TArray<bool> wall_row;
	wall_row.Init(false, padded_width_);
	for (uint32 row = 0; row < padded_height_; ++row)
	{
		data_.Push(wall_row);
	}

	URandomWallQueue exploration_front;

	// Pick a starting location at random to make it part of the labyrinth
	const uint32 starting_row = FMath::RandRange(0, height);
	const uint32 starting_col = FMath::RandRange(0, width);

	// These conversions will kill me
	const uint32 padded_row = (starting_row * 2) + 1;
	const uint32 padded_col = (starting_col * 2) + 1;

	data_[padded_row][padded_col] = true;

	// Add all the walls that are adjacent to the chosen location
	AddWalls(std::make_pair(padded_row, padded_col), exploration_front);

	// Time for the loop!
	while (!exploration_front.empty())
	{
		const auto next_wall = exploration_front.pop();
		std::pair<std::uint32_t, std::uint32_t> next_cell = next_wall;

		// Now check if it's a vertical or an horizontal wall
		if ((next_wall.first % 2) == 0)
		{
			// If the row is even then it's a vertical wall

			// Now we have to check where we came from and if this is a wall
			// leading to a non-explored location

			const bool cell_below = data_[next_wall.first + 1][next_wall.second];
			const bool cell_above = data_[next_wall.first - 1][next_wall.second];

			// if we have one maze cell and one wall...
			if (cell_below != cell_above)
			{
				// set the wall as a connection
				data_[next_wall.first][next_wall.second] = true;

				// then, if the maze cell is the one above, then the next maze
				// cell will be the one below and the opposite
				if (cell_above)
				{
					++next_cell.first;
				}
				else
				{
					--next_cell.first;
				}
			}
		}
		else
		{
			// Otherwise it's an horizontal wall
			const bool cell_right = data_[next_wall.first][next_wall.second + 1];
			const bool cell_left = data_[next_wall.first][next_wall.second - 1];

			if (cell_right != cell_left)
			{
				data_[next_wall.first][next_wall.second] = true;

				if (cell_left)
				{
					++next_cell.second;
				}
				else
				{
					--next_cell.second;
				}
			}
		}
		data_[next_cell.first][next_cell.second] = true;
		AddWalls(next_cell, exploration_front);
	}
}

void UMaze::AddWalls(const std::pair<std::uint32_t, std::uint32_t>& cell, URandomWallQueue& front) const
{
	if (cell.first >= 3)
	{
		front.push(cell.first - 1, cell.second);
	}
	if (cell.first <= (height_ - 4ul))
	{
		front.push(cell.first + 1, cell.second);
	}
	if (cell.second >= 3)
	{
		front.push(cell.first, cell.second - 1);
	}
	if (cell.second <= (width_ - 4ul))
	{
		front.push(cell.first, cell.second + 1);
	}
}