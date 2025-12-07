//contine mai multe tabele

#pragma once

#include <iostream>
#include "tabela.hpp"
#include <vector>

class BazaDeDate {
private:
	char* nume;
	std::vector<Tabela>tabele;

public:
	//constructori
	BazaDeDate(const char* nume);
	BazaDeDate(const BazaDeDate& bdd);
	~BazaDeDate();

	//op
};