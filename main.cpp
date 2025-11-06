#include "mylib.h"
#include "failai.h"
#include "studentas.h"

int main() {

    char konteineris;
    cout << "Su kokiu konteineriu norite dirbti? Jei su sarasu rasykite raide S, jei su vektoriumi - V" << endl;
    cin >> konteineris;

    vector<Studentas> GrupeV;
    list<Studentas> GrupeS;

    cout << "Ar duomenis norite vesti pats, ar nuskaityti is failo? Jei pats, rasykite raide p(P), jei is failo, tuomet f(F), o jei generuoti failus - rasykite g(G)." << endl;
    char pasirinkta;
    cin >> pasirinkta;

    if (pasirinkta == 'p' || pasirinkta == 'P') {
        cout << "Iveskite studentu skaiciu grupeje: ";
        int m;
        cin >> m;
        if (m <= 0) {
            cout << "Klaidingai ivesti duomenys. Studentu skaicius turi buti rasomas arabiskais skaitmenimis ir turi buti didesnis uz 0." << endl;
            return 0;
        }

        if (konteineris == 'V' || konteineris == 'v') {
            for (int z = 0; z < m; z++) {
                Studentas st;
                cout << "Vardas ";
                cin >> st.vard;
                for (char c : st.vard) if (isdigit(static_cast<unsigned char>(c))) st.validu = false;

                cout << "Pavarde ";
                cin >> st.pavard;
                for (char c : st.pavard) if (isdigit(static_cast<unsigned char>(c))) st.validu = false;

                if (!st.validu) {
                    cout << "Rasomos tik raides!" << endl;
                    continue;
                }

                cout << "Iveskite gautus pazymus. Baige vesti rasykite 0" << endl;
                int numeris = 1, laik_paz;

                while (true) {
                    cout << numeris << " pazymys: ";
                    cin >> laik_paz;

                    if (cin.fail()) {
                        cout << "Klaidingai ivestas pazymys." << endl;
                        cin.clear();
                        cin.ignore();
                        continue;
                    }
                    if (laik_paz == 0) break;
                    if (laik_paz < 1 || laik_paz>10) {
                        cout << "Pazymiai turi buti vedami nuo 1 iki 10." << endl;
                        continue;
                    }
                    st.pazym.push_back(laik_paz);
                    numeris++;
                }
                cout << "Iveskite gauta studento egzamino pazymi: ";
                cin >> st.egzam;
                if (cin.fail() || st.egzam < 1 || st.egzam>10) {
                    cout << "Klaidingai ivesti duomenys" << endl;
                    st.validu = false;
                }

                if (st.validu) {
                    st.skaiciuojuvidmed();
                    GrupeV.push_back(st);
                    cout << "Studento ( " << st.vard << " "<<st.pavard << " ) atminties adresas: " << static_cast<void*>(&GrupeV.back()) << endl;
                }
            }
            atvaizdvektorius(GrupeV);
        }
        else {
            for (int z = 0; z < m; z++) {
                Studentas st;
                cout << "Vardas ";
                cin >> st.vard;
                for (char c : st.vard) if (isdigit(static_cast<unsigned char>(c))) st.validu = false;

                cout << "Pavarde ";
                cin >> st.pavard;
                for (char c : st.pavard) if (isdigit(static_cast<unsigned char>(c))) st.validu = false;

                if (!st.validu) {
                    cout << "Rasomos tik raides!" << endl;
                    continue;
                }

                cout << "Iveskite gautus pazymus. Baige vesti rasykite 0" << endl;
                int numeris = 1, laik_paz;

                while (true) {
                    cout << numeris << " pazymys: ";
                    cin >> laik_paz;

                    if (cin.fail()) {
                        cout << "Klaidingai ivestas pazymys." << endl;
                        cin.clear();
                        cin.ignore();
                        continue;
                    }
                    if (laik_paz == 0) break;
                    if (laik_paz < 1 || laik_paz>10) {
                        cout << "Pazymiai turi buti vedami nuo 1 iki 10." << endl;
                        continue;
                    }
                    st.pazym.push_back(laik_paz);
                    numeris++;
                }
                cout << "Iveskite gauta studento egzamino pazymi: ";
                cin >> st.egzam;
                if (cin.fail() || st.egzam < 1 || st.egzam>10) {
                    cout << "Klaidingai ivesti duomenys" << endl;
                    st.validu = false;
                }

                if (st.validu) {
                    st.skaiciuojuvidmed();
                    GrupeS.push_back(st);
                    cout << "Studento ( " << st.vard << " "<<st.pavard << " ) atminties adresas: " << static_cast<void*>(&GrupeS.back()) << endl;
                }
            }
            atvaizdsarasas(GrupeS);
        }
    }
    else if (pasirinkta == 'f' || pasirinkta == 'F') {
        string norimfail;
        cout << "Iveskite norimo failo pavadinimas (gale nepamirskite prideti .txt): ";
        cin >> norimfail;

        auto startas = high_resolution_clock::now();
        bool sekmingas = false;

        if (konteineris == 'V' || konteineris == 'v') {
            sekmingas = failiukasvektorius(GrupeV, norimfail);
        }
        else
            sekmingas = failiukassarasas(GrupeS, norimfail);

        auto uztrukimas = duration_cast<seconds>(high_resolution_clock::now() - startas);

        if (sekmingas) {

            cout << "Sekmingai pavyko nuskaityti duomenis is failo. ";
            cout << "Nuskaityti faila uztruko: " << uztrukimas.count() << " s." << endl;
            if (konteineris == 'V' || konteineris == 'v')
                atvaizdvektorius(GrupeV);
            else
                atvaizdsarasas(GrupeS);
        }
        else {
            cout << "Nesekmingas failo nuskaitymas" << endl;
        }
    }

    else if (pasirinkta == 'g' || pasirinkta == 'G') {
        generuojafailus();
        cout << "Jei norite toliau dirbti su sugeneruotu failu, iveskite jo pavadinima, jei norite baigti, rasykite raide b(B): ";
        string failas;
        cin >> failas;

        if (failas != "b" && failas != "B") {
            auto startas = (high_resolution_clock::now());
            bool sekmingas = false;

            if (konteineris == 'V' || konteineris == 'v')
                sekmingas = failiukasvektorius(GrupeV, failas);
            else
                sekmingas = failiukassarasas(GrupeS, failas);

            auto uztrukimas = duration_cast<seconds>(high_resolution_clock::now() - startas);

            if (sekmingas) {

                cout << "Nuskaitymas sekmingas" << endl;
                cout << "Nuskaityti faila uztruko: " << uztrukimas.count() << " s." << endl;
                if (konteineris == 'V' || konteineris == 'v')
                    atvaizdvektorius(GrupeV);
                else
                    atvaizdsarasas(GrupeS);
            }
            else {
                cout << "Nesekmingas nuskaitymas failo" << failas << endl;
            }
        }
        else {
            cout << "Viskas baigta, failai sekmingai sukurti" << endl;
        }
    }
    return 0;
}
