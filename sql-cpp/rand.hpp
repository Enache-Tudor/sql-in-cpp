#pragma once

#include <vector>
#include <iostream>

class Rand {
private:
	char* nume;
	std::vector<double>valoriDate;

public:
	//constructori
	Rand(const char* nume);
	Rand(const Rand& r);
	~Rand();
};