#include <iostream>
#include <vector>
#include "coloana.hpp"
#include "rand.hpp"

using namespace std;

int main() {
    cout << "=== TESTARE CLASA RAND ===" << endl;

    // 1. Creare (Instan?iere)
    // "Comanda": Creeaz? un rând nou asociat, de exemplu, unui student
    Rand r1("Student_Gigel");

    // 2. Ad?ugare date (Populare)
    // "Comanda": Adaug? notele sau valorile numerice
    // (Presupunând c? ai ad?ugat metoda adaugaValoare în .hpp ?i .cpp a?a cum am discutat)
    r1.addValue(9.50);
    r1.addValue(8.25);
    r1.addValue(10.00);

    // 3. Afi?are
    // "Comanda": Arat?-mi ce con?ine rândul
    cout << "Rindul 1: " << r1 << endl;

    // 4. Testare Copiere (Rule of 3)
    // "Comanda": F? o copie a lui Gigel
    Rand r2 = r1;
    cout << "Rindul 2 (Copie): " << r2 << endl;

    // 5. Testare Atribuire
    Rand r3("Temp");
    r3 = r1; // Test?m operator=
    cout << "Rindul 3 (Atribuit): " << r3 << endl;

    return 0;
}