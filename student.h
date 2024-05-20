#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class elev
{
public:
    elev();
    elev(int,string,double,double,double,double);
    void setnr_mat(int);
    void setnume(string);
    void setmed_adm(double);
    void setnota1(double);
    void setnota2(double);
    void setnota3(double);
    int getnr_mat() const;
    string getnume() const;
    double getmed_adm() const;
    double getnota1() const;
    double getnota2() const;
    double getnota3() const;
    int situatie() const;
    int bursa() const;
    int promovat() const;
private:
    int nr_mat;
    string nume;
    double med_adm;
    double nota1;
    double nota2;
    double nota3;
};
elev::elev(int a, string b, double c, double d, double e, double f)
{
    nr_mat=a;
    nume=b;
    med_adm=c;
    nota1=d;
    nota2=e;
    nota3=f;
}
elev::elev()
{
    nr_mat=0;
    nume="nume";
    med_adm=0;
    nota1=0;
    nota2=0;
    nota3=0;
}
void elev::setnr_mat(int a)
{
    nr_mat=a;
}
void elev::setnume(string a)
{
    nume=a;
}
void elev::setmed_adm(double a)
{
    med_adm=a;
}
void elev::setnota1(double a)
{
    nota1=a;
}
void elev::setnota2(double a)
{
    nota2=a;
}
void elev::setnota3(double a)
{
    nota3=a;
}
int elev::getnr_mat() const
{
    return nr_mat;
}
string elev::getnume() const
{
    return nume;
}
double elev::getmed_adm() const
{
    return med_adm;
}
double elev::getnota1() const
{
    return nota1;
}
double elev::getnota2() const
{
    return nota2;
}
double elev::getnota3() const
{
    return nota3;
}
int elev::situatie() const
{
  if(nota1>=5&&nota2>=5&&nota3>=5)
        return 1;
  else
    return 0;
}
int elev::bursa() const
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
int elev::promovat() const
{
    if(nota1<5&&nota2<5&&nota3<5)
        return 0;
    else
        return 1;
}
