#pragma once

#include <vector>
#include <iostream>
#include "coloana.hpp"

class Tabela {
private:
	char* nume;
	std::vector<Coloana> coloane;

	public:
		//constructori
		Tabela(const char* nume);
		Tabela(const Tabela& c);
		~Tabela();
		//operatori

		friend std::ostream& operator<<(std::ostream& out, const Tabela& c);
		friend std::istream& operator>>(std::ifstream& in, Tabela& c);

		Tabela operator=(const Tabela& c);
		int& operator[](int index);
		Tabela operator++(int); //post incrementare
		Tabela operator++();//preincrementare
		Tabela operator+(int valoare);
		bool operator==(const Tabela& c);
		bool operator!() const;
		bool operator<(const Tabela& c);
};