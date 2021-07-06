#pragma once
#include <iostream>
#include <locale>
#include <cstdarg>

namespace Call {

	int _cdecl cdevl(int& a, int& b, int& c);

	int _stdcall cstd(int& a, int b, int c);

	int _fastcall cfst(int a, int b, int c);

};
