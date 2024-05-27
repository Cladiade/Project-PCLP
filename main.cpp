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
    // Create a Student object
    Student a(1,"Popescu Ionut",7.8,6,8,8,4,1,2004);

    // Serialize to JSON
    json j = a;
    cout << j.dump(4) << endl;

    // Write JSON to file
   ofstream o("Student.json");
    o << j.dump(4);
    o.close();

    // Read JSON from file
   ifstream i("Student.json");
    json j2;
    i >> j2;

    // Deserialize to Student object
    Student Student2 = j2.get<Student>();
    cout << "Numar matricol: " << Student2.getnr_mat() << ", Nume: " << Student2.getnume()<< ", Medie admitere: " << Student2.getmed_adm() << ", Nota1: "<<Student2.getnota1()
    << ", Nota2: "<<Student2.getnota2()<< ", Nota3: "<<Student2.getnota3()<< " ";
    Student2.getdata();
    cout<<endl;


    return 0;
}

