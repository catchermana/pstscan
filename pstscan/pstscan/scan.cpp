#include "scan.h"
#include "func.h"
using namespace std;


int ReadAndSanitizeInput(FILE *file, char *buffer,int len) 
{
	//read a line from a file stream, and removes '\r' and '\n'
	//if the line is not a comment, true is returned
	fgets(buffer,len,file);
	buffer[len-1]='\0';
	unsigned int bufferSize = ( unsigned int ) strlen(buffer);
	if ( (bufferSize>3) && buffer[0]!='#'  && buffer[0]!=';'  ) 
	{
		char *p=buffer+bufferSize-1;
		while ( (*p=='\r' ) || (*p=='\n') || (*p==' ') )
		{
			p[0]='\0'; 
			--p; 
		}
		return(1);
	}
	return(0);
}


int main(int argc, char *argv[]) 
{

	char *host = "192.168.1.1-192.168.1.254";
	//int port = 6379;       //自定义端口
	//char szHostName[200];     //保存主机名
	//host = argv[1];
	int ipNum = 0;      //ip 数量
	DWORD intIpStart;   //int 类型开始ip
	DWORD intIpEnd;     //int 类型结束ip
	string _startIp;    //开始ip
	string _endIp;      //结束ip
	
	const char *file = "user.txt";
	char ip[1024];
	char user[1000];
	/*
	if ( strcmp(argv[1],"-host") == 0)
	{
		std::cout << "host" << endl;
	}
	else if ( strcmp(argv[1],"-file") == 0)
	{
		std::cout << "file" << endl;
	}
	else
	{
		return 0;
	}
	*/
	
	CScan * mScan = new CScan();
	//DWORD ipint = 3232235777;
	
	startAndEndIP mStartAndEndIp;
	mScan->getStartAndEndIP(host, &mStartAndEndIp);

	_startIp = mStartAndEndIp.startIp;
	_endIp = mStartAndEndIp.endIp;
	
	intIpStart = mScan->ipToint(_startIp.c_str()); //string to const char
	intIpEnd   = mScan->ipToint(_endIp.c_str());
	ipNum = intIpEnd - intIpStart; 

	//mScan->intToip(ipint);
	//mScan->help();
	//mScan->ReadDataFromFileLBLIntoCharArray(file,ip);
	mScan->ReadDataFromFileLBLIntoCharArray(file,user);
	
	return 0;
}