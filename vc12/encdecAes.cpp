// encdecAes.cpp : �������̨Ӧ�ó������ڵ㡣
//

//#include "stdafx.h"
#include "../src/iAes.h"
#include <tchar.h>
#include <time.h>
#include <fstream>
#include <iostream>
using namespace std;

#define BATCH_SIZE		4
#define BLOCK_SIZE		16
#define FILE_TEST_IN		"D://world.jpg"//"D://mssd-2" world.jpg
#define FILE_TEST_MID		"D://cipher123.txt"////"D://cipher123.txt"
#define FILE_TEST_OUT		"D://world123.jpg"//"D://mssd-2x" world123.jpg
#define HANDLE_ONCE		1

int _tmain(int argc, TCHAR* argv[])
{
	string pw("1234567890123456");
	CAES	aesEncDec;
	aesEncDec.AesInit((unsigned char*)pw.c_str(), BLOCK_SIZE, CAES::AES_ECB);


	long timeBegin = clock();

#if HANDLE_ONCE

	aesEncDec.Encrypt_ECB(FILE_TEST_IN, FILE_TEST_MID);

#else

	char	pBlockByteIn[BLOCK_SIZE * BATCH_SIZE];
	char	pBlockByteOut[BLOCK_SIZE * BATCH_SIZE];
	// ���ļ� flower.jpg ���ܵ� cipher.txt ��  
	ifstream in;
	ofstream out;

	out.open(FILE_TEST_MID, ios::binary);
	in.open(FILE_TEST_IN, ios::binary);

	while (in.read((char*)&pBlockByteIn, sizeof(pBlockByteIn)))
	{
		for (int i = 0; i < BATCH_SIZE;i++)
			aesEncDec.Encrypt_ECB((unsigned char*)(pBlockByteIn + i*BLOCK_SIZE), BLOCK_SIZE, 
			(unsigned char*)(pBlockByteOut + i*BLOCK_SIZE), BLOCK_SIZE);

		out.write(pBlockByteOut, sizeof(pBlockByteOut));
	}

	in.close();
	out.close();

#endif

	cout << "\n encryption time is: " << clock() - timeBegin;

	timeBegin = clock();

#if HANDLE_ONCE

	aesEncDec.Decrypt_ECB(FILE_TEST_MID, FILE_TEST_OUT);
	
#else
	// ���� cipher.txt����д��ͼƬ flower1.jpg  

	in.open(FILE_TEST_MID, ios::binary);
	out.open(FILE_TEST_OUT, ios::binary);

	while (in.read((char*)&pBlockByteIn, sizeof(pBlockByteIn)))
	{
		for (int i = 0; i < BATCH_SIZE; i++)	
			aesEncDec.Decrypt_ECB((unsigned char*)(pBlockByteIn + i*BLOCK_SIZE), BLOCK_SIZE,
			(unsigned char*)(pBlockByteOut + i*BLOCK_SIZE), BLOCK_SIZE);

		out.write(pBlockByteOut, sizeof(pBlockByteIn));
	}
	in.close();
	out.close();

#endif

	cout << "\n decryption time is: " << clock() - timeBegin;


	return 0;
}

