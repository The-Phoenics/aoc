#pragma once
#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <iostream>
#include <algorithm>

template<typename T>
void print(const std::vector<T>& value) {
	std::cout << "[ ";
	for (auto& item: value) {
		std::cout << item << " ";
	}
	std::cout << "]\n";
}

template<typename T>
void print(std::vector<T>& value) {
	std::for_each(value.begin(), value.end(), [](T& item) {
		std::cout << item << " ";
	});
	std::cout << std::endl;
}

void print(std::vector<int>& data) {
	std::cout << "[ ";
	std::for_each(data.begin(), data.end(), [](int item) {
		std::cout << item << " ";
	});
	std::cout << "]\n";
}

template<typename T, size_t size>
void print(const std::array<T, size>& value) {
	std::cout << "[ ";
	for (auto& item: value) {
		std::cout << item << " ";
	}
	std::cout << "]\n";
}

void print(void) {}
void print(int n)    { std::cout << n << std::endl; }
void print(float n)  { std::cout << n << std::endl; }
void print(double n) { std::cout << n << std::endl; }

void print(bool n)
{
	std::cout << n ? std::cout << "true" << std::endl : std::cout << "false" << std::endl; }
