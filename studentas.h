#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::sort;

class Studentas {
public:
	string vard;
	string pavard;
	vector <int> pazym;
	int egzam = 0;
	double vidurk = 0.0;
	double medianaa = 0.0;
	bool validu = true;

	Studentas();
	Studentas(string v, string p);

	void skaiciuojuvidmed();
	double galutinis(bool naudotimediana) const;
	void isvesti() const;
};
