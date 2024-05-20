#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <numeric>
#include "student.h"
using namespace std;
int main()
{
    vector<Student> Grupa;
    Student a(1,"Popescu Ionut",7.8,6,8,8);
    Student b(2,"Alexandru Ion",10,10,10,10);
    Student c(3,"Val Mihai",5.5,4,4,4);
    Student d(4,"Enescu David",9.5,9,10,10);
    Student e(5,"Rusu Andrei",8.7,9,8,9);
    Student f(6,"Georgescu Andreea",7,7,9,10);
    Student g(7,"Chirila Denisa",8,6,5,7);
    Student h(8,"Istrate Marius",6,4,5,5);
    Student i(9,"Petrescu Cristian",8,9,8,8);
    Student j(10,"Coman Octavia",7,9,9,9);
    Grupa.push_back(a);
    Grupa.push_back(b);
    Grupa.push_back(c);
    Grupa.push_back(d);
    Grupa.push_back(e);
    Grupa.push_back(f);
    Grupa.push_back(g);
    Grupa.push_back(h);
    Grupa.push_back(i);
    Grupa.push_back(j);
    cout<<"Studentii care beneficiaza de burse de studii sunt: ";
    for(const Student &element : Grupa)
    {
        if(element.bursa() == 1)
            cout<<element.getnume()<<", ";
    }
    cout<<endl;
    cout<<"Studentii care beneficiaza de burse de merit sunt: ";
    for(const Student &element : Grupa)
    {
        if(element.bursa() == 2)
            cout<<element.getnume()<<", ";
    }
    cout<<endl;
    Grupa.erase(
    remove_if(Grupa.begin(), Grupa.end(),[](const Student &element) {return element.promovat() == 0; }),
    Grupa.end()
            );
    cout<<"Numarul studentilor din grupa dupa stergere este: "<<Grupa.size();
    cout<<endl;
    cout<<"Scrieti un numar matricol ";
    int x;
    cin>>x;
    int ok=0;
    for(const Student &element : Grupa)
    {
        if(element.getnr_mat() == x)
           {
            ok=1;
            cout<<element.getnume()<<" "<<element.getmed_adm()<<" "<<element.getnota1()<<" "<<element.getnota2()<<" "<<element.getnota3();
           }
    }
    if(ok==0)
        cout<<"Nu exista studentul cu numarul matricol "<<x;
    cout<<endl;
    return 0;
}
