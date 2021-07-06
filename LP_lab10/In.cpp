#include <fstream>
#include <string>
#include "In.h"
#include "Error.h"

using namespace std;

namespace In
{
	IN getin(wchar_t* infile)
	{
		IN inner_text;

		ifstream file;
		file.open(infile);

		if (!file)
			throw ERROR_THROW(110);
		inner_text.text = new unsigned char[IN_MAX_LEN_TEXT];

		char unsigned tempChar;
		int position = 0;
		int positionArray = 0;

		bool flagEmptyFile = true;

		while ((tempChar = file.get()) && !file.eof())
		{
			flagEmptyFile = false;

			if (tempChar == IN_CODE_ENDL)
			{
				inner_text.text[positionArray++] = IN_CODE_ENDL;
				inner_text.size++;
				inner_text.lines++;
				position = 0;
				continue;
			}

			switch (inner_text.code[tempChar])
			{
			case IN::T:
			{
				inner_text.text[positionArray++] = tempChar;
				inner_text.size++;
				position++;
				break;
			}

			case IN::I:
			{
				inner_text.ignor++;
				inner_text.size++;
				position++;
				break;
			}

			case IN::F:
			{

				throw ERROR_THROW_IN(111, inner_text.lines, position + 1);
				break;
			}

			default:
			{
				inner_text.text[positionArray++] = inner_text.code[tempChar];
				inner_text.size++;
				position++;
				break;
			}

			}
		}
		inner_text.text[positionArray++] = '\0';
	
		if (flagEmptyFile)	throw ERROR_THROW(113);

		if (inner_text.size == 0)
			inner_text.lines = 0;

		file.close();
		return inner_text;
	}
}
