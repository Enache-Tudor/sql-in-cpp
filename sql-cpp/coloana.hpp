#pragma once

#include<iostream>
#include <string>
#include <vector>

class Coloana {
private:
	char* nume;
	std::vector<std::string>valori;
	//std::string tipDate;
	static int nrColoane;
	const int idColoana;

public:
	//constructori
	Coloana(char* nume);
	Coloana(const Coloana& c);
	~Coloana();

	//operatori
	friend std::ostream& operator<<(std::ostream& out, const Coloana& c);//Afi?eaz? numele, tipul de date ?i con?inutul vectorului valori pe ecran
	friend std::istream& operator>>(std::ifstream& in, Coloana& c);//dummy

	Coloana operator=(const Coloana& c);
	std::string & operator[](int index);
	Coloana operator++(int); //post incrementare mareste valorile cu 1
	Coloana operator++();//preincrementare mareste valorile cu 1
	Coloana operator--(int); //post incrementare scade valorile cu 1
	Coloana operator--();//preincrementare scade valorile cu 1
	Coloana operator+(int valoare);//aduna o valoare numerica la toate celulele din coloana
	Coloana operator-(int valoare);//scade o valoare numerica
	bool operator==(const Coloana& c);
	bool operator!() const;//returneaza true daca coloana e empty()
	bool operator<(const Coloana& c);//compara dimensiunea coloanelor 
	operator float() const;
};