#include "scan.h"
#include "func.h"
using namespace std;

int main(int argc, char *argv[]) {

	char *host = "192.168.1.1-192.168.1.254";
	//char szHostName[200];     //����������
	//host = argv[1];
	//help();
	DWORD xxx;
	int num = 0;
	string _startIp;
	string _endIp;
	CScan * mScan = new CScan();
	/*�ָ� 192.168.1.1-192.168.1.254 �õ� 192.168.1.1��192.168.1.254*/
	
	startAndEndIP mStartAndEndIp;
	mScan->getStartAndEndIP(host, &mStartAndEndIp);

	_startIp = mStartAndEndIp.startIp;
	_endIp = mStartAndEndIp.endIp;

	std::cout << _startIp << endl;
	std::cout << _endIp << endl;
	xxx = mScan->ipToint(_startIp.c_str()); //string to const char
	//gethost();
	getchar();
	return 0;
}