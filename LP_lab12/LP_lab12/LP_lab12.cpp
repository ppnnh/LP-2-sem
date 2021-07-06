#include <iomanip>
#include <iostream>
#include "FST.h"

using namespace std;

//a(b)*(cb^+(d|e)f)^+b*g

int main() {
	setlocale(LC_CTYPE, "Russian");

	char line1[] = "abdbgb";
	FST::FST_linecheck(line1);

	char line2[] = "abcdbgb";
	FST::FST_linecheck(line2);

	char line3[] = "abcebcgb";
	FST::FST_linecheck(line3);

	char line4[] = "abcfbcgb";
	FST::FST_linecheck(line4);

	char line5[] = "abcfbgb";
	FST::FST_linecheck(line5);

	char line6[] = "abccdbcgb";
	FST::FST_linecheck(line6);

	char line7[] = "abcccfbccgb";
	FST::FST_linecheck(line7);

	char line8[] = "acfbgb";				//в цепочке нет обязательного символа 'b'
	FST::FST_linecheck(line8);

	char line9[] = "aabcfbgb";			//более одного символа 'a'
	FST::FST_linecheck(line9);

	return 0;
}