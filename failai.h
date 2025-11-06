#pragma once
#include "mylib.h"
#include "studentas.h"
#include "skaidymas.h"


bool failiukasvektorius(vector <Studentas>& Grupe, const string& failassupavadinimu);
bool failiukassarasas(list <Studentas>& Grupe, const string& failassupavadinimu);

void atvaizdvektorius(vector <Studentas>& Grupe);
void atvaizdsarasas(list <Studentas>& Grupe);
