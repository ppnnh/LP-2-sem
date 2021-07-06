
#include "stdafx.h"
using namespace std;
//1
typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;
struct Date {
	day dd;
	month mm;
	year yyyy;
};
bool operator == (Date date1, Date date2)
{
	bool rezult;
	if (date1.yyyy == date2.yyyy && date1.mm == date2.mm && date1.dd == date2.dd)
	{	rezult = true;}
	else { rezult = false; }
	return rezult;
};
bool operator <(Date date1, Date date2)
{
	bool rezult;
	if (date1.yyyy < date2.yyyy || date1.yyyy == date2.yyyy && date1.mm < date2.mm || date1.yyyy == date2.yyyy && date1.mm == date2.mm && date1.dd < date2.dd)
	{rezult = true;}
	else { rezult = false; }
	return rezult;
};
bool operator >(Date date1, Date date2)
{
	bool rezult;
	if (date1.yyyy > date2.yyyy || date1.yyyy == date2.yyyy && date1.mm > date2.mm || date1.yyyy == date2.yyyy && date1.mm == date2.mm && date1.dd > date2.dd)
	{	rezult = true;}
	else { rezult = false; }
	return rezult;
};


//2
typedef unsigned char fio;
typedef unsigned short vozrast;
typedef unsigned char pol;
typedef unsigned char specialnost;
typedef unsigned short kurs;
typedef unsigned short gruppa;
typedef unsigned short sredniy_ball;

struct Student {
	fio f;
	vozrast v;
	pol p;
	specialnost s;
	kurs k;
	gruppa g;
	sredniy_ball b;
};
bool operator ==(Student s1, Student s2) {
	bool rezult;
	if (s1.s == s2.s && s1.g == s2.g) { rezult = true; }
	else { rezult = false; }
	return rezult;
}
bool operator >(Student s1, Student s2) {
	bool rezult;
	if (s1.b > s2.b ) { rezult = true; }
	else { rezult = false; }
	return rezult;
}
int _tmain(int arg, _TCHAR* argv[])
{
	//1
	setlocale(LC_ALL, "rus");
	Date date1 = { 7,1,1980 };
	Date date2 = { 7,2,1990 };
	Date date3 = { 7,1,1980 };
	if (date1 < date2) { cout << "true\n" << endl; }
	else { cout << "false\n" << endl; }
	if (date1 > date2) { cout << "true\n" << endl; }
	else { cout << "false\n" << endl; }
	if (date1 == date2) { cout << "true\n" << endl; }
	else { cout << "false\n" << endl; }
	if (date1 == date3) { cout << "true\n" << endl; }
	else { cout << "false\n" << endl; }
	//2
	Student s1 = { 'Ivan',18,'m','poit',1,5,5.6 };
	Student s2 = { 'Stas',18,'m','poit',1,5,6.4 };
	if (s1 == s2) { cout << "s1 и s2 учатся в одной группе\n"; }
	else { cout << "s1 и s2 учатся в разных группах\n"; }
	if (s1 > s2) { cout << "у s1 средний балл выше, чем у s2\n"; }
	else {cout << "у s2 средний балл выше, чем у s1\n";}
	return 0;
} 
