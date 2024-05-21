#include <iostream>
using namespace std;
#include "data.h"
//constructor fara verificarea valorilor
Date::Date(int d, int m, int y)
{
 if(m > 0 && m <= 12)
 month = m;
 else {
 month = 1;
 cout << "Luna " << m << " incorecta. "
 << "Valoarea implicita este 1.\n";
 }
 year = y;
 day = checkDay(d); //valideaza ziua
}
//Tipareste data in forma zi-luna-an
void Date::print() const
 { cout << day << '-' << month << '-' << year; }
//Destructorul folosit pentru confirmarea stergerii obiectului
Date::~Date(){}

int Date::checkDay( int testDay )
{
 static const int daysPerMonth[13] =
 {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 if( testDay > 0 && testDay <= daysPerMonth[month])
 return testDay;

 //Februarie: test pentru an bisect
 if(month == 2 && testDay == 29 &&
 (year % 400 == 0 ||
 (year % 4 == 0 && year % 100 != 0)))
 return testDay;

 cout << "Ziua " << testDay << " incorecta. "
 << "Valoarea implicita este 1.\n";
 return 1;
}
int Date::getzi()
{
    return day;
}
int Date::getluna()
{
    return month;
}
int Date::getan()
{
    return year;
}
void Date::setan(int a)
{
  year=a;
}
void Date::setluna(int b)
{
    month=b;
}
void Date::setzi(int c)
{
    day=c;
}
