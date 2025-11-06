#include "failai.h"
#include "studentas.h"

bool failiukasvektorius(vector <Studentas>& Grupe, const string& failassupavadinimu) {
    ifstream skaitymui(failassupavadinimu);
    if (!skaitymui.is_open()) {
        return false;
    }
    
    string visaeil;
    getline(skaitymui, visaeil);

    while (getline(skaitymui, visaeil)) {
        if (visaeil.empty()) continue;

        istringstream kintam(visaeil);

        Studentas s;
        s.readStudent(kintam);
        Grupe.push_back(s);
    }
    return true;
}

void atvaizdvektorius(vector <Studentas> & Grupe) {
    if (!Grupe.empty()) {
        cout << "Kaip norite atlikti rusiavima? Pagal vardus - 1, pagal pavardes - 2, pagal vidurkius - 3. " << endl;
        int prad;
        cin >> prad;

        auto rikiavimopradzia = high_resolution_clock::now();

        if (prad == 1) sort(Grupe.begin(), Grupe.end(), [](const Studentas& a, const Studentas& b) {return a.vardas() < b.vardas(); });
        else if (prad == 2) sort(Grupe.begin(), Grupe.end(), [](const Studentas& a, const Studentas& b) {return a.pavarde() < b.pavarde(); });
        else if (prad == 3) sort(Grupe.begin(), Grupe.end(), [](const Studentas& a, const Studentas& b) {return a.galutinisvid() > b.galutinisvid(); });

        auto rikiavimopabaiga = high_resolution_clock::now();
        auto rikiavimasuztruko = duration<double>(rikiavimopabaiga - rikiavimopradzia).count();
        cout << "Pasirinktas studentu isrikiavimas is viso uztruko: " << fixed << setprecision(4) << rikiavimasuztruko << " s." << endl;

        cout << "Ka norite suskaiciuoti? Tik galutini vidurki - rasykite raide A, jeigu tik mediana - raide B, jeigu abu - raide C: ";
        char abc;
        cin >> abc;
        const bool imed = (abc == 'b' || abc == 'B');

        auto pradedam = high_resolution_clock::now();

        ofstream rezultatai("rezultatufailas.txt");

        rezultatai << setw(18) << left << "Pavardė";
        rezultatai << setw(18) << left << "Vardas";
        if (abc == 'A' || abc == 'a')
            rezultatai << setw(22) << left << "Galutinis (Vid.)";
        if (abc == 'B' || abc == 'b')
            rezultatai << setw(22) << left << "Galutinis (Med.)";
        if (abc == 'C' || abc == 'c') {
            rezultatai << setw(22) << left << "Galutinis (Vid.)";
            rezultatai << setw(22) << left << "Galutinis (Med.)";
        }
        rezultatai << endl;
        rezultatai << string(65, '-') << endl;

        for (const auto& s : Grupe) {
            rezultatai << setw(18) << left << s.pavarde();
            rezultatai << setw(18) << left << s.vardas();
            if (abc == 'A' || abc == 'a')
                rezultatai << setw(22) << left << fixed << setprecision(2) << s.galutinisvid();
            if (abc == 'B' || abc == 'b')
                rezultatai << setw(22) << left << fixed << setprecision(2) << s.galutinismed();
            if (abc == 'C' || abc == 'c') {
                rezultatai << setw(22) << left << fixed << setprecision(2) << s.galutinisvid();
                rezultatai << setw(22) << left << fixed << setprecision(2) << s.galutinismed();
            }
            rezultatai << endl;
        }

        double kursovidurkis = 0.0;
        int islaik = 0;
        int neislaik = 0;

        for (auto& s : Grupe) {
            const double gal = imed ? s.galutinismed(): s.galutinisvid();
            kursovidurkis += gal;
            if (gal >= 4.5) islaik++;
            else neislaik++;
        }
        kursovidurkis = kursovidurkis / Grupe.size();
        rezultatai << "Bendras viso kurso studentu vidurkis: " << fixed << setprecision(2) << kursovidurkis << endl;
        rezultatai << "Teigiama bendra iverti gavo: " << islaik << " studentai." << endl;
        rezultatai << "Neigiama bendra iverti gavo ir kursa kartos: " << neislaik << " studentai." << endl;


        rezultatai.close();

        auto pabaigiam = high_resolution_clock::now();
        auto bendraslaikas = duration<double>(pabaigiam - pradedam).count();
        cout << "Irasymas i rezultatu faila uztruko: " << fixed << setprecision(4) << bendraslaikas << " s." << endl;

        cout << "Pasirinkite norima skaidymo strategija: " << endl;
        cout << "1 - du nauji to paties tipo konteineriai, 2 - naudojamas tik vienas konteineris, 3 - optimizuota, veikianti greičiausiai" << endl;
        int strategija;
        cin >> strategija;

        if (strategija == 1) {
            vector<Studentas>vargseliai;
            vector<Studentas>kietiakai;


            auto pradedamskaidyma = high_resolution_clock::now();
            skaidymasvector_pirm(Grupe, vargseliai, kietiakai, imed);
            auto baigiamskaidyma = high_resolution_clock::now();
            double skaid = duration<double>(baigiamskaidyma - pradedamskaidyma).count();

            cout << "Pirmos strategijos vector skaidymas i 2 kont. uztruko: " << fixed << setprecision(4) << skaid << " s" << endl;
            ofstream vargsiukaiisv("vargsiukai.txt");
            ofstream kietekaiisv("kietekai.txt");
            if (!vargsiukaiisv.is_open() || !kietekaiisv.is_open()) {
                cout << "Nepavyko sukurti vargsiuku, kieteku failo" << endl;
                return;
            }
            vargsiukaiisv << setw(17) << left << "Pavarde";
            vargsiukaiisv << setw(17) << left << "Vardas";
            vargsiukaiisv << setw(21) << left << "Galutinis" << endl;
            vargsiukaiisv << string(65, '-') << endl;

            kietekaiisv << setw(17) << left << "Pavarde";
            kietekaiisv << setw(17) << left << "Vardas";
            kietekaiisv << setw(21) << left << "Galutinis" << endl;
            kietekaiisv << string(65, '-') << endl;

            auto startass = high_resolution_clock::now();

            for (const auto& s : vargseliai) {
                const double gal = imed ? s.galutinismed() : s.galutinisvid();
                vargsiukaiisv << setw(17) << left << s.pavarde();
                vargsiukaiisv << setw(17) << left << s.vardas();
                vargsiukaiisv << setw(21) << left << fixed << setprecision(2) << gal << endl;
            }

            for (const auto& s : kietiakai) {
                const double gal = imed ? s.galutinismed() : s.galutinisvid();
                kietekaiisv << setw(17) << left << s.pavarde();
                kietekaiisv << setw(17) << left << s.vardas();
                kietekaiisv << setw(21) << left << fixed << setprecision(2) << gal << endl;
            }
            auto endas = high_resolution_clock::now();
            cout << "Studentu surusiuotu isvedimas i du naujus failus uztruko: " << fixed << setprecision(4) << duration<double>(endas - startass).count() << " s." << endl;


            vargsiukaiisv.close();
            kietekaiisv.close();
        }
        else if (strategija == 2) {
            vector <Studentas> nekeiciamorg = Grupe;
            vector <Studentas> varg2;

            auto pradedam2 = high_resolution_clock::now();
            skaidymasvector_antr(nekeiciamorg, varg2, imed);
            auto baigiam2 = high_resolution_clock::now();

            cout << "2 strategijos vector skaidymas uztruko: " << fixed << setprecision(4) << duration<double>(baigiam2 - pradedam2).count() << " s." << endl;
        }
        else if (strategija == 3) {
            vector <Studentas> nukop = Grupe;
            vector <Studentas> vargseliai;
            vector <Studentas> kietiakiai;
            
            auto pradze = high_resolution_clock::now();
            skaidymasvector_trec(nukop, vargseliai, kietiakiai, imed);
            auto pabi = high_resolution_clock::now();
            cout << "3 strategijos skaidymas uztruko: " << fixed << setprecision(4) << duration<double>(pabi - pradze).count() << " s." << endl;
        }
        else {
            cout << "Blogai ivesta strategija" << endl;
        }
    }
}

bool failiukassarasas(list <Studentas>& Grupe,const string & failassupavadinimu) {
    ifstream skaitymui(failassupavadinimu);
    if (!skaitymui.is_open()) {
        return false;
    }

    string visaeil;
    getline(skaitymui, visaeil);

    while (getline(skaitymui, visaeil)) {
        if (visaeil.empty()) continue;

        istringstream kintam(visaeil);
        Studentas s;
        s.readStudent(kintam);
        Grupe.push_back(s);
    }
    return true;
}

void atvaizdsarasas(list <Studentas>& Grupe) {
    if (!Grupe.empty()) {
        cout << "Kaip norite atlikti rusiavima? Pagal vardus - 1, pagal pavardes - 2, pagal vidurkius - 3. " << endl;
        int prad;
        cin >> prad;

        auto rikiavimopradzia = high_resolution_clock::now();

        if (prad == 1) Grupe.sort([](const Studentas& a, const Studentas& b) {return a.vardas() < b.vardas(); });
        else if (prad == 2) Grupe.sort([](const Studentas& a, const Studentas& b) {return a.pavarde() < b.pavarde(); });
        else if (prad == 3) Grupe.sort([](const Studentas& a, const Studentas& b) {return a.galutinisvid() > b.galutinisvid(); });

        auto rikiavimopabaiga = high_resolution_clock::now();
        auto rikiavimasuztruko = duration<double>(rikiavimopabaiga - rikiavimopradzia).count();
        cout << "Pasirinktas studentu isrikiavimas is viso uztruko: " << fixed << setprecision(4) << rikiavimasuztruko << " s." << endl;

        cout << "Ka norite suskaiciuoti? Tik galutini vidurki - rasykite raide A, jeigu tik mediana - raide B, jeigu abu - raide C: ";
        char abc;
        cin >> abc;
        const bool imed = (abc == 'b' || abc == 'B');

        auto pradedam = high_resolution_clock::now();

        ofstream rezultatai("rezultatufailas.txt");

        rezultatai << setw(18) << left << "Pavardė";
        rezultatai << setw(18) << left << "Vardas";
        if (abc == 'A' || abc == 'a')
            rezultatai << setw(22) << left << "Galutinis (Vid.)";
        if (abc == 'B' || abc == 'b')
            rezultatai << setw(22) << left << "Galutinis (Med.)";
        if (abc == 'C' || abc == 'c') {
            rezultatai << setw(22) << left << "Galutinis (Vid.)";
            rezultatai << setw(22) << left << "Galutinis (Med.)";
        }
        rezultatai << endl;
        rezultatai << string(65, '-') << endl;

        for (const auto& s : Grupe) {
            rezultatai << setw(18) << left << s.pavarde();
            rezultatai << setw(18) << left << s.vardas();
            if (abc == 'A' || abc == 'a')
                rezultatai << setw(22) << left << fixed << setprecision(2) << s.galutinisvid();
            if (abc == 'B' || abc == 'b')
                rezultatai << setw(22) << left << fixed << setprecision(2) << s.galutinismed();
            if (abc == 'C' || abc == 'c') {
                rezultatai << setw(22) << left << fixed << setprecision(2) << s.galutinisvid();
                rezultatai << setw(22) << left << fixed << setprecision(2) << s.galutinismed();
            }
            rezultatai << endl;
        }

        double kursovidurkis = 0;
        int islaik = 0;
        int neislaik = 0;

        for (auto& s : Grupe) {
            const double gal = imed ? s.galutinismed() : s.galutinisvid();
            kursovidurkis += gal;
            if (gal >= 4.5) islaik++;
            else neislaik++;
        }
        kursovidurkis = kursovidurkis / Grupe.size();
        rezultatai << "Bendras viso kurso studentu vidurkis: " << fixed << setprecision(2) << kursovidurkis << endl;
        rezultatai << "Teigiama bendra iverti gavo: " << islaik << " studentai." << endl;
        rezultatai << "Neigiama bendra iverti gavo ir kursa kartos: " << neislaik << " studentai." << endl;


        rezultatai.close();

        auto pabaigiam = high_resolution_clock::now();
        auto bendraslaikas = duration<double>(pabaigiam - pradedam).count();
        cout << "Irasymas i rezultatu faila uztruko: " << fixed << setprecision(4) << bendraslaikas << " s." << endl;
        cout << "Rezultatai sekmingai issaugoti" << endl;

        cout << "Pasirinkite norima skaidymo strategija: " << endl;
        cout << "1 - du nauji to paties tipo konteineriai, 2 - naudojamas tik vienas konteineris, 3 - optimizuota, veikianti greičiausiai" << endl;
        int strategija;
        cin >> strategija;
        if (strategija == 1) {
            list<Studentas>vargseliai;
            list<Studentas>kietiakai;

            auto pradedamskaidyma = high_resolution_clock::now();
            skaidymaslist_pirm(Grupe, vargseliai, kietiakai, imed);
            auto baigiamskaidyma = high_resolution_clock::now();
            double skaid = duration<double>(baigiamskaidyma - pradedamskaidyma).count();


            cout << "Pirmos strategijos list skaidymas i 2 kont. uztruko: " << fixed << setprecision(4) << skaid << " s" << endl;
            ofstream vargsiukaiisv("vargsiukai.txt");
            ofstream kietekaiisv("kietekai.txt");
            if (!vargsiukaiisv.is_open() || !kietekaiisv.is_open()) {
                cout << "Nepavyko sukurti vargsiuku, kieteku failo";
                return;
            }
            vargsiukaiisv << setw(17) << left << "Pavarde";
            vargsiukaiisv << setw(17) << left << "Vardas";
            vargsiukaiisv << setw(21) << left << "Galutinis" << endl;
            vargsiukaiisv << string(65, '-') << endl;

            kietekaiisv << setw(17) << left << "Pavarde";
            kietekaiisv << setw(17) << left << "Vardas";
            kietekaiisv << setw(21) << left << "Galutinis" << endl;
            kietekaiisv << string(65, '-') << endl;

            auto startass = high_resolution_clock::now();

            for (const auto& s : vargseliai) {
                const double gal = imed ? s.galutinismed() : s.galutinisvid();
                vargsiukaiisv << setw(17) << left << s.pavarde();
                vargsiukaiisv << setw(17) << left << s.vardas();
                vargsiukaiisv << setw(21) << left << fixed << setprecision(2) << gal << endl;
            }

            for (const auto& s : kietiakai) {
                const double gal = imed ? s.galutinismed() : s.galutinisvid();
                kietekaiisv << setw(17) << left << s.pavarde();
                kietekaiisv << setw(17) << left << s.vardas();
                kietekaiisv << setw(21) << left << fixed << setprecision(2) << gal << endl;
            }

            auto endas = high_resolution_clock::now();
            cout << "Studentu surusiuotu isvedimas i du naujus failus uztruko: " << fixed << setprecision(4) << duration<double>(endas - startass).count() << " s." << endl;
            vargsiukaiisv.close();
            kietekaiisv.close();
        }
        else if (strategija == 2) {
            list <Studentas> nekeiciamorg = Grupe;
            list <Studentas> varg2;

            auto pradedam2 = high_resolution_clock::now();
            skaidymaslist_antr(nekeiciamorg, varg2, imed);
            auto baigiam2 = high_resolution_clock::now();

            cout << "2 strategijos list skaidymas uztruko: " << fixed << setprecision(4) << duration<double>(baigiam2 - pradedam2).count() << " s." << endl;
        }
        else if (strategija == 3) {
            list <Studentas> nukop = Grupe;
            list <Studentas> vargseliai;
            list <Studentas> kietiakiai;

            auto pradze = high_resolution_clock::now();
            skaidymaslist_trec(nukop, vargseliai, kietiakiai, imed);
            auto pabi = high_resolution_clock::now();
            cout << "3 strategijos skaidymas uztruko: " << fixed << setprecision(4) << duration<double>(pabi - pradze).count() << " s." << endl;
        }
        else {
            cout << "Blogai ivesta strategija" << endl;
        }
    }
}

