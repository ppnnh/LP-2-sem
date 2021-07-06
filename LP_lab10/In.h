#pragma once


#define IN_MAX_LEN_TEXT 1024*1024
#define IN_CODE_ENDL '\n'

//мир
//#define IN_CODE_TABLE {\
//IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,\
//IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,\
//IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,\
//IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,\
//IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,\
//IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::I,	 '!',	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,\
//IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,\
//IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,\
//\
//IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,\
//IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,\
//IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,\
//IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,\
//IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,\
//IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,\
//IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,\
//IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,	IN::T,\
//}
#define IN_CODE_TABLE {\
IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,\
IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,\
IN::T,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::T,	IN::I,	IN::I,\
IN::T,	IN::I,	IN::T,	IN::T,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,\
IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,\
IN::I,	IN::I,	IN::I,	IN::T,	IN::I,	IN::I,	IN::T,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,\
IN::I,	IN::T,	IN::I,	IN::I,	IN::I,	IN::T,	IN::I,	IN::I,	IN::I,	IN::T,	IN::I,	IN::T,	IN::T,	IN::I,	IN::T,	IN::T,\
IN::I,	IN::I,	IN::T,	IN::I,	IN::I,	IN::T,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,\
\
IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,\
IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,\
IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,\
IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,\
'-',	IN::T,	IN::T,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::T,	IN::I,	IN::I,\
IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,\
IN::T,	IN::I,	IN::I,	IN::I,	IN::I,	IN::T,	IN::I,	IN::I,	IN::T,	IN::I,	IN::T,	IN::T,	IN::I,	IN::T,	IN::T,	IN::I,\
IN::T,	IN::I,	IN::I,	IN::T,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::I,	IN::T,\
}

namespace In
{
	struct IN
	{
		enum { T = 1, F = 2, I = 3 };
		int size;
		int lines;
		int ignor;
		unsigned char* text;
		int code[256] = IN_CODE_TABLE;

		IN()
		{
			this->size = this->ignor = 0;
			this->lines = 1;
			this->text = new unsigned char[IN_MAX_LEN_TEXT];
		}
	};

	IN getin(wchar_t infile[]); // ввести и проверить входной поток кода (Windows - 1251)

};