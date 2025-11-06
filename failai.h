#pragma once
#include "mylib.h"
#include "studentas.h"
#include "skaidymas.h"


bool failiukasvektorius(vector <Studentas>& Grupe, const string& failassupavadinimu);
bool failiukassarasas(list <Studentas>& Grupe, const string& failassupavadinimu);

void atvaizdvektorius(vector <Studentas>& Grupe);
void atvaizdsarasas(list <Studentas>& Grupe);


inline bool sortvard(const Studentas& a, const Studentas& b) { return a.vard < b.vard; }
inline bool sortpav(const Studentas& a, const Studentas& b) { return a.pavard < b.pavard; }
inline bool sortvidurk(const Studentas& a, const Studentas& b) { return a.vidurk > b.vidurk; }
