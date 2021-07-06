#include "stdafx.h"
#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "In.h"
#include "FST.h"
int wmain(int argc, wchar_t* argv[])
{
	setlocale(LC_ALL, "ru");
	int colp = 0;
	Log::LOG	log = Log::INTLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, "Тест: ", "без ошибок ", "");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
	Log:WriteIn(log, in);

		char String[100]{};
		for (int i = 0, j = 0; i < strlen((const char*)in.text); j++)
		{
			String[i++] = in.text[j];

			if (String[i - 1] == '|')
			{
				String[i - 1] = '\0';
				i = 0;

				FST::FST myFST(
					String,
					7,// количество состояний
					FST::NODE(1, FST::RELATION('a', 1)),// S0
					FST::NODE(1, FST::RELATION('b', 2)),// S1
					FST::NODE(4, FST::RELATION('c', 2), FST::RELATION('d', 3), FST::RELATION('e', 3), FST::RELATION('f', 3)), // S2
					FST::NODE(2, FST::RELATION('b', 4), FST::RELATION('b', 2)),// S3
					FST::NODE(2, FST::RELATION('c', 4), FST::RELATION('g', 5)),// S4
					FST::NODE(1, FST::RELATION('b', 6)),// S5
					FST::NODE()// S6
				);
				if (FST::execute(myFST))
				{
					colp++;
					std::cout << "\nЦепочка " << myFST.string << " распознана.\n";
					*log.stream << "\nЦепочка " << myFST.string << " распознана.\n";
				}
				else
				{
					colp++;
					std::cout << "\nЦепочка " << myFST.string << " не распознана. Ошибка распознавания. Строка: " << colp << " Символ: " << myFST.posp << "\n";
					*log.stream << "\nЦепочка " << myFST.string << " не распознана. Ошибка распознавания. Строка: " << colp << " Символ: " << myFST.posp << "\n";
				}
				strcpy_s(String, "");
			}
		}

		Log::Close(log);
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	}
	system("pause");
	return 0;

}