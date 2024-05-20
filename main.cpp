#include <iostream>
#include <fstream>
#include "json.hpp"
#include "student.h"
using namespace std;
namespace nlohmann {
    void to_json(nlohmann::json& j, const Student& s) {
        j = nlohmann::json{{"nr_mat", s.getnr_mat()}, {"nume", s.getnume()}, {"med_adm", s.getmed_adm()}, {"nota1",s.getnota1()},{"nota2",s.getnota2()},{"nota3",s.getnota3()}};
    }

    void from_json(const nlohmann::json& j, Student& s) {
        j.at("nr_mat").get_to(s.setnr_mat());
        j.at("nume").get_to(s.setnume());
        j.at("med_adm").get_to(s.setmed_adm());
        j.at("nota1").get_to(s.setnota1());
        j.at("nota2").get_to(s.setnota2());
        j.at("nota3").get_to(s.setnota3());
    }
}
using json = nlohmann::json;

int main() {
    // Create a Student object
    Student a(1,"Popescu Ionut",7.8,6,8,8);

    // Serialize to JSON
    json j = a;
    std::cout << j.dump(4) << std::endl;

    // Write JSON to file
    std::ofstream o("student.json");
    o << j.dump(4);
    o.close();

    // Read JSON from file
    std::ifstream i("student.json");
    json j2;
    i >> j2;

    // Deserialize to Student object
    Student student2 = j2.get<Student>();
    std::cout << "Numar matricol: " << student2.getnr_mat() << ", Nume: " << student2.getnume()<< ", Medie admitere: " << student2.getmed_adm() << ", Nota1: "<<student2.getnota1()
    << ", Nota2: "<<student2.getnota2()<< ", Nota3: "<<student2.getnota3()<< std::endl;

    return 0;
}

