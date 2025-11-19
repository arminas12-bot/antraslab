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

double mediana(const vector<double>&);
double vidurkis(const vector<double>&);

class Studentas {
private:
	string vardas_;
	string pavarde_;
	vector <double> nd_;
	double egzaminas_;

public:
	Studentas() : egzaminas_(0) {}
	explicit Studentas(istream & istu);

	Studentas(const string& vard, const string& pav, const vector <double>& nd, double egz) :vardas_(vard), pavarde_(pav), nd_(nd), egzaminas_(egz) {}

	Studentas(const Studentas& s);

	Studentas& operator=(const Studentas& s);

	~Studentas() {
		vardas_.clear();
		pavarde_.clear();
		nd_.clear();
		egzaminas_ = 0;
	}



	inline const string & vardas() const { return vardas_; }
	inline const string & pavarde() const { return pavarde_; }
	inline const vector <double>& nd() const { return nd_; }
	inline double egzaminas() const { return egzaminas_; }

	double galutinisvid() const;
	double galutinismed() const;
	double galutinisbalas(bool naudotimediana)const {
		return naudotimediana ? galutinismed() : galutinisvid();
	}

	istream& readStudent(istream&);

	friend istream& operator>>(istream& is, Studentas& s);
	friend ostream& operator <<(ostream& os, const Studentas& s);

};

bool lyginam(const Studentas& a, const Studentas& b);
bool lyginampavardes(const Studentas& a, const Studentas& b);
bool lyginamegzam(const Studentas& a, const Studentas& b);

