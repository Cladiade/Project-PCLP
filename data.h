#ifndef DATA_H
#define DATA_H
using namespace std;
class Date
{
 public:
 //constructor implicit
 Date(): day(1), month(1), year(100){}
 //constructor explicit
 Date(int = 1, int = 1, int = 1990);
 Date(const Date& other) = default;
 Date(Date&& other) = default;
 void print() const;
 ~Date();
 int getzi();
 int getluna();
 int getan();
 void setzi(int);
 void setluna(int);
 void setan(int);
 void printD() const;
 private:
 int day; //1-12
 int month;//1-31
 int year;
 //functie utilitara de testare a
 //corectitudinii zilei pentru month si year
 int checkDay(int);
};
#endif
