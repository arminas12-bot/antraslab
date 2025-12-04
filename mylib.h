#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
#include <cctype>
#include <chrono>
#include <list>
#include <iterator>


using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::string;
using std::fixed;
using std::setprecision;
using std::sort;
using std::uniform_int_distribution;
using std::random_device;
using std::mt19937;
using std::ifstream;
using std::istringstream;
using std::ofstream;
using std::stringstream;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::duration_cast;
using std::list;
using std::chrono::duration;
using std::partition_copy;
using std::back_inserter;
using std::remove_if;
using std::copy_if;
using std::partition;
using std::stable_partition;




/**
 * @brief Suranda mediana skaiciu vektoriui (int).
 * @param paz Vektorius pazymiu (int).
 * @return Medianos reiksme (double). Jei tuscias - 0.0.
 */
double ieskommediana(const vector <int> & paz);
/**
 * @brief Sugeneruoja kelis failus su atsitiktiniais studentu duomenimis.
 *        Failai: 1000stud.txt, 10000stud.txt, 100000stud.txt, ...
 */
void generuojafailus();
/**
 * @brief Sugeneruoja vieno dydzio faila su studentu ir pazymiais.
 * @param genfail Failo pavadinimas.
 * @param iraskiekis Kiek irasu sugeneruoti.
 */
void generuotifaila(const string & genfail, int iraskiekis);
