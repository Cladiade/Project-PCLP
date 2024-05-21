#ifndef DATA_H
#define DATA_H
using namespace std;
class Date
{
 public:
 //constructor implicit
 Date(int = 1, int = 1, int = 1990);
 void print() const;
 ~Date();
 int getzi();
 int getluna();
 int getan();
 void setzi(int);
 void setluna(int);
 void setan(int);
 private:
 int day; //1-12
 int month;//1-31
 int year;
 //functie utilitara de testare a
 //corectitudinii zilei pentru month si year
 int checkDay(int);
 Date(Date& p)
 {
 setzi(p.day);
 setluna(p.month);
 setan(p.year);
 }
 ostream& operator<<(ostream& o, Date& p){
    o << p.getzi() << '-' << p.getluna()<< '-' <<p.getan();
    return o;
}

};
#endif
