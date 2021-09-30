#include "stdafx.h"
#include <iostream>
#include <Windows.h>

using namespace std;

char* UpperW1251(char* destination, char* source)
{
	for (int i = 0; i < strlen(source); i++)
		if (((source[i] >= 97) && (source[i] <= 122)) || ((source[i] >= -32) && (source[i] <= -1)))
			destination[i] = source[i] - 32;
		else destination[i] = source[i];
	return destination;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char source[] = "12345sdfghjйцгшщз";
	char destination[] = "124567890123456789";

	UpperW1251(destination, source);

	cout << destination << endl;
	system("pause");
	return 0;
}