#ifndef FUNCTII_H
#define FUNCTII_H
#include <iostream>
#include <fstream>
#include <vector>
#include "student.h"
#include "json.hpp"
#include <string.h>
using namespace std;
namespace nlohmann
{
void to_json(nlohmann::json& j, const Student& s)
{
    j = nlohmann::json{{"nr_mat", s.getnr_mat()}, {"nume", s.getnume()}, {"med_adm", s.getmed_adm()}, {"nota1",s.getnota1()},{"nota2",s.getnota2()},{"nota3",s.getnota3()},
        {"zi",s.getdatazi()},{"luna",s.getdataluna()},{"an",s.getdataan()}};
}

void from_json(const nlohmann::json& j, Student& s)
{
    s.setnr_mat(j.at("nr_mat").get<int>());
    s.setnume(j.at("nume").get<string>());
    s.setmed_adm(j.at("med_adm").get<double>());
    s.setnota1(j.at("nota1").get<double>());
    s.setnota2(j.at("nota2").get<double>());
    s.setnota3(j.at("nota3").get<double>());
    s.setdatazi(j.at("zi").get<int>());
    s.setdataluna(j.at("luna").get<int>());
    s.setdataan(j.at("an").get<int>());
}
}
using json = nlohmann::json;

// Create a Student object
vector<Student> Grupa =
{
    Student (1,"Popescu Ionut",7.8,6,8,8,4,1,2004),
    Student (2,"Marin Alexandru",8.5,9,8.5,9,2,6,2004),
    Student (3,"Georgescu Mihnea",5,4,4,4,12,9,2004),
    Student (4,"Val Mihai",5.5,4,4,4,6,2,2004),
    Student (5, "Rusu Andrei",8.7,9,8,9,5,10,2004),
    Student (6, "Georgescu Andreea",7,7,9,10,20,12,2004),
    Student (7, "Chirila Denisa",8,6,5,7,2,1,2005),
    Student (8, "Istrate Marius",6,4,5,5,3,7,2004),
    Student (9, "Petrescu Cristian",8,9,8,8,2,5,2005),
    Student (10, "Coman Octavia",7,9,9,9,13,9,2004)
};
// Serialize to JSON
json j = Grupa;

// Write JSON to file
ofstream o("Student.json");
o << j.dump(4);
o.close();

// Read JSON from file
ifstream i("Student.json");
json j2;
i >> j2;

void verifica (string x)
{
    int ok=0;
    if(x=="afiseaza")
    {
        ok=1;
        // Deserialize to Student object
        vector<Student> deserialized_students = j2.get<vector<Student>>();
        for (const auto& student : deserialized_students)
        {
            cout << "Numar matricol: " << student.getnr_mat() << ", Nume: " << student.getnume()<< ", Medie admitere: " << student.getmed_adm() << ", Nota1: "<<student.getnota1()
                 << ", Nota2: "<<student.getnota2()<< ", Nota3: "<<student.getnota3()<< ", Data nasterii: ";
            student.getdata();
            cout<<endl<<endl;
        }
    }
    if(x=="ajutor")
    {
        ok=1;
        cout<<endl;
        cout<<"Scrieti comanda 'afiseaza' pentru a afisa studentii din grupa "<<endl;
        cout<<"Scrieti comanda 'inchide' pentru a inchide corespunzator programul "<<endl;
    }
    if(ok==0)
        cout<<"Comanda incorecta"<<endl;
}
#endif
