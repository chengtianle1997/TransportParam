#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>
#include <array>

using namespace std;

int main()
{
	const char* defaultPath = "D:\\database";
	const char* folderPath = "\\testFolder";
	char finalpath[100];
	sprintf(finalpath, "%s%s", defaultPath, folderPath);
	printf("%s", finalpath);


	CreateDirectory(defaultPath, NULL);
	CreateDirectory(finalpath, NULL);
	// flag ? true ??????

	return 0;
}
