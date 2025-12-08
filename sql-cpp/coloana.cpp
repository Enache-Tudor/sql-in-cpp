/*

*/
#include "coloana.hpp"

using namespace std;

int Coloana::nrColoane = 0;

Coloana::Coloana(char* nume, const std::string& tipDate) {
	if (nume != nullptr)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
	this->tipDate = tipDate;
	Coloana::nrColoane++;
}
Coloana::Coloana(const Coloana& c) {
	if (c.nume != nullptr) {
		this->nume = new char[strlen(c.nume) + 1];
		strcpy_s(this->nume,strlen(c.nume) +1,c.nume);
	}
	this->valori = c.valori;
	this->tipDate = c.tipDate;
	Coloana::nrColoane++;

}
Coloana::~Coloana() {
	if (nume != nullptr) {
		delete[] nume;
	}
	Coloana::nrColoane--;
}
Coloana Coloana::operator=(const Coloana & c) {
	if(this != &c)
	{
		this->tipDate = c.tipDate;
		this->valori = c.valori;
		if (c.nume != nullptr) {
			this->nume = new char[strlen(c.nume) + 1];
			strcpy_s(this->nume, strlen(c.nume) + 1, c.nume);
		}
		else
			this->nume = nullptr;
	}
	return *this;
}
ostream& operator<<(std::ostream& out, const Coloana& c) {
	out << "Nume: " << (c.nume != nullptr ? c.nume : "Anonim") << endl;
	out << "Tip date: " << c.tipDate << endl;
	out << "Valori: [";
	{
		if (!c.valori.empty())
			for (int i = 0; i < c.valori.size();i++) {
				out << i;
				if (i + 1 < c.valori.size())
					out << ", ";
			}
		out << "]" << endl;
	}

	return out;
}
int& Coloana::operator[](int index) {
	if (index < 0 || index >= this->valori.size())
		throw out_of_range("Index invalid");
	return this->valori[index];
}
Coloana Coloana::operator+(int valoare) { 
	Coloana copie = *this;
	for (int &i : copie.valori) {//lucram cu valoarea nu cu o copie
		i += valoare;
	}
	return copie;
}
Coloana Coloana::operator++(int) {//post
	//salveaza o copie a obiectului vechi, modifica copia si returneaz originalul nemodificat
	Coloana copie = *this;
	this->valori.push_back(0);
	return copie;

}
Coloana Coloana::operator++() {//pre
	//modifica originalul
	this->valori.push_back(0);
	return *this;
}
bool Coloana::operator==(const Coloana& c) {
	//2 coloana sunt egale daca au valorile egale
	if (c.valori.size() == this->valori.size())
	{
		for (int i = 0; i < c.valori.size(); i++) {
			if (this->valori[i] != c.valori[i])
				return false;
		}
		return true;
	}
	else
		return false;
}
bool Coloana::operator!() const{
	//daca nu este goala => true
	return this->valori.empty();
}