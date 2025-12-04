#include "studentas.h"

/* mediana ir vidurkis aprasyti header faile */
double mediana(const vector<double>& v) {
	if (v.empty()) return 0.0;
	vector <double> kint1 = v;

	sort(kint1.begin(), kint1.end());

	auto n = kint1.size();
	return (n % 2) ? kint1[n / 2] : (kint1[n / 2 - 1] + kint1[n / 2]) / 2.0;
}

double vidurkis(const vector<double> & v) {
	if (v.empty()) return 0.0;
	double suma = accumulate(v.begin(), v.end(), 0.0);
	return suma / v.size();
}


Studentas::Studentas(istream & istu) : Zmogus(), egzaminas_(0) {
	readStudent(istu);
}

Studentas::Studentas(const Studentas& s) : Zmogus(s.vardas_, s.pavarde_), nd_(s.nd_), egzaminas_(s.egzaminas_) {}

Studentas& Studentas::operator=(const Studentas& s) {
	if (this != &s) {
		vardas_ = s.vardas_;
		pavarde_ = s.pavarde_;
		nd_ = s.nd_;
		egzaminas_ = s.egzaminas_;
	}
	return *this;
}

double Studentas::galutinismed() const {
	return 0.4 * mediana(nd_) + 0.6 * egzaminas_;
}
double Studentas::galutinisvid() const {
	return 0.4 * vidurkis(nd_) + 0.6 * egzaminas_;
}

istream& Studentas::readStudent(istream & istu) {
	nd_.clear();
	egzaminas_ = 0;

	if (!(istu >> pavarde_ >> vardas_)) return istu;


	double paz;
	vector <double> laikk;
	while (istu >> paz) laikk.push_back(paz);

	if (!laikk.empty()) {
		egzaminas_ = laikk.back();
		laikk.pop_back();
		nd_ = move(laikk);
	}

	istu.clear();
	return istu;

}

istream& operator>>(istream& is, Studentas& s) {
	return s.readStudent(is);
}

ostream& operator <<(ostream& os, const Studentas& s) {
	os << s.pavarde() << " " << s.vardas();

	if (!s.nd().empty()) {
		os << " ND:";
		for (double paz : s.nd()) {
			os << " " <<static_cast<int>(paz);
		}
	}
	os << " Egz:" << static_cast<int>(s.egzaminas());
	return os;
}


bool lyginam(const Studentas& a, const Studentas& b) { return a.vardas() < b.vardas(); }
bool lyginampavardes(const Studentas& a, const Studentas& b) { return a.pavarde() < b.pavarde(); }
bool lyginamegzam(const Studentas& a, const Studentas& b) { return a.egzaminas() < b.egzaminas(); }
