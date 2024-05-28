#ifndef FUNCTII_H
#define FUNCTII_H
#include <iostream>
#include <fstream>
#include <vector>
#include "student.h"
#include "json.hpp"
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
void saveStudentsToFile(const vector<Student>& students, const string& filename)
{
    json j = students;
    ofstream o(filename);
    if (o.is_open())
    {
        o << j.dump(4);
        o.close();
    }
    else
    {
        cerr << "Failed to open file for writing: " << filename << endl;
    }
}

vector<Student> loadStudentsFromFile(const string& filename)
{
    ifstream i(filename);
    vector<Student> students;
    if (i.is_open())
    {
        json j;
        i >> j;
        students = j.get<vector<Student>>();
        i.close();
    }
    else
    {
        cerr << "Failed to open file for reading: " << filename << endl;
    }
    return students;
}
void addStudentToFile(const Student& newStudent, const string& filename)
{
    // Load existing students
    vector<Student> students = loadStudentsFromFile(filename);

    // Add the new student to the vector
    students.push_back(newStudent);

    // Save the updated list back to the file
    saveStudentsToFile(students, filename);
}
// Function to delete a student from the JSON file by their `nr_mat`
void deleteStudentFromFile(int nr_mat, const string& filename) {
    // Load existing students
    vector<Student> students = loadStudentsFromFile(filename);

    // Find and remove the student
    auto it = std::remove_if(students.begin(), students.end(),
                             [nr_mat](const Student& s) { return s.getnr_mat() == nr_mat; });

    if (it != students.end()) {
        students.erase(it, students.end());
        // Save the updated list back to the file
        saveStudentsToFile(students, filename);
    } else {
        cout << "Student with nr_mat " << nr_mat << " not found." << endl;
    }
}
// Serialize to JSON
vector<Student> students = loadStudentsFromFile("students.json");
json j = students;

void verifica (string x)
{
    // Write JSON to file
    ofstream o("Student.json");
    o << j.dump(4);
    o.close();

// Read JSON from file
    ifstream i("Student.json");
    json j2;
    i >> j2;
    int ok=0;
    if(x=="afiseaza")
    {
        ok=1;

        // Deserialize to Student object
        vector<Student> students = loadStudentsFromFile("students.json");
        json j = students;

        for (const auto& student : students)
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
        cout<<"Scrieti comanda 'adaugastudent' pentru a adauga un tudent in grupa "<<endl;
        cout<<"Scrieti comanda 'stergestudent' pentru a sterge un student din grupa "<<endl;

    }
    if(x=="adaugastudent")
    {
        ok=1;
        int nr,b,c,d;
        string e;
        float f,g,h,i;
        nr=students.size()+1;
        cout<<endl<<"Dati pe rand urmatoarele valori: nume, media de admitere, nota1, nota2, nota3 si data nasterii(zi-luna-an)"<<endl;
        cin>>e>>f>>g>>h>>i>>b>>c>>d;
        Student newStudent(nr,e,f,g,h,i,b,c,d);
        addStudentToFile(newStudent,"students.json");
    }
    if(x=="stergestudent")
    {
        ok=1;
        int a;
        cout<<"Dati numarul matricol al studentului care urmeaza sa fie sters "<<endl;
        cin>>a;
        deleteStudentFromFile(a,"students.json");
    }
    if(ok==0)
        cout<<"Comanda incorecta"<<endl;
}
#endif
