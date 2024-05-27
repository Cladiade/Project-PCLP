#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include "data.h"
using namespace std;
class Student
{
public:
    Student();
    Student(int,string,double,double,double,double,int,int,int);
    void setnr_mat(int);
    void setnume(string);
    void setmed_adm(double);
    void setnota1(double);
    void setnota2(double);
    void setnota3(double);
    void setdatazi(int);
    int getdatazi() const;
    int getnr_mat() const;
    string getnume() const;
    double getmed_adm() const;
    double getnota1() const;
    double getnota2() const;
    double getnota3() const;
    int situatie() const;
    int bursa() const;
    int promovat() const;
    void getdata();
    Student(const Student& other) = default;
    Student(Student&& other) = default;
    ~Student() = default;
private:
    int nr_mat;
    string nume;
    double med_adm;
    double nota1;
    double nota2;
    double nota3;
    Date datan;
};
Student::Student(int a, string b, double c, double d, double e, double f, int zi, int luna, int an)
:datan(zi,luna,an)
{
    nr_mat=a;
    nume=b;
    med_adm=c;
    nota1=d;
    nota2=e;
    nota3=f;
}
Student::Student():datan(1,1,100)
{
    nr_mat=0;
    nume="nume";
    med_adm=0;
    nota1=0;
    nota2=0;
    nota3=0;
}
void Student::setdatazi(int a)
{
    datan.setzi(a);
}
void Student::setnr_mat(int a)
{
    nr_mat=a;
}
void Student::setnume(string a)
{
    nume=a;
}
void Student::setmed_adm(double a)
{
    med_adm=a;
}
void Student::setnota1(double a)
{
    nota1=a;
}
void Student::setnota2(double a)
{
    nota2=a;
}
void Student::setnota3(double a)
{
    nota3=a;
}
int Student::getnr_mat() const
{
    return nr_mat;
}
int Student::getdatazi() const
{
  return datan.getzi();
}
string Student::getnume() const
{
    return nume;
}
double Student::getmed_adm() const
{
    return med_adm;
}
double Student::getnota1() const
{
    return nota1;
}
double Student::getnota2() const
{
    return nota2;
}
double Student::getnota3() const
{
    return nota3;
}
int Student::situatie() const
{
  if(nota1>=5&&nota2>=5&&nota3>=5)
        return 1;
  else
    return 0;
}
int Student::bursa() const
{
    if(nota1>=5&&nota2>=5&&nota3>=5)
    {
        if((nota1+nota2+nota3)/3>=9.5)
            return 2;
        else
            if((nota1+nota2+nota3)/3>=8.5)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}
int Student::promovat() const
{
    if(nota1<5&&nota2<5&&nota3<5)
        return 0;
    else
        return 1;
}
void Student::getdata()
{
datan.printD();
}
