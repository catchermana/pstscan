#include "scan.h"
#include "func.h"
using namespace std;

int main(int argc, char *argv[]) {

	char *host = "192.168.1.1-192.168.1.254";
	//char szHostName[200];     //保存主机名
	//host = argv[1];
	
	//DWORD xxx;
	//int num = 0;
	string _startIp;
	string _endIp;
	const char *file = "ip.txt";
	char ip[65536];

	int ipNum = 0;
	
	CScan * mScan = new CScan();
	DWORD ipint = 3232235777;
	/*分割 192.168.1.1-192.168.1.254 拿到 192.168.1.1和192.168.1.254*/
	
	startAndEndIP mStartAndEndIp;
	mScan->getStartAndEndIP(host, &mStartAndEndIp);

	_startIp = mStartAndEndIp.startIp;
	_endIp = mStartAndEndIp.endIp;

	//std::cout << _startIp << endl;
	//std::cout << _endIp << endl;
	//xxx = mScan->ipToint(_startIp.c_str()); //string to const char

	//mScan->intToip(ipint);
	//mScan->help();
	//mScan->ReadDataFromFileIntoString(file,ip);
	mScan->ReadDataFromFileLBLIntoCharArray(file,ip);
	for (int i = 0; i < ipNum; ++i )
	{
		cout << ip[i] << endl;
	}
	
	return 0;
}