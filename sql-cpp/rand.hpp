#pragma once

#include <vector>
#include <iostream>

class Rand {
private:
	char* nume;
	std::vector<double>valoriDate;
	static int nrRanduri;

public:
	//constructori
	Rand(const char* nume);
	Rand(const Rand& r);
	~Rand();

	void addValue(double v);

	Rand& operator=(const Rand& r);
	friend std::ostream& operator<<(std::ostream& out, const Rand& r);
};