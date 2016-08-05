#include "func.h"

using namespace std;
using std::vector;

CScan::CScan()
{

}

void CScan::help()
{
	cout << "<Usage>: " << '\n'
		<< "\tscan.exe -host [HostName|startIP<-endIP>] <Options> [plugins]" << '\n'
		<< "\tscan.exe -file HostListFile <Options> [Plugins]" << '\n'
		<< std::endl;

	cout << "<Options>:" << '\n'
		<< "\t-m thread     : max thread count, default: 256" << '\n'
		<< "\t-m2 thread    : max thread count in each ip, default: 3" << '\n'
		<< "\t-t timeout    : timed out in ms, default: 10" << '\n'
		<< "\t-s sleeptime  : sleep ms during ip, default: 10" << '\n'
		<< "\t-v            : verbose mode, more information" << '\n'
		<< std::endl;

	cout << "<Plugins>:" << '\n'
		<< "\t-ipc (-admin) : ipc accounts scan" << '\n'
		<< "\t-ftp          : ftp accounts scan" << '\n'
		<< "\t-pop3         : pop3 accounts scan" << '\n'
		<< "\t-ssh          : imap accounts scan" << '\n'
		<< "\t-mail         : mail accounts scan" << '\n'
		<< "\t-mssql        : mssql accounts scan" << '\n'
		<< "\t-mysql        : mysql accounts scan" << '\n'
		<< "\t-middle       : midlle vulnerabilities scan" << '\n'
		<< "\t-all          : scan all the plugins" << '\n'
		<< std::endl;
}

//分割字符并返回字符数组  
int  CScan::splitString(const string & strSrc, const std::string& strDelims, vector<string>& strDest)
{
	typedef string::size_type ST;
	string delims = strDelims;
	std::string STR;
	if (delims.empty())
	{
		delims = "/n/r";
	}

	ST pos = 0, LEN = strSrc.size();

	while (pos < LEN)
	{
		STR = "";
		while ((delims.find(strSrc[pos]) != string::npos) && (pos < LEN))
		{
			++pos;
		}
		if (pos == LEN)
		{
			return strDest.size();
		}
		while ((delims.find(strSrc[pos]) == string::npos) && (pos < LEN))
		{
			STR += strSrc[pos++];
		}
		//std::cout << "[" << STR << "]";  
		if (!STR.empty())
		{
			strDest.push_back(STR);
		}
	}
	return strDest.size();
}


/* 192.168.1.1-192.168.1.254*/
DWORD CScan::gethost()
{

	return endIp - startIp;
}

void CScan::getStartAndEndIP(char *host, startAndEndIP *mStartAndEndIP)
{
	int num = 0;
	std::string ip_list[2];
	vector<string> splitStrs;
	if (strstr(host, "-"))
	{
		splitString(host, "-", splitStrs); //调用自定义的分割函数  

		mStartAndEndIP->ipNum = splitStrs.size();//ip 个数

		vector<string>::iterator iter;
		for (iter = splitStrs.begin(); iter != splitStrs.end(); ++iter) 
		{
			//num = splitStrs.size();
			ip_list[num++] = (string)*iter;
		}
		splitStrs.clear();
	}

	mStartAndEndIP->startIp = ip_list[0];
	mStartAndEndIP->endIp = ip_list[1];
}

/*ip to int 函数*/
int CScan::ipToint( const char * ip )
{
	std::cout << ntohl( inet_addr( ip ) ) << endl;
	return ntohl( inet_addr( ip ) );
}

/* int to ip 函数 */
char* CScan::inttoip(DWORD ip_num)
{
	char ip[64];
	WORD _ip[4];

	_ip[0] = ((ip_num >> 24) & 0xFF);
	_ip[1] = ((ip_num >> 16) & 0xFF);
	_ip[2] = ((ip_num >> 8)  & 0xFF);
	_ip[3] = (ip_num & 0xFF);

	sprintf(ip,"%d.%d.%d.%d",_ip[0],_ip[1],_ip[2],_ip[3]);

	return ip;
}
