#include "rand.hpp"

using namespace std;

int Rand::nrRanduri = 0;

Rand::Rand(const char* nume) {
	if (nume != nullptr) {
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
	else
	{
		this->nume = new char[4];
		strcpy_s(this->nume, 4, "N/a");
	}
	Rand::nrRanduri++;
}
Rand::Rand(const Rand& r) {
	if (r.nume != nullptr) {
		this->nume = new char[strlen(r.nume) + 1];
		strcpy_s(this->nume, strlen(r.nume) + 1, r.nume);
	}
	else
	{
		this->nume = new char[4];
		strcpy_s(this->nume, 4, "N/a");
	}
	this->valoriDate = r.valoriDate;
	Rand::nrRanduri++;
}
Rand::~Rand() {
	delete[] nume;
	Rand::nrRanduri--;
}

Rand& Rand::operator=(const Rand & r) {
	if (this != &r) {
		this->valoriDate = r.valoriDate;
		if (r.nume != nullptr) {
			this->nume = new char[strlen(r.nume) + 1];
			strcpy_s(this->nume, strlen(r.nume) + 1, r.nume);
		}
		else
			this->nume = nullptr;
	}
	return *this;
}

ostream& operator<<(ostream& out, const Rand& r) {
	out << "Nume: " << (r.nume != nullptr ? r.nume : "N/A") << endl;
	out << "Valori: [";
	{
		if (!r.valoriDate.empty())
			for (int i = 0; i < r.valoriDate.size(); i++) {
				out << i;
				if (i + 1 < r.valoriDate.size())
					out << ", ";
			}
		out << "]" << endl;
	}
	return out;
}

//metode

void Rand::addValue(double value) {
	this->valoriDate.push_back(value);
}