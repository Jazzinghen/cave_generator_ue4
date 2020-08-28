// Copyright (c) 2020 Michele "Jazzinghen" Bianchi

#pragma once

#include <cstdint>
#include <iterator>
#include <random>
#include <utility>
#include <vector>

/**
 *
 */
class CAVGEN_API RandomWallQueue
{
public:
	RandomWallQueue()
	{
		std::random_device rd;
		generator_ = std::mt19937(rd());
	};

	~RandomWallQueue();

	void push(std::uint32_t row, std::uint32_t col)
	{
		data_.push_back(std::make_pair(row, col));
	}

	std::pair<std::uint32_t, std::uint32_t> pop()
	{
		std::uniform_int_distribution<> distribution(0, data_.size() - 1);
		const size_t idx = distribution(generator_);
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
	std::mt19937 generator_;
	// Underlying datastructure
	std::vector<std::pair<std::uint32_t, std::uint32_t>> data_;
};