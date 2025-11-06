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

void skaidymasvector_pirm(const vector <Studentas>& in, vector<Studentas>& vargseliai, vector <Studentas>& kietiakai, bool naudotimediana);
void skaidymaslist_pirm(const list <Studentas>& in, list<Studentas>& vargseliai, list <Studentas>& kietiakai, bool naudotimediana);

void skaidymasvector_antr(vector <Studentas>& in, vector<Studentas>& vargseliai, bool naudotimediana);
void skaidymaslist_antr(list <Studentas>& in, list<Studentas>& vargseliai, bool naudotimediana);

void skaidymasvector_trec(vector <Studentas>& in, vector<Studentas>& vargseliai, vector <Studentas>& kietiakai, bool naudotimediana);
void skaidymaslist_trec(list <Studentas>& in, list<Studentas>& vargseliai, list <Studentas>& kietiakai, bool naudotimediana);
