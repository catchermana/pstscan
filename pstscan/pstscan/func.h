#ifndef _FUNC_H_
#define _FUNC_H_
#include <iostream>
#include <string>
#include <vector>
#include<Winsock2.h>
#include <fstream>   //��д�ļ�����
#pragma comment(lib,"ws2_32.lib")

using namespace std;
using std::vector;

typedef unsigned long		DWORD;
typedef unsigned short      WORD;

struct startAndEndIP
{
	int    ipNum;
	string	startIp;
	string	endIp;
};
class CScan
{
	//һ���ȷź���
public:
	CScan();//���캯��
	~CScan();//��������
	void help();
	DWORD gethost();
	int  splitString(const std::string & strSrc, const std::string& strDelims, vector<string>& strDest);
	void getStartAndEndIP(char *host, startAndEndIP * mStartAndEndIP);
	int ipToint( const char *ip );
	char* intToip(DWORD ip_num);
	void ReadDataFromFileLBLIntoCharArray(const char *file,string &strDest);


	//Ȼ��ű���
private:
	DWORD	startIp;
	DWORD	endIp;
};

#endif // _FUNC_H_