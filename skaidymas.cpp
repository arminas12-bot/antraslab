#include "skaidymas.h"
#include "studentas.h"

bool  ar_vargs(const Studentas& s, bool naudotimediana) {
	return s.galutinisbalas(naudotimediana) < 5.0;
}

void skaidymasvector_pirm(const vector <Studentas>& in, vector<Studentas>& vargseliai, vector <Studentas>& kietiakai, bool naudotimediana) {
	vargseliai.clear(); kietiakai.clear();
	for (const auto& s : in) {
		if (ar_vargs(s, naudotimediana)) vargseliai.push_back(s);
		else kietiakai.push_back(s);
	}
}
void skaidymaslist_pirm(const list <Studentas>& in, list<Studentas>& vargseliai, list <Studentas>& kietiakai, bool naudotimediana) {
	vargseliai.clear(); kietiakai.clear();
	for (const auto& s : in) {
		if (ar_vargs(s, naudotimediana)) vargseliai.push_back(s);
		else kietiakai.push_back(s);
	}
}

void skaidymasvector_antr(vector <Studentas>& in, vector<Studentas>& vargseliai, bool naudotimediana) {
	vargseliai.clear();

	for (const auto& s : in) {
		if (ar_vargs(s, naudotimediana))  {
			vargseliai.push_back(s);
		}
	}
	in.erase(remove_if(in.begin(), in.end(), [naudotimediana](const Studentas& s) {
		return ar_vargs(s, naudotimediana);
		}),
		in.end()
	);
}

void skaidymaslist_antr(list <Studentas>& in, list<Studentas>& vargseliai, bool naudotimediana) {
	vargseliai.clear();

	auto tnet = [naudotimediana](const Studentas& s) {
		return ar_vargs(s, naudotimediana);
		};

	copy_if(in.begin(), in.end(), back_inserter(vargseliai), tnet);

	in.remove_if(tnet);
}

void skaidymasvector_trec(vector <Studentas>& in, vector<Studentas>& vargseliai, vector <Studentas>& kietiakai, bool naudotimediana) {
	vargseliai.clear();
	kietiakai.clear();

	auto nein = stable_partition(in.begin(), in.end(), [naudotimediana](const Studentas& s) {
		return ar_vargs(s, naudotimediana);
		});
	for (auto i = in.begin(); i != nein; ++i) vargseliai.push_back(*i);
	for (auto i = nein; i != in.end(); ++i) kietiakai.push_back(*i);

	in.clear();
}

void skaidymaslist_trec(list <Studentas>& in, list<Studentas>& vargseliai, list <Studentas>& kietiakai, bool naudotimediana) {
	vargseliai.clear();
	kietiakai.clear();

	for (auto nein = in.begin(); nein != in.end(); ) {
		if (ar_vargs(*nein, naudotimediana)) {
			auto kop = nein++;
			vargseliai.splice(vargseliai.end(), in, kop);
		}
		else {
			++nein;
		}
	}
	kietiakai.splice(kietiakai.end(), in);
}
