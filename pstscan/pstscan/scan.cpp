#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

#define DWORD unsigned long 
DWORD	startIp;
DWORD	endIp;
string ip_list[1000];

void help()
{
	std::cout << "<Usage>: "													<< '\n'
		<<	"\tscan.exe -host [HostName|startIP<-endIP>] <Options> [plugins]"	<< '\n'
		<<	"\tscan.exe -file HostListFile <Options> [Plugins]"					<< '\n'
		<<	std::endl;
	
	std::cout << "<Options>:"													<< '\n'
		<<	"\t-m thread     : max thread count, default: 256"					<< '\n'
		<<	"\t-m2 thread    : max thread count in each ip, default: 3"			<< '\n'
		<<	"\t-t timeout    : timed out in ms, default: 10"					<< '\n'
		<<	"\t-s sleeptime  : sleep ms during ip, default: 10"					<< '\n'
		<<	"\t-v            : verbose mode, more information"					<< '\n'
		<<std::endl;

	std::cout << "<Plugins>:"													<< '\n'
		<<	"\t-ipc (-admin) : ipc accounts scan"								<< '\n'
		<<	"\t-ftp          : ftp accounts scan"								<< '\n'
		<<	"\t-pop3         : pop3 accounts scan"								<< '\n'
		<<	"\t-ssh          : imap accounts scan"								<< '\n'
		<<	"\t-mail         : mail accounts scan"								<< '\n'
		<<	"\t-mssql        : mssql accounts scan"								<< '\n'
		<<	"\t-mysql        : mysql accounts scan"								<< '\n'
		<<	"\t-middle       : midlle vulnerabilities scan"						<< '\n'
		<<	"\t-all          : scan all the plugins"							<< '\n'
		<<std::endl;
}

//分割字符并返回字符数组  
int  splitString(const string & strSrc, const std::string& strDelims, vector<string>& strDest)  
{  
	typedef std::string::size_type ST;  
	string delims = strDelims;  
	std::string STR;  
	if(delims.empty())
	{
		delims = "/n/r";
	}  

	ST pos=0, LEN = strSrc.size();  
	
	while(pos < LEN )
	{  
		STR="";   
		while( (delims.find(strSrc[pos]) != std::string::npos) && (pos < LEN) ) 
		{
			++pos;
		}  
		if(pos==LEN) 
		{
			return strDest.size();
		}  
		while( (delims.find(strSrc[pos]) == std::string::npos) && (pos < LEN) )
		{
			STR += strSrc[pos++];
		}  
		//std::cout << "[" << STR << "]";  
		if( ! STR.empty() )
		{
			strDest.push_back(STR);
		}  
	}  
	return strDest.size();  
}


/* 192.168.1.1-192.168.1.254*/
DWORD gethost()
{
	
	return endIp-startIp;
}

int main(int argc,char *argv[]) {
 
  char *host = "192.168.1.1-192.168.1.254";
  char szHostName[200];     //保存主机名
  //host = argv[1];
  //help();
  int num = 0;

  /*分割 192.168.1.1-192.168.1.254 拿到 192.168.1.1和192.168.1.254*/
  vector<string> splitStrs;
  if (strstr(host, "-" )){
		splitString(host,"-", splitStrs); //调用自定义的分割函数  
		vector<string>::iterator iter;  
		for (iter = splitStrs.begin(); iter != splitStrs.end(); ++iter) {
			ip_list[num] = (string)*iter;
			std::cout << ip_list[num] << '\n' << endl;
			num++;
		}  
		splitStrs.clear();
	}

  //gethost();
  getchar();
  return 0;
}