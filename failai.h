#pragma once
#include "mylib.h"
#include "studentas.h"
#include "skaidymas.h"

/**
 * @brief Nuskaityti studentus i vector is failo.
 * @return true jei pavyko, false priesingu atveju.
 */
bool failiukasvektorius(vector <Studentas>& Grupe, const string& failassupavadinimu);
/**
 * @brief Nuskaityti studentus i list is failo.
 */
bool failiukassarasas(list <Studentas>& Grupe, const string& failassupavadinimu);

/**
 * @brief Atvaizduoti ir issaugoti rezultatus is vector konteinerio.
 */
void atvaizdvektorius(vector <Studentas>& Grupe);
/**
 * @brief Atvaizduoti ir issaugoti rezultatus is list konteinerio.
 */
void atvaizdsarasas(list <Studentas>& Grupe);
