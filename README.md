# PAGRINDINIAI NAUDOJIMOSI ŽINGSNIAI
1. Paleidę programą vartotojai pasirenka, ar nori dirbti su list, ar su vector tipo konteineriu.
   
<img width="813" height="25" alt="image" src="https://github.com/user-attachments/assets/5cac5314-474a-4a72-9f5a-2814bdb96c52" />

2. Tuomet naudotojas turi teisę pasirinkti, ar duomenis nori nuskaityti is failo, ar vesti ranka pats, o galbūt generuoti atsitiktinius pažymius su įvairiais kiekiais įrašų.
   
<img width="1092" height="50" alt="image" src="https://github.com/user-attachments/assets/ee30582c-6144-4ad4-9b0d-713b2447ea40" />

3. Tuomet atlikęs pasirinkimą, turi nuspręsti, kokį atlikti rūšiavimą. Galimi trys pasirinkimo variantai.
   
<img width="812" height="26" alt="image" src="https://github.com/user-attachments/assets/a10db75a-ab5d-4171-93d5-126c0eecfa98" />

4. Tuomet yra apskaičiuojamas ir išvedamas laikas (kiek užtruko rūšiavimas). Tada vartotojas renkasi - ar skaičiuoti vidurkį, ar medianą, ar abu.
   
<img width="1032" height="41" alt="image" src="https://github.com/user-attachments/assets/1131a2b3-a95c-44cc-8790-1665e8790bd7" />

5. Tada vartotojui yra išvedamas rezultatų įrašymo į failą laikas bei liepiama pasirinkti norimą strategiją iš trijų variantų.
   
<img width="855" height="112" alt="image" src="https://github.com/user-attachments/assets/4bce0811-1908-4b2c-993d-62b6a6c60a13" />

6. Galiausiai informuojama apie pasirinktos strategijos ir konteinerio (list arba vector) studentų skaidymo į du naujus kont. trukmę bei pranešama, kiek užtruko surūšiuotų studentų išvedimas.
    
<img width="611" height="49" alt="image" src="https://github.com/user-attachments/assets/6e63b56d-2ccc-44e0-b6bb-842c3d627cf5" />

7. Programa baigiama, o visi rezultatai išsaugomi keliuose rezultatų failuose.
 
# PAGRINDINIAI DIEGIMO ŽINGSNIAI
1. Būtinai pasitikrinkite, ar įrenginyje yra idiegtas kompiliatorius su cmake.
2. Atsisiųskite visus reikalingus failus: main.cpp, mylib.cpp, failai.cpp, failai.h, mylib.h bei CMakeLists.txt.
3. Susikurkite projektui naują vietą, pvz: C:\Projects\*Projekto pavadinimas*
4. Sukelkite į projekto aplanką visus atsisiųstus failus.
5. Terminale sukurkite build katalogą:
   
mkdir build

cd build

cmake .. -G "Visual Studio 17 2022" -A x64

6. Kompiliuojame:

cmake --build . --config Release

.\Release\*Studentaif*.exe

7. Viskas! Programa paruošta! Dabar galite spustelėti du kartus ant .exe failo ir programa pradės veikti!



## V0.1 + V.0.2 versijos trumpas aprašymas.

Nuo šiol programa veikia ne vien tik V0.1 principu, bet ir V0.2, todėl papildomai gali:

-generuoti atsitiktinius studentų sąrašų failus su skirtingais įrašų kiekiais;

-rūšiuoti studentus į kategorijas pagal galutinį įvertinimą;

-apskaičiuoti ir išvesti, per kiek laiko sukuriamas failas, per kiek laiko nuskaitomi duomenys iš tam tikrų failų, taip pat apskaičiuojamas rūšiavimo veikimo greitis.

Pavyzdys: -1000 įrašų – failas sukuriamas per 2 ms, paskutinį kartą nuskaitytas per 3 ms. Failo sugeneravimo vidurkis - 2,2 ms.

-10000 įrašų – failas sukuriamas per 22 ms, paskutinį kartą nuskaitytas per 31 ms. Failo sugeneravimo vidurkis - 27,2 ms.

-100000 įrašų – failas sukuriamas per 226 ms, paskutinį kartą nuskaitytas per 339 ms. Failo sugeneravimo vidurkis - 277,4 ms.

-1000000 įrašų – failas sukuriamas per 1127 ms, paskutinį kartą nuskaitytas per 1690 ms. Failo sugeneravimo vidurkis - 1643 ms.

-10000000 įrašų – failas sukuriamas per 8964 ms, paskutinį kartą nuskaitytas per 13441 ms. Failo sugeneravimo vidurkis - 13487,8 ms.

Tikslas - sukurti programą, kuri gebėtų ne tik leisti naudotojui įvesti duomenis, bet ir nuskaitytų duomenis iš pateiktų failų.

Ši programa sukurta taip, kad galėtų:

-įvesti norimus studentų duomenis, t.y. vardą, pavardę, gautus pažymius bei egzamino įvertinimą;

-skaityti failus, kur namų darbų vertinimų arba studentų skaičius skirtingas;

-nuskaityti studentų sąrašus iš įvairaus tipo .txt formatų;

-pranešti apie naudotoją padarytą kokią nors (pvz.: loginę) klaidą;

-leisti naudotojui vesti pažymius pačiam arba generuoti automatiškai;

-skaičiuoti ne tik studentų vidurkius, bet ir rasti įvertinimų medianas;

-sortinti studentus ir pagal vardus, ir pagal pavardes, ir pagal vidurkius (naudotojo teisė rinktis);

-išvesti visų studentų bendrąjį kurso vidurkį, parodyti, kiek studentų kursą išlaikė (bendras įvertinimas >=4.5), o kiek neišlaikė (bendras įvertinimas <4.5);

-rezultatus atvaizduoti paprastoje, suformatuotoje, naudotojui suprantamoje lentelėje.


## ***V0.3 ATNAUJINIMAS:***
- Pridėta galimybė naudotojui pasirinkti, ar dirbti su vector, ar su list tipo konteineriu.
- Atliekama programos spartos analizė. Nuo šiol programa matuoja studentų rūšiavimo į dvi grupes laiką, pasirinkto studentų rikiavimo laiką bei įrašymo į rezultatų failą trukmę.

- Buvo atliekamas patikrinimas (testavimas) su 2 tipų konteineriais: vector, list. Testavimas atliktas su kompiuteriu, kurio parametrai: CPU - 2.8GHz, RAM - 24GB, SSD - 223GB. Gauti rezultatai pateikiami žemiau lentelėse:


I) **Studentų rikiavimas (pagal vardus)**
| Įrašų kiekis | Vector | List |
|:--------------|:----------:|-------:|
| 1000 |0.0004 s| 0.0001 s|
| 10000 |0.0039 s|0.001 s|
| 100000 |0.0375 s|0.0127 s|
| 1000000 | 0.453 s|0.1881 s|
| 10000000 |5.4857 s|2.2341 s|

**Studentų rikiavimo (pagal vardus) vidutinis laikas (testas atliktas 5 kartus), dirbant su 1000000 įrašų failu: vector - 0.431 s, list - 0.193 s.**

II) **Duomenų įrašymas į rezultatų failą**
| Įrašų kiekis | Vector | List |
|:--------------|:----------:|-------:|
| 1000 |0.0062 s|0.0736 s|
| 10000 | 0.0491 s| 0.049 s|
| 100000 |0.4679 s| 0.4685 s|
| 1000000 |4.7254 s| 4.8847 s|
| 10000000 |46.7826 s|46.2365 s|

**Studentų duomenų įrašymo į rezultatų failą vidutinis laikas (testas atliktas 5 kartus), dirbant su 1000000 įrašų failu: vector - 4.712 s, list - 4.8985 s.**

III) **Studentų rūšiavimas į grupes pagal įvertinimus**
| Įrašų kiekis | Vector | List |
|:--------------|:----------:|-------:|
| 1000 | 0.0004 s| 0.0003 s|
| 10000 |0.0034 s|0.0027 s|
| 100000 | 0.0295 s|0.0248 s|
| 1000000 | 0.2895 s|0.2594 s|
| 10000000 |3.1769 s|2.5181 s|

**Studentų rūšiavimo į grupes (pagal įvertinimus) vidutinis laikas (testas atliktas 5 kartus), dirbant su 1000000 įrašų failu: vector - 0.2911 s, list - 0.26 s.**


IŠVADA: Rezultatai pateikiami lentelėse yra nurodyti sekundėmis. Galima pastebėti, jog rikiavimas greičiau buvo atliekamas dirbant su list tipo konteineriu, duomenų įrašymas į rezultatų failą didelio laiko skirtumo nedaro, o studentų rūšiavimas į dvi grupes (vargšiukus ir kietekus) buvo greitesnis dirbant su list. Taigi, testavimas parodo, jog bendru atveju, dirbant su vector, darbas trunka ilgiau.


## **V1.0 GALUTINĖ VERSIJA**

Nuo šiol programa gali įgyvendinti 3 skirtingas strategijas (priklausomai nuo vartotojo pasirinkimo).
Pasirinkus pirmą - studentų skaidymui yra naudojami du konteineriai (vargšiukai ir kietiakai).
Pasirinkus antrą - studentų skaidymui yra panaudojamas tik vienas vargšiukų konteineris, o iš jo ištrinami studentai, kurie netenkina tam tikrų sąlygų.
Pasirinkus trečiąjį - studentu skaidymui yra naudojamas labiausiai optimizuotas (efektyvus) studentų rūšiavimas, todėl visas veikimo principas yra labai greitas.

***STUDENTŲ SKAIDYMAS PAGAL STRATEGIJAS***

Buvo atliekamas kiekvienos strategijos tyrimas. Kiekviena strategija su vector arba list tipo konteineriu buvo ištestuota tris kartus. Žemiau esančiose lentelėse yra pateikiami gauti rezultatai.

**1 strategija**

| Įrašų kiekis | Vector | List |
|:--------------|:----------:|-------:|
| 1000 | 0.0002 s| 0.0003 s|
| 10000 |0.0015 s| 0.0024 s|
| 100000 |0.0124 s| 0.0194 s|
| 1000000 | 0.124 s| 0.1889 s|
| 10000000 |1.2913 s|1.9058 s|

1000000 įrašų vidurkis (atliekant testavimą 10 kartų) vector konteineryje 0.122 s, list - 1.91 s.

**2 strategija**

| Įrašų kiekis | Vector | List |
|:--------------|:----------:|-------:|
| 1000 |0.0002 s| 0.0001 s|
| 10000 |0.002 s| 0.0014 s|
| 100000 | 0.0145 s|0.0152 s|
| 1000000 |0.1383 s|0.1626 s|
| 10000000 |1.4815 s| 1.6431 s|

1000000 įrašų vidurkis (atliekant testavimą 10 kartų) vector konteineryje 0.141 s, list - 0.1697 s.

**3 strategija**

| Įrašų kiekis | Vector | List |
|:--------------|:----------:|-------:|
| 1000 | 0.0001 s|0.0001 s|
| 10000 | 0.0006 s| 0.0001 s|
| 100000 |0.0047 s|0.004 s|
| 1000000 |0.0472 s| 0.0251 s|
| 10000000 |0.5178 s|0.2609 s|

1000000 įrašų vidurkis (atliekant testavimą 10 kartų) vector konteineryje 0.0455 s, list - 0.029 s.

Išvada: naudojant pirmos strategijos skaidymą list konteineris buvo apytiksliai 1.5 karto lėtesnis nei vector; naudojant antros strategijos rūšiavimą pranašesnis buvo taip pat vector konteineris, tačiau labai nežymiai - apie 15% kiekvienu atveju; naudojant trečios strategijos skaidymą rezultatai pasikeitė - buvo taikomi nauji algoritmai, kurie gerokai pagreitino procesą ir pranašumą įgijo list konteineris, kuris vidutiniškai buvo greitesnis du kartus nei vector.


## V1.1 VERSIJA
Programa nuo šiol yra realizuota su Class tipu, tačiau programos veikimo principas ir esmė nepasikeitusi. Atlikus pakeitimus buvo atlikti spartos analizės tyrimai su 100000 ir 1000000 įrašų studentų failais.
Gauti rezultatai pateikiami žemiau esančiose lentelėse.

### CLASS su 100000 studentų

| Optimizavimo lygis | Failo nuskaitymas | Studentų skaidymas |
|:--------------|:----------:|-------:|
| O1 | 1. 89 s| 0.0241 s|
| O2 | 1.86 s|0.0231 s|
| O3 | 1.84 s|0.0225 s|

### CLASS su 1000000 studentų

| Optimizavimo lygis | Failo nuskaitymas | Studentų skaidymas |
|:--------------|:----------:|-------:|
| O1 |22.9 s|0.2633 s|
| O2 | 22.6 s| 0.2539 s|
| O3 | 22.4 s|0.2517 s|

### STRUCT su 100000 studentų

| Optimizavimo lygis | Failo nuskaitymas | Studentų skaidymas |
|:--------------|:----------:|-------:|
| O1 |1.85 s| 0.235 s|
| O2 |1.83 s| 0.221 s|
| O3 |1.82 s| 0.2131 s|

### STRUCT su 1000000 studentų

| Optimizavimo lygis | Failo nuskaitymas | Studentų skaidymas |
|:--------------|:----------:|-------:|
| O1 | 23.4 s| 0.259 s|
| O2 | 22.5 s| 0.2471 s|
| O3 |22.2 s| 0.242 s|

IŠVADA: Optimizavo lygiai turėjo nedidelį poveikį tiek studentų failų nuskaitymui, tiek skaidymui į grupes. Įprastai laiko buvo mažesnis tik keliomis dešimtosiomis sekundės dalimis. Tikrinant 100000 ir 1000000 dydžio failus galima pastebėti, jog didesnio failo studentų skaidymo laikai buvo maždaug 11 kartų didesni.

### EXE failų dydžiai naudojant CLASS pagal optimizavimo lygį
#### O1 - 199 KB, O2 - 192 KB, O3 - 198 KB.
### EXE failų dydžiai naudojant STRUCT pagal optimizavimo lygį
#### O1 - 200 KB, O2 - 198 KB, O3 - 196 KB.



## V1.2 VERSIJA
Nuo šiol versijoje papildomai įgyvendinta:
a) „Rule of three“ turimai klasei Studentas - aprašytas kopijavimo konstruktorius, priskyrimo operatorius ir destruktorius;
b) realizuoti įvesties >> ir išvesties << operatoriai klasei Studentas.

Kiekvieno iš OPERATOR << arba >> konkretūs kodo pavyzdžiai yra pateikiami žemiau esančiose nuotraukose (nuotraukos yra padarytos iš programos failai.cpp ir studentas.cpp failuose esančių kodų).

### OPERATOR >>
1. Duomenys iš failo yra nuskaitomi su operator >> pagalba. Pavzydys: <img width="592" height="400" alt="image" src="https://github.com/user-attachments/assets/f3e332e9-8f46-4bca-b47b-484eddfd9a54" />

### OPERATOR <<
2. Išvesties operator << leidžia tvarkingai išvesti duomenis apie studentą. Pavyzdys: <img width="711" height="330" alt="image" src="https://github.com/user-attachments/assets/98d65b2a-df53-415d-b9bc-69cc1e85cc73" />

3. Operator << automatiškai parodo pirmojo studento iš sąrašo vardą, pavardę bei gautus nd įvertinimus ir egzamino įvertį. Pavyzdys: <img width="931" height="112" alt="image" src="https://github.com/user-attachments/assets/969e9f1f-2c50-4bbe-ba0e-632da3c5c7ac" />


### Rule Of Three realizavimas ir demonstracija
#### Kopijavimo konstruktoriaus realizacija
<img width="343" height="115" alt="image" src="https://github.com/user-attachments/assets/80fa490e-db37-4215-a6b4-b5b09154d8ec" />

#### Priskyrimo operatoriaus realizacija
<img width="413" height="157" alt="image" src="https://github.com/user-attachments/assets/5301fe79-71f4-410f-8a29-c88d193bf384" />

#### Destruktoriaus realizacija
<img width="203" height="105" alt="image" src="https://github.com/user-attachments/assets/0f20e7e7-d6aa-452e-a2d0-ec78503805a2" />

#### Visų demonstracija yra šiame kodo bloke:
<img width="502" height="187" alt="image" src="https://github.com/user-attachments/assets/1a1a16a9-d05e-46e1-9112-37833073f58b" />

IŠVADA: rankinis įvedimas paliktas taip, kaip buvo; nuskaitymas iš failo pakeistas - kiekviena eilutė nuo šiol nuskaitom su operator >> (kintam >> s); sugeneruoti failai vėliau gali būti nuskaitomi tokiu pačiu būdu, t.y. per operator >>; išvedimui į konsolę yra naudojamas operator << (cout << Grupe[0], cout << kopijuojamas ir t.t.); išvedimui į failą metodai palikti tie patys.


## V1.5 VERSIJA

Nuo šiol programa atnaujinta dar kartą. 
Visų pirma buvo sukurta abstrakti klasė Zmogus, įdėta virtuali funkcija (1 pav.), tai padarė Zmogus klasę abstrakčia, vadinasi, kurti naujų objektų nebegalima, taip pat buvo pridėtas virtualus destruktorius(2 pav.).

1 pav. <img width="504" height="40" alt="image" src="https://github.com/user-attachments/assets/de2e3b12-a3e1-431b-9c35-03b9fe71bd49" />

2 pav. <img width="229" height="36" alt="image" src="https://github.com/user-attachments/assets/e18bd639-00b4-439d-a8e4-8188cf5e42c3" />

Antra, klasė Studentas padaryta išvestine iš Zmogus. Studentas perima vardus ir pavardes iš Zmogus. Taip pat papildyta naująja bazinės klases virtualia funkcija (3 pav.). Dėl šios priežasties Studentas yra ne abstrakčia klase.

3 pav. <img width="472" height="59" alt="image" src="https://github.com/user-attachments/assets/724babee-b91e-45d3-875e-921d5c1b1a21" />

Žemiau esančioje nuotraukoje pateikiamas įrodymas, kad naujų objektų kūrimas yra negalimas (gaunamas pranešimas apie klaidingą programos vykdymą):
<img width="513" height="170" alt="image" src="https://github.com/user-attachments/assets/17dfa443-ceb6-4a7a-9831-00bbc6dc9e7c" />


Išvada: užduotis atlikta pagal visus reikalavimus, t.y. vietoje klasės Studentas sukurtos dvi: abstrakti klasė, aprašanti žmogų bei iš jos išvestinę klasę - Studentas, taip pat padaryta, kad žmogui skirta klasė yra abstrakti. Na, o visa kita veikimo logika - palikta ta pati, programa veikia taip, kaip veikdavo anksčiau (gali generuoti failus, nuskaityti failus arba dirbti su žmogaus ranka įvedamais (random būdu generuojamais) pažymiais).

## V2.0 VERSIJA

Šioje versijoje buvo:

1. sukurta dokumentacija panaudojant Doxygen;

2. realizuoti unit testai.

### PROGRAMOS DIEGIMO INSTRUKCIJA
a) Būtinai pasitikrinkite, ar įrenginyje yra idiegtas kompiliatorius su cmake;

b) Atsisiųskite visus reikalingus .cpp ir .h failus, taip pat nepamirškite ir labai svarbaus failo: CMakeLists.txt;

c)Susikurkite projektui naują vietą, pvz: C:\Projects*Projekto pavadinimas* ir sukelkite į projekto aplanką visus atsisiųstus failus;

d) Terminale rašykite šia eilės tvarka: pirmiausia nueikite į pagrindinį projekto katalogą: cd C:\*, tuomet mkdir build, įvykdę šiuos du etapus, terminale pereikiti į build katalogą: cd build, tada konfigūruokite: cmake .. ir, sėkmės atveju, kompiliuokite: cmake --build .

e) Viskas! studentu_valdymas.exe sukurtas sėkmingai, galite atsidaryti bei patikrinti programos veiksnumą! Atsidaryti galima rankiniu būdu arba terminale įvedus: Release\studentu_valdymas.exe


### TEST INSTRUKCIJA
<img width="592" height="717" alt="image" src="https://github.com/user-attachments/assets/e1ebf92f-3b38-4819-9a8c-5649371fc863" />

a) Norėdami paleisti testavimą pirmiausia consolėje turite atsirasti tam pačiame projekto aplanke: cd C:\* ;

b)Tuomet įveskite komandą, kuri sukompiliuos visą kodą: cl /EHsc /MDd /std:c++17 /I googletest-1.17.0\googletest\include studentas_test.cpp studentas.cpp mylib.cpp skaidymas.cpp failai.cpp /link /Fe:studentas_test.exe /LIBPATH:googletest-1.17.0\build\lib\Debug gtest.lib gtest_main.lib oldnames.lib

c) Paskutinis žingsnis - paleiskite testus: studentas_test.exe . Gautų rezultatų nuotrauka yra pateikiama žemiau:

<img width="597" height="428" alt="image" src="https://github.com/user-attachments/assets/a6810f96-fa09-422c-92bd-4814021c338c" />


### DOXYGEN PALEIDIMO INSTRUKCIJA
a) Atsisiųskite pateiktą aplankalą Doxygen_dokumentacija ir įkelkite į projekto aplanką;

b) Tuomet konsolėje nueikite į aplanką, kuriame yra projekto dokumentacija (Doxygen_dokumentacija): cd C:\*\Doxygen_dokumentacija ;

c) Tada veskite: start html\index.html ir būsite nukreiptas į dokumentacijos puslapį sėkmingai!
<img width="419" height="737" alt="image" src="https://github.com/user-attachments/assets/510191f2-be2f-47cd-9eae-7c8bf7f42d2f" />
