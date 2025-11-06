#include "mylib.h"


double ieskommediana(const vector<int> & paz) {
    double h;
    if (paz.empty()) return 0.0;
    vector<int> kopija = paz;
    sort(kopija.begin(), kopija.end());
    int n = kopija.size();
    if (n % 2 == 1) {
        h = kopija[n / 2];
    }
    else {
        h = (kopija[n / 2 - 1] + kopija[n / 2]) / 2.0;
    }
    return h;
}
void generuojafailus() {
    cout << "Generuojami failai, prasome palaukti" << endl;
    generuotifaila("1000stud.txt", 1000);
    generuotifaila("10000stud.txt", 10000);
    generuotifaila("100000stud.txt", 100000);
    generuotifaila("1000000stud.txt", 1000000);
    generuotifaila("10000000stud.txt", 10000000);
    cout << "5 skirtingo dydzio failai sekmingai sugeneruoti" << endl;
}

void generuotifaila(const string & genfail, int iraskiekis) {
    auto pradzia = high_resolution_clock::now();
    ofstream failas(genfail);
    if (!failas.is_open()) {
        cout << "Nesekmingas " << genfail << " failo sukurimas" << endl;
        return;
    }

    failas << left << setw(20) << "Pavarde";
    failas << left << setw(20) << "Vardas";
    for (int y = 1; y < 8; y++) {
        stringstream sstreamas;
        sstreamas << "Nd" << y;
        failas << left << setw(9) << sstreamas.str();
    }
    failas << left << setw(9) << "Egz" << endl;

    random_device rando;
    mt19937 mt(rando());
    uniform_int_distribution <int> paz(1, 10);

    for (int h = 1; h <= iraskiekis; h++) {
        stringstream stringpav, stringvar;
        stringpav << "Pavarde" << h;
        stringvar << "Vardas" << h;
        failas << left << setw(20) << stringpav.str();
        failas << left << setw(20) << stringvar.str();
        for (int l = 0; l < 7; l++) {
            failas << left << setw(9) << paz(mt);
        }
        failas << left << setw(9) << paz(mt) << endl;
    }
    failas.close();

    auto pabaiga = high_resolution_clock::now();
    auto uztruko = duration_cast<milliseconds>(pabaiga - pradzia);
    cout << genfail << ".Si faila is visos sukurti uztruko " << uztruko.count() << " ms." << endl;
}
