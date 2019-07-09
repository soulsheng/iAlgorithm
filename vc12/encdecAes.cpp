// encdecAes.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include "../src/iAes.h"
#include <tchar.h>
#include <time.h>
#include <fstream>
#include <iostream>
using namespace std;

#define FILE_TEST_IN		"D://world.jpg"//"D://mssd-2" world.jpg
#define FILE_TEST_MID		"D://cipher123.txt"////"D://cipher123.txt"
#define FILE_TEST_OUT		"D://world123.jpg"//"D://mssd-2x" world123.jpg

int _tmain(int argc, TCHAR* argv[])
{
	string pw("1234567890123456");
	CAES	aesEncDec;
	aesEncDec.AesInit((unsigned char*)pw.c_str(), 16, CAES::AES_ECB);


	long timeBegin = clock();

	aesEncDec.Encrypt_ECB(FILE_TEST_IN, FILE_TEST_MID);

	cout << "\n encryption time is: " << clock() - timeBegin;

	timeBegin = clock();

	aesEncDec.Decrypt_ECB(FILE_TEST_MID, FILE_TEST_OUT);

	cout << "\n decryption time is: " << clock() - timeBegin;


	return 0;
}

