#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <limits>
#include <sstream>
#include <utility>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::sort;
using std::istream;
using std::accumulate;
using std::numeric_limits;
using std::streamsize;
using std::move;
using std::isdigit;
using std::ostream;

/**
 * @brief Apskaičiuoja mediana vektoriui.
 * @param v Vektorius pazymiu.
 * @return Medianos reiksme (double). Jei vektorius tuscias grazina 0.0.
 */
double mediana(const vector<double>&);
/**
 * @brief Apskaičiuoja vidurki vektoriui.
 * @param v Vektorius pazymiu.
 * @return Vidurkis (double). Jei vektorius tuscias grazina 0.0.
 */
double vidurkis(const vector<double>&);

/**
 * @brief Bazine klase, sauganti zmogaus varda ir pavarde.
 */
class Zmogus {
protected:
	string vardas_;
	string pavarde_;
public:
	Zmogus() :vardas_(), pavarde_() {}
	Zmogus(const string& vard, const string& pav) : vardas_(vard), pavarde_(pav) {}

	virtual ~Zmogus() = default;

	const string& vardas() const { return vardas_; }
	const string& pavarde() const { return pavarde_; }

	/**
	 * @brief Grazina galutinio balo reiksme.
	 * @param naudotimediana Jei true - naudoti mediana, kitu atveju - vidurki.
	 */
	virtual double galutinisbalas(bool naudotimediana) const = 0;
};

/**
 * @brief Studentas klase: saugo namu darbu pazymius ir egzamino pazymi.
 */
class Studentas :public Zmogus {
private:
	vector <double> nd_; ///< Namu darbu pazymiai
	double egzaminas_; ///< Egzamino pazymys

public:
	Studentas() : Zmogus(), egzaminas_(0) {}
	explicit Studentas(istream& istu);

	Studentas(const string& vard, const string& pav, const vector <double>& nd, double egz) :Zmogus(vard, pav), nd_(nd), egzaminas_(egz) {}

	Studentas(const Studentas& s);

	Studentas& operator=(const Studentas& s);

	bool operator<(const Studentas& kitas) const;
	~Studentas() {
		nd_.clear();
		egzaminas_ = 0;
	}

	const vector<double>& nd() const { return nd_; }
	double egzaminas() const { return egzaminas_; }


	/**
	 * @brief Lygybes operatorius (vardas, pavarde, egzaminas, nd).
	 */
	bool operator==(const Studentas& other) const {
		return vardas_ == other.vardas_ && pavarde_ == other.pavarde_ && egzaminas_ == other.egzaminas_ && nd_ == other.nd_;
	}

	/**
	* @brief Apskaiciuojamas galutinis pagal vidurki.
	* @return Galutinis (double).
	*/
	double galutinisvid() const;
	/**
	* @brief Apskaiciuojamas galutinis pagal mediana.
	* @return Galutinis (double).
	*/
	double galutinismed() const;
	virtual double galutinisbalas(bool naudotimediana)const {
		return naudotimediana ? galutinismed() : galutinisvid();
	}

	/**
	* @brief Skaito studento duomenis is input stream.
	* @param istu Input stream (pavyzdzui is failo ar cin).
	* @return Atgal grazina stream.
	*/
	istream& readStudent(istream&);

	friend istream& operator>>(istream& is, Studentas& s);
	friend ostream& operator <<(ostream& os, const Studentas& s);

};

/* Pagalbines palyginimo funkcijos */
bool lyginam(const Studentas& a, const Studentas& b);
bool lyginampavardes(const Studentas& a, const Studentas& b);
bool lyginamegzam(const Studentas& a, const Studentas& b);
