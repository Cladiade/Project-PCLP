#include <iostream>
#include <fstream>
#include "json.hpp"
#include "student.h"
#include <vector>
#include "functii.h"
#include <string.h>
using namespace std;

int main()
{
    string x;
    cout<<endl<<"Scrieti comanda 'ajutor' pentru a afisa lista de comenzi"<<endl;
    while(x!="inchide")
    {
        verifica(x);
    }


    return 0;
}

