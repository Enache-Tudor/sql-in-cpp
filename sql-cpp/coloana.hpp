#pragma once

#include<iostream>
#include <string>
#include <vector>

class Coloana {
private:
	char* nume;
	std::vector<int>valori;
	std::string tipDate;
	static int nrColoane;


public:
	//constructori
	Coloana(char* nume, const std::string& tipDate);
	Coloana(const Coloana& c);
	~Coloana();

	//operatori
	friend std::ostream& operator<<(std::ostream& out, const Coloana& c);//Afi?eaz? numele, tipul de date ?i con?inutul vectorului valori pe ecran
	friend std::istream& operator>>(std::ifstream& in, Coloana& c);//dummy

	Coloana operator=(const Coloana& c);
	int& operator[](int index);
	Coloana operator++(int); //post incrementare
	Coloana operator++();//preincrementare
	Coloana operator+(int valoare);
	bool operator==(const Coloana& c);
	bool operator!() const;
	bool operator<(const Coloana& c);
};