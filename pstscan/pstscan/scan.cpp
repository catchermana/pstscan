#include <iostream>
#include <string>

using namespace std;

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
		<<	"\t-imap         : imap accounts scan"								<< '\n'
		<<	"\t-mail         : mail accounts scan"								<< '\n'
		<<	"\t-mssql        : mssql accounts scan"								<< '\n'
		<<	"\t-mysql        : mysql accounts scan"								<< '\n'
		<<	"\t-middle       : midlle vulnerabilities scan"						<< '\n'
		<<	"\t-all          : scan all the plugins"							<< '\n'
		<<std::endl;
}

int main(int agrc,char *agrv[]) {
  help();
  //getchar();
  return 0;
}