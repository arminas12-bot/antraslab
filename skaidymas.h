#pragma once
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include "studentas.h"

using std::vector;
using std::list;
using std::remove_if;
using std::stable_partition;
using std::copy_if;
using std::back_inserter;

/**
 * @brief Kelios skaidymo strategijos: pirma/ antra/ trecia.
 * Funkcijos padeda atskirti vargselius (galutinis < 5) nuo kietuakiu.
 */

 /**
  * @brief Skiria i du konteinerius (vector) nedeplytant originalo.
  */
void skaidymasvector_pirm(const vector <Studentas>& in, vector<Studentas>& vargseliai, vector <Studentas>& kietiakai, bool naudotimediana);
/**
 * @brief Tas pats kaip auksciau bet su list konteineriu.
 */
void skaidymaslist_pirm(const list <Studentas>& in, list<Studentas>& vargseliai, list <Studentas>& kietiakai, bool naudotimediana);

/**
 * @brief Antra strategija: perkelia vargselius i atskira konteineri ir istrina is originalo (vector).
 */
void skaidymasvector_antr(vector <Studentas>& in, vector<Studentas>& vargseliai, bool naudotimediana);
/**
 * @brief Antra strategija list versija.
 */
void skaidymaslist_antr(list <Studentas>& in, list<Studentas>& vargseliai, bool naudotimediana);

/**
 * @brief Trecia strategija: stable_partition + kopijavimas i dvi grupes (vector).
 */
void skaidymasvector_trec(vector <Studentas>& in, vector<Studentas>& vargseliai, vector <Studentas>& kietiakai, bool naudotimediana);
/**
 * @brief Trecia strategija list versija (splice).
 */
void skaidymaslist_trec(list <Studentas>& in, list<Studentas>& vargseliai, list <Studentas>& kietiakai, bool naudotimediana);
