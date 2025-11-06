#include "studentas.h"


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



Studentas::Studentas(istream & istu) : egzaminas_(0) {
	readStudent(istu);
}
double Studentas::galutinismed() const {
	return 0.4 * mediana(nd_) + 0.6 * egzaminas_;
}
double Studentas::galutinisvid() const {
	return 0.4 * vidurkis(nd_) + 0.6 * egzaminas_;
}

istream& Studentas::readStudent(istream & istu) {
	vardas_.clear();
	pavarde_.clear();
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


bool lyginam(const Studentas& a, const Studentas& b) { return a.vardas() < b.vardas(); }
bool lyginampavardes(const Studentas& a, const Studentas& b) { return a.pavarde() < b.pavarde(); }
bool lyginamegzam(const Studentas& a, const Studentas& b) { return a.egzaminas() < b.egzaminas(); }
