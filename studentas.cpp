#include "studentas.h"

Studentas::Studentas() = default;

Studentas::Studentas(string v, string p) {
	vard = v;
	pavard = p;
}

void Studentas::skaiciuojuvidmed() {
	if (pazym.empty()) {
		vidurk = 0.6 * egzam;
		medianaa = 0.6 * egzam;
		return;
	}

	double suma = 0;
	for (int p : pazym) suma += p;
	double vid = suma / pazym.size();

	vector <int> laikina = pazym;
	sort(laikina.begin(), laikina.end());
	double med;
	int laikindyd = laikina.size();
	if (laikindyd % 2 == 1) med = laikina[laikindyd / 2];
	else med = (laikina[laikindyd / 2 - 1] + laikina[laikindyd / 2]) / 2.0;
	vidurk = vid * 0.4 + egzam * 0.6;
	medianaa = med * 0.4 + egzam * 0.6;
}
double Studentas::galutinis(bool naudotimediana) const {
	return naudotimediana ? medianaa : vidurk;
}

void Studentas::isvesti() const {
	cout << "Vardas ir pavarde( " << vard << " " << pavard << " ). Jo vidurkis: " << vidurk << " , o mediana: " << medianaa << endl;
}
