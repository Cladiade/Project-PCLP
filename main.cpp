#include <iostream>
#include "json.hpp"
#include "student.h"
#include "functii.h"
#include <string.h>
using namespace std;

int main()
{
    string x;
    cout<<endl<<"Scrieti comanda 'ajutor' pentru a afisa lista de comenzi"<<endl;
    cin>>x;
    while(x!="inchide")
    {
        verifica(x);
        cin>>x;
    }


    return 0;
}

