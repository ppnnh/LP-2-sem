#include "stdafx.h"
#include <locale>
#include <cwchar>
using namespace std;

int wmain(int argc, wchar_t* argv[])
{
	setlocale(LC_ALL, "Russian");

	Log::LOG log=Log::INTLOG;

		try
		{
			Parm::PARM param = Parm::getparm(argc, argv);
			Log::LOG log = Log::getlog(param.log);
			Log::WriteLine(log, "Тест: ", "без ошибок\n", "");
			Log::WriteLog(log);
			Log::WriteParm(log, param);
			In::IN in = In::getin(param.in);
			cout << in.text << endl;
			Log::WriteIn(log, in);
			Log::Close(log);
		}
		catch (Error::ERROR e)
		{
			Log::WriteError(log, e);
		}
		system("pause");
		return 0;
	}