#pragma once

class _declspec(dllexport) CRC4
{
public:
	CRC4(void);
	~CRC4(void);

private:
	unsigned char* pRC4Key;
	int RC4KeySize;

	unsigned char* pRC4StreamKey;
	int RC4StreamKeySize;

	unsigned char State[256];
	unsigned char Temp[256];

public:
	inline unsigned int KeyMaxSize(void)
	{
		return 256;
	}

	inline unsigned int KeyMinSize(void)
	{
		return 1;
	}

public:
	bool InitKey(unsigned char* pKey, int KeySize);
	bool EncryptData(unsigned char* pBufferIn, int BufferInSize, unsigned char* pBufferOut, int BufferOutSize);
	bool DecryptData(unsigned char* pBufferIn, int BufferInSize, unsigned char* pBufferOut, int BufferOutSize);

private:
	bool SetKey(unsigned char* pKey, int KeySize);

private:
	void InitStateAndTemp();
	void RangeState();
	void KeyStream(int BufferLength);
};