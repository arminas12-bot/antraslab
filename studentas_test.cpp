#include "gtest/gtest.h"
#include "studentas.h" 
#include "mylib.h"     


using std::vector;


TEST(PagalbinesFunkcijosTest, Vidurkis) {
    vector<double> pazymiai = { 10, 8, 9, 7 };
    ASSERT_NEAR(vidurkis(pazymiai), 8.5, 0.001);

    vector<double> tuscias;
    ASSERT_EQ(vidurkis(tuscias), 0.0);
}

TEST(PagalbinesFunkcijosTest, MedianaLyginis) {
    vector<double> pazymiai = { 10, 8, 9, 7 };
    ASSERT_NEAR(mediana(pazymiai), 8.5, 0.001);
}

TEST(PagalbinesFunkcijosTest, MedianaNelyginis) {
    vector<double> pazymiai = { 10, 8, 9, 7, 5 };
    ASSERT_NEAR(mediana(pazymiai), 8.0, 0.001);
}



TEST(StudentasTest, GalutinisVidurkis) {
    vector<double> nd = { 10, 10, 10 }; 
    double egzaminas = 5.0;
    Studentas s("Vardas", "Pavarde", nd, egzaminas);
    ASSERT_NEAR(s.galutinisvid(), 7.0, 0.001);
}

TEST(StudentasTest, Palyginimas) {
    Studentas s1("Ona", "Antanaite", {}, 10);
    Studentas s2("Jonas", "Jonauskas", {}, 8);
    Studentas s3("Petras", "Antanaite", {}, 5); 


    ASSERT_TRUE(s1 < s2);
    ASSERT_TRUE(s1 < s3);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}