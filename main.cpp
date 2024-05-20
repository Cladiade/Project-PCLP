#include <iostream>
#include <fstream>
#include "json.hpp"
#include "student.h"
using namespace std;
namespace nlohmann {
    void to_json(nlohmann::json& j, const elev& s) {
        j = nlohmann::json{{"nr_mat", s.getnr_mat()}, {"nume", s.getnume()}, {"med_adm", s.getmed_adm()}, {"nota1",s.getnota1()},{"nota2",s.getnota2()},{"nota3",s.getnota3()}};
    }

    void from_json(const nlohmann::json& j, elev& s) {
       s.setnr_mat(j.at("nr_mat").get<int>());
        s.setnume(j.at("nume").get<string>());
        s.setmed_adm(j.at("med_adm").get<double>());
        s.setnota1(j.at("nota1").get<double>());
        s.setnota2(j.at("nota2").get<double>());
        s.setnota3(j.at("nota3").get<double>());
    }
}
using json = nlohmann::json;

int main() {
    // Create a elev object
    elev a(1,"Popescu Ionut",7.8,6,8,8);

    // Serialize to JSON
    json j = a;
    cout << j.dump(4) << endl;

    // Write JSON to file
   ofstream o("elev.json");
    o << j.dump(4);
    o.close();

    // Read JSON from file
   ifstream i("elev.json");
    json j2;
    i >> j2;

    // Deserialize to elev object
    elev elev2 = j2.get<elev>();
    cout << "Numar matricol: " << elev2.getnr_mat() << ", Nume: " << elev2.getnume()<< ", Medie admitere: " << elev2.getmed_adm() << ", Nota1: "<<elev2.getnota1()
    << ", Nota2: "<<elev2.getnota2()<< ", Nota3: "<<elev2.getnota3()<< endl;

    return 0;
}

