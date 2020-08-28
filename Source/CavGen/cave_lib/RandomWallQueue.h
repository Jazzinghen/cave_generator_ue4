// Copyright (c) 2020 Michele "Jazzinghen" Bianchi

#pragma once

#include "Math/UnrealMathUtility.h"

#include <cstdint>
#include <iterator>
#include <random>
#include <utility>
#include <vector>

#include "RandomWallQueue.generated.h"

/**
 *
 */
UCLASS()
class CAVGEN_API URandomWallQueue : public UObject
{
	GENERATED_BODY()
public:
	URandomWallQueue() = default;

	~URandomWallQueue() = default;

	void push(std::uint32_t row, std::uint32_t col)
	{
		data_.push_back(std::make_pair(row, col));
	}

	std::pair<std::uint32_t, std::uint32_t> pop()
	{
		const size_t idx = FMath::RandRange(0, data_.size() - 1);
		std::swap(data_[idx], data_.back());
		const auto random_value = data_.back();
		data_.pop_back();

		return random_value;
	}

	bool empty() const
	{
		return data_.empty();
	}

private:
	std::vector<std::pair<std::uint32_t, std::uint32_t>> data_;
};