<Usage>:
        scan.exe -host [HostName|startIP<-endIP>] <Options> [plugins]
        scan.exe -file HostListFile <Options> [Plugins]

<Options>:
        -m thread     : max thread count, default: 256
        -m2 thread    : max thread count in each ip, default: 3
        -t timeout    : timed out in ms, default: 10
        -s sleeptime  : sleep ms during ip, default: 10
        -v            : verbose mode, more information

<Plugins>:
        -ipc (-admin) : ipc accounts scan
        -ftp          : ftp accounts scan
        -pop3         : pop3 accounts scan
        -imap         : imap accounts scan
        -mail         : mail accounts scan
        -mssql        : mssql accounts scan
        -mysql        : mysql accounts scan
        -middle       : midlle vulnerabilities scan
        -all          : scan all the plugins