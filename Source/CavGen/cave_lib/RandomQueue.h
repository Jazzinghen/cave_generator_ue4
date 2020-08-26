// Copyright (c) 2020 Michele "Jazzinghen" Bianchi

#pragma once

#include <random>
#include <utility>
#include <vector>

/**
 *
 */
template <typename T>
class CAVGEN_API RandomList
{
public:
	RandomList()
	{
		std::random_device rd;
		generator = std::mt19937(rd());
	};

	~RandomList();

	void push(const T& next)
	{
		data.push_back(next);
	}

	T pop()
	{
		std::uniform_int_distribution<> distribution(0, data_.size() - 1);
		const size_t idx = distribution(generator_);
		std::swap(data_[idx], data_.back());
		const T random_value = data_.back();
		data_.pop_back();

		return random_value;
	}

private:
	std::mt19937 generator_;
	// Underlying datastructure
	std::vector<T> data_;
};