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
void deleteStudentFromFile(int nr_mat, const string& filename)
{
    // Load existing students
    vector<Student> students = loadStudentsFromFile(filename);

    // Find and remove the student
    auto it = std::remove_if(students.begin(), students.end(),
                             [nr_mat](const Student& s)
    {
        return s.getnr_mat() == nr_mat;
    });

    if (it != students.end())
    {
        students.erase(it, students.end());
        // Save the updated list back to the file
        saveStudentsToFile(students, filename);
    }
    else
    {
        cout << "Student with nr_mat " << nr_mat << " not found." << endl;
    }
}
void AfiseazaBursaMerit(const string& filename)
{
    vector<Student> students = loadStudentsFromFile(filename);

    cout <<"Studentii cu bursa de merit sunt "<< endl;
    for (const auto& student : students)
    {
        if (student.bursa()==2)
        {
            cout << "Numar matricol: " << student.getnr_mat() << ", Nume: " << student.getnume()<< ", Medie admitere: " << student.getmed_adm() << ", Nota1: "<<student.getnota1()
                 << ", Nota2: "<<student.getnota2()<< ", Nota3: "<<student.getnota3()<< ", Data nasterii: ";
            student.getdata();
            cout<<endl<<endl;

        }
    }
}
void AfiseazaBursaStudii(const string& filename)
{
    vector<Student> students = loadStudentsFromFile(filename);

    cout <<"Studentii cu bursa de merit sunt "<< endl;
    for (const auto& student : students)
    {
        if (student.bursa()==1)
        {
            cout << "Numar matricol: " << student.getnr_mat() << ", Nume: " << student.getnume()<< ", Medie admitere: " << student.getmed_adm() << ", Nota1: "<<student.getnota1()
                 << ", Nota2: "<<student.getnota2()<< ", Nota3: "<<student.getnota3()<< ", Data nasterii: ";
            student.getdata();
            cout<<endl<<endl;
        }
    }
}
void SchimbaNr_mat(int a,int b,const string& filename)
{
    vector<Student> students = loadStudentsFromFile(filename);
    auto th = std::find_if(students.begin(), students.end(),
                           [b](const Student& s)
    {
        return s.getnr_mat() == b;
    });
    if(th != students.end())
        cout<<"Exista deja un student cu acest numar matricol "<<endl;
    else
    {
        auto it = std::find_if(students.begin(), students.end(),
                               [a](const Student& s)
        {
            return s.getnr_mat() == a;
        });

        if (it != students.end())
        {
            it->setnr_mat(b);
            saveStudentsToFile(students, filename);
        }
        else
            cout << "Studentul cu numarul matricol " << a << " nu a fost gasit" << endl;
    }
}
void SchimbaNume(int a,string b,const string& filename)
{
    vector<Student> students = loadStudentsFromFile(filename);

    auto it = std::find_if(students.begin(), students.end(),
                           [a](const Student& s)
    {
        return s.getnr_mat() == a;
    });

    if (it != students.end())
    {
        it->setnume(b);
        saveStudentsToFile(students, filename);
    }
    else
        cout << "Studentul cu numarul matricol " << a << " nu a fost gasit" << endl;
}
void SchimbaMed_adm(int a,float b,const string& filename)
{
    vector<Student> students = loadStudentsFromFile(filename);

    auto it = std::find_if(students.begin(), students.end(),
                           [a](const Student& s)
    {
        return s.getnr_mat() == a;
    });

    if (it != students.end())
    {
        it->setmed_adm(b);
        saveStudentsToFile(students, filename);
    }
    else
        cout << "Studentul cu numarul matricol " << a << " nu a fost gasit" << endl;
}
void SchimbaNota1(int a,float b,const string& filename)
{
    vector<Student> students = loadStudentsFromFile(filename);

    auto it = std::find_if(students.begin(), students.end(),
                           [a](const Student& s)
    {
        return s.getnr_mat() == a;
    });

    if (it != students.end())
    {
        it->setnota1(b);
        saveStudentsToFile(students, filename);
    }
    else
        cout << "Studentul cu numarul matricol " << a << " nu a fost gasit" << endl;
}
void SchimbaNota2(int a,float b,const string& filename)
{
    vector<Student> students = loadStudentsFromFile(filename);

    auto it = std::find_if(students.begin(), students.end(),
                           [a](const Student& s)
    {
        return s.getnr_mat() == a;
    });

    if (it != students.end())
    {
        it->setnota2(b);
        saveStudentsToFile(students, filename);
    }
    else
        cout << "Studentul cu numarul matricol " << a << " nu a fost gasit" << endl;
}
void SchimbaNota3(int a,float b,const string& filename)
{
    vector<Student> students = loadStudentsFromFile(filename);

    auto it = std::find_if(students.begin(), students.end(),
                           [a](const Student& s)
    {
        return s.getnr_mat() == a;
    });

    if (it != students.end())
    {
        it->setnota3(b);
        saveStudentsToFile(students, filename);
    }
    else
        cout << "Studentul cu numarul matricol " << a << " nu a fost gasit" << endl;
}
void SchimbaDataN(int a,int b,int c,int d,const string& filename)
{
    vector<Student> students = loadStudentsFromFile(filename);

    auto it = std::find_if(students.begin(), students.end(),
                           [a](const Student& s)
    {
        return s.getnr_mat() == a;
    });

    if (it != students.end())
    {
        it->setdatazi(b);
        it->setdataluna(c);
        it->setdataan(d);
        saveStudentsToFile(students, filename);
    }
    else
        cout << "Studentul cu numarul matricol " << a << " nu a fost gasit" << endl;
}
void StergeStudentiSlabi(const string& filename)
{
    vector<Student> students = loadStudentsFromFile(filename);

    auto it = std::remove_if(students.begin(), students.end(),
                             [](const Student& s)
    {
        return !s.promovat();
    });

    if (it != students.end())
    {
        students.erase(it, students.end());
        // Save the updated list back to the file
        saveStudentsToFile(students, filename);
    }
    else
    {
        cout << "Toti studentii au promovat " << endl;
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
        cout<<"Scrieti comanda 'AFISARE' pentru mai multe moduri de afisare a studentilor "<<endl;
        cout<<"Scrieti comanda 'sterge_nepromovati' pentru a sterge studentii care nu au promovat "<<endl;
        cout<<"Scrieti comanda 'modifica' pentrua modifica datele unui student "<<endl;
    }
    if(x=="adaugastudent")
    {
        ok=1;
        int nr,b,c,d;
        string e;
        float f,g,h,i;
        vector<Student> students = loadStudentsFromFile("students.json");
        if(students.empty())
            nr=1;
        else
        {
            const Student& ultimul = students.back();
            nr=ultimul.getnr_mat();
        }
        cout<<endl<<"Dati pe rand urmatoarele valori: nume, media de admitere, nota1, nota2, nota3 si data nasterii(zi-luna-an)"<<endl;
        cin>>e>>f>>g>>h>>i>>b>>c>>d;
        Student newStudent(nr+1,e,f,g,h,i,b,c,d);
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
    if(x=="AFISARE")
    {
        ok=1;
        string y;
        cout<<"Pentru a afisa studentii cu bursa de merit scrieti: 'bursa_merit'"<<endl;
        cout<<"Pentru a afisa studentii cu bursa de studii scrieti: 'bursa_studii'"<<endl;
        cout<<"Pentru a anula comanda scrieti: 'anuleaza'"<<endl;
        int ok1=0;
        while(ok1==0)
        {
            cin>>y;
            if(y=="bursa_merit")
            {
                ok1=1;
                AfiseazaBursaMerit("students.json");
            }
            if(y=="bursa_studii")
            {
                ok1=1;
                AfiseazaBursaStudii("students.json");
            }
            if(y=="anulare")
            {
                ok1=1;
                cout<<"Comanda a fost anulata"<<endl;
            }
            if(ok1==0)

                cout<<"Comanda incorecta"<<endl;

        }
    }
    if(x=="sterge_nepromovati")
    {
        ok=1;
        StergeStudentiSlabi("students.json");
    }
    if(x=="modifica")
    {
        ok=1;
        cout<<"Scrieti numarul matricol al studenului caruia vreti sa ii modficati datele "<<endl;
        int a;
        cin>>a;
        cout<<"Scrieti ce vreti sa modificati: numar_matricol, nume, media_admitere, nota1, nota2, nota3, data_nastere "<<endl;
        string y;
        int ok1=0;
        while(ok1==0)
        {
            cin>>y;
            if(y=="numar_matricol")
            {
                ok1=1;
                int b;
                cout<<"Scrieti noul numar matricol "<<endl;
                cin>>b;
                SchimbaNr_mat(a,b,"students.json");
            }
            if(y=="nume")
            {
                ok1=1;
                string c;
                cout<<"Scrieti noul nume "<<endl;
                cin>>c;
                SchimbaNume(a,c,"students.json");
            }
            if(y=="media_admitere")
            {
                ok1=1;
                float d;
                cout<<"Scrieti noua medie "<<endl;
                cin>>d;
                SchimbaMed_adm(a,d,"students.json");
            }
            if(y=="nota1")
            {
                ok1=1;
                float e;
                cout<<"Scrieti noua nota "<<endl;
                cin>>e;
                SchimbaNota1(a,e,"students.json");
            }
            if(y=="nota2")
            {
                ok1=1;
                float f;
                cout<<"Scrieti noua nota "<<endl;
                cin>>f;
                SchimbaNota2(a,f,"students.json");
            }
            if(y=="nota3")
            {
                ok1=1;
                float g;
                cout<<"Scrieti noua nota "<<endl;
                cin>>g;
                SchimbaNota3(a,g,"students.json");
            }
            if(y=="data_nastere")
            {
                ok1=1;
                int h,i,j;
                cout<<"Scrieti noua data(zi,luna,an) "<<endl;
                cin>>h>>i>>j;
                SchimbaDataN(a,h,i,j,"students.json");
            }
            if(ok1==0)
            {
                ok1=1;
                cout<<"Comanda gresita "<<endl;
            }
        }
    }
    if(ok==0)
        cout<<"Comanda incorecta"<<endl;
}

#endif
