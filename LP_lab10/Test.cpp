#include "stdafx.h"
#include <iostream>
#include <locale>
#include <cwchar>
#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "In.h"

////тест geterror & geterrorin
//int wmain(int argc, wchar_t* argv[])
//{
//	setlocale(LC_ALL, "rus");
//	cout << "----тест error::geterror    ---" << endl << endl;
//	try { throw ERROR_THROW(100); }
//	catch (Error::ERROR e)
//	{
//		cout << "ошибка " << e.id << ": " << e.message << endl << endl;
//	};
//
//	cout << "---- тест error::geterrorin    ---" << endl << endl;
//	try { throw ERROR_THROW_IN(111, 7, 7); }
//	catch (Error::ERROR e)
//	{
//		cout << "ошибка " << e.id << ": " << e.message
//			<< ", строка " << e.errorPosition.line
//			<< ", позиция " << e.errorPosition.col << endl << endl;
//	};
//
//	system("pause");
//	return 0;
//};
//-----------------------------------------------------------------------------------------------------------------------------------------------------
//тест getparm

//int wmain(int argc, wchar_t* argv[])
//{
//	setlocale(LC_ALL, "rus");
//	cout << "----тест Parm::getparm    ---" << endl << endl;
//	try 
//	{
//		Parm::PARM parm = Parm::getparm(argc, argv);
//		wcout << "-in:" << parm.in << ", -out:" << parm.out << ", -log:" << parm.log << endl << endl;
//	}
//	catch (Error::ERROR e)
//	{
//		cout << "Ошибка" << e.id << ": " << e.message << endl << endl;
//	};
//
//	system("pause");
//	return 0;
//};
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//тест getin

//int wmain(int argc, wchar_t* argv[])
//{
//	setlocale(LC_ALL, "rus");
//	cout << "----тест in::getin    ---" << endl << endl;
//	try 
//	{
//		Parm::PARM parm = Parm::getparm(argc, argv);
//		In::IN in = In::getin(parm.in);
//		cout << in.text << endl;
//		cout << "всего символов: " << in.size << endl;
//		cout << "всего строк: " << in.lines << endl;
//		cout << "пропущено: " << in.ignor << endl;
//	}
//	catch (Error::ERROR e)
//	{
//		cout << "ошибка" << e.id << ": " << e.message << endl << endl;
//		cout << "строка: " << e.errorPosition.line << " позиция " << e.errorPosition.col << endl << endl;
//	};
//
//	system("pause");
//	return 0;
//};