/*

*/
#include "coloana.hpp"

using namespace std;

int Coloana::nrColoane = 0;

Coloana::Coloana(char* nume) :idColoana(++nrColoane){
	if (nume != nullptr)
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
	//idColoana = 0;
	Coloana::nrColoane++;
}
Coloana::Coloana(const Coloana& c) :idColoana(++nrColoane) {
	if (c.nume != nullptr) {
		this->nume = new char[strlen(c.nume) + 1];
		strcpy_s(this->nume, strlen(c.nume) + 1, c.nume);
	}
	this->valori = c.valori;
	//this->idColoana = c.idColoana;
	Coloana::nrColoane++;

}
Coloana::~Coloana() {
	if (nume != nullptr) {
		delete[] nume;
	}
	Coloana::nrColoane--;
}
ostream& operator<<(std::ostream& out, const Coloana& c) {
	out << "Nume: " << (c.nume != nullptr ? c.nume : "Anonim") << endl;
	out << "Valori: [";
	{
		if (!c.valori.empty())
			for (int i = 0; i < c.valori.size(); i++) {
				out << i;
				if (i + 1 < c.valori.size())
					out << ", ";
			}
		out << "]" << endl;
	}

	return out;
}
string& Coloana::operator[](int index) {
	if (index < 0 || index >= this->valori.size())
		throw out_of_range("Index invalid");
	return this->valori[index];
}
Coloana Coloana::operator=(const Coloana& c) {
	if (this != &c)
	{
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
Coloana Coloana::operator+(int valoare) {
	Coloana copie = *this;
	for (int i = 0; i < copie.valori.size(); i++) {
		try {
			float val = stof(copie.valori[i]);
			val+= valoare;
			copie.valori[i] = to_string(val);
		}
		catch (...) {
			//nu ne intereseaza daca nu este numeric si ignoram
		}
	}
	return copie;
}
Coloana Coloana::operator-(int valoare) {
	Coloana copie = *this;
	for (int i = 0; i < copie.valori.size(); i++) {
		try {
			float val = stof(copie.valori[i]);
			val -= valoare;
			copie.valori[i] = to_string(val);
		}
		catch (...) {
			//nu ne intereseaza daca nu este numeric si ignoram
		}
	}
	return copie;
}
Coloana Coloana::operator++(int) {//post
	//salveaza o copie a obiectului vechi, modifica copia si returneaz originalul nemodificat
	Coloana copie = *this;
	for (int i = 0; i < this->valori.size(); i++) {
		try {
			float val = stof(this->valori[i]);
			val++;
			valori[i] = to_string(val);
		}
		catch (...) {
			//nu ne intereseaza daca nu este numeric si ignoram
		}
	}
	return copie;

}
Coloana Coloana::operator++() {//pre
	//modifica originalul
	for (int i = 0; i < this->valori.size(); i++) {
		try {
			float val = stof(this->valori[i]);
			val++;
			valori[i] = to_string(val);
		}
		catch (...) {
			//nu ne intereseaza daca nu este numeric si ignoram
		}
	}
	return *this;
}
Coloana Coloana::operator--(int) {//post
	//salveaza o copie a obiectului vechi, modifica copia si returneaz originalul nemodificat
	Coloana copie = *this;
	for (int i = 0; i < this->valori.size(); i++) {
		try {
			float val = stof(this->valori[i]);
			val--;
			valori[i] = to_string(val);
		}
		catch (...) {
			//nu ne intereseaza daca nu este numeric si ignoram
		}
	}
	return copie;

}
Coloana Coloana::operator--() {//pre
	//modifica originalul
	for (int i = 0; i < this->valori.size(); i++) {
		try {
			float val = stof(this->valori[i]);
			val--;
			valori[i] = to_string(val);
		}
		catch (...) {
			//nu ne intereseaza daca nu este numeric si ignoram
		}
	}
	return *this;
}
bool Coloana::operator==(const Coloana& c) {
	return this->valori == c.valori;
}
bool Coloana::operator!() const {
	return this->valori.empty();
}
Coloana::operator float() const {
	//suma pe coloana
	float suma = 0;
	for (int i = 0; i < this->valori.size(); i++) {
		try {
			float val = stof(this->valori[i]);
			suma += val;
		}
		catch (...) {
			//nu ne intereseaza daca nu este numeric si ignoram
		}
	}
	return suma;
}