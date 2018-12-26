#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>
#include <array>

using namespace std;

int Devnum = 0;
const char* filepath="D:\\data";

int main()
{
	/*const char* defaultPath = "D:\database\\test";
	const char* folderPath = "\\testFolder";
	char finalpath[100];
	sprintf(finalpath, "%s%s", defaultPath, folderPath);
	printf("%s", finalpath);*/

	char finalpath [200];
	sprintf(finalpath, "%s\\Camera%d_Image", filepath, Devnum);

	CreateDirectory(filepath, NULL);
	CreateDirectory(finalpath, NULL);
	// flag ? true ??????

	return 0;
}
