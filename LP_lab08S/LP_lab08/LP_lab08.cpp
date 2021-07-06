#include "stdafx.h"
using namespace std;
#include "../../LP_lab08S/LP_lab08L/Dictionary.h"
#include <stdio.h>
#include <fstream>
using namespace Dictionary;

int main() {
	setlocale(LC_ALL, "Rus");
#if(defined(TEST_CREATE_01)+ defined(TEST_CREATE_02)+ defined(TEST_ADDENTRY_03)+ defined(TEST_ADDENTRY_04)+ defined(TEST_GETENTRY_05)+ defined(TEST_DELENTRY_06)+ defined(TEST_UPDENTRY_07)+ defined(TEST_UPDENTRY_08)+ defined(TEST_DICTIONARY) > 1)
#error вы можете выбрать только одну ошибку
#endif
	try {
#ifdef TEST_CREATE_01
		Instance k1 = Create((char*)"тееееееееееееееееееееееееееееееееееееееееееееееееееееееееееееест", 1);//переполнение по названию
#endif
#ifdef TEST_CREATE_02
		Instance k2 = Create((char*)"тест", 10000000000);//переполнение элементами
#endif
#ifdef  TEST_ADDENTRY_03
		Instance k3 = Create((char*)"тест", 0);//задаем библиотеку на 0 элементов
		Entry k = { 1,"название" };
		AddEntry(k3, k);//пытаемся добавить первый элемент
#endif
#ifdef  TEST_ADDENTRY_04
		Instance k4 = Create((char*)"тест", 7);
		Entry k = { 1,"название" };
		AddEntry(k4, k);//пытаемся дублировать идентификатор
		AddEntry(k4, k);
#endif
#ifdef  TEST_GETENTRY_05
		Instance k5 = Create((char*)"тест", 7);
		Entry k = { 1,"название" };
		AddEntry(k5, k);
		GetEntry(k5, 2);//вызываем по другому индентификатору
#endif
#ifdef  TEST_DELENTRY_06
		Instance k6 = Create((char*)"тест", 7);
		Entry k = { 1,"проверка" };
		AddEntry(k6, k);
		DelEntry(k6, 2);//так же 
#endif
#ifdef  TEST_UPDENTRY_07
		Instance k7 = Create((char*)"тест", 7);
		Entry k = { 1,"название" }, o = { 2,"название2" };
		AddEntry(k7, k);
		UpdEntry(k7, 3, o);//пытаемся вызвать по другому индентификатору
#endif
#ifdef  TEST_UPDENTRY_08
		Instance k8 = Create((char*)"тест", 7);
		Entry k = { 1,"название" }, o = { 2,"название2" };
		AddEntry(k8, o);
		UpdEntry(k8, 2, o);//т.к у о другой индентификатор, это будет выдавать ошибку
#endif
#ifdef TEST_DICTIONARY
		Instance d1 = Create((char*)"Преподаватели", 5);
		Entry e1 = { 1,"Гладкий" }, e2 = { 2,"Веялкин" }, e3 = { 3,"Смелов" }, e4 = { 4, "Урбанович" }, e5 = { 5, "Пацей" };
		AddEntry(d1, e1);
		AddEntry(d1, e2);
		AddEntry(d1, e3);
		AddEntry(d1, e4);
		AddEntry(d1, e5);
		Entry getE = GetEntry(d1, 5);
		DelEntry(d1, 2);
		Entry newentry1 = { 6, "Доморад" };
		UpdEntry(d1, 3, newentry1);
		Print(d1);

		Instance d2 = Create((char*)"Студенты", 5);
		Entry s1 = { 1,"Иванов" }, s2 = { 2,"Петров" }, s3 = { 3,"Сидоров" };
		AddEntry(d2, s1);
		AddEntry(d2, s2);
		AddEntry(d2, s3);
		Entry newentry3 = { 4, "Николаев" };
		UpdEntry(d2, 3, newentry3);
		Print(d2);
		Delete(d1);
		Delete(d2);
#endif
	}
	catch (char* e) {
		cout << e << endl;
	}
	return 0;
}