#ifndef _FUNC_H_
#define _FUNC_H_
#include <iostream>
#include <string>
#include <vector>
#include<Winsock2.h>
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
	//一般先放函数
public:
	CScan();//构造函数
	~CScan();//析构函数
	void help();
	DWORD gethost();
	int  splitString(const std::string & strSrc, const std::string& strDelims, vector<string>& strDest);
	void getStartAndEndIP(char *host, startAndEndIP * mStartAndEndIP);
	int ipToint( const char *ip );

	//然后放变量
private:
	DWORD	startIp;
	DWORD	endIp;
};

#endif // _FUNC_H_