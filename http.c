/*  Make the necessary includes and set up the variables.  */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"
#include "httpclient.h"


int main(int argc, char *argv[])
{
	//char h_con[1024];
	//sprintf(h_con,"<?xml version=\"1.0\" encoding=\"UTF-8\" ?><PTZData version=\"2.0\" xmlns=\"http://www.isapi.org/ver20/XMLSchema\"><pan>%s</pan><tilt>0</tilt><zoom>%s</zoom></PTZData>",argv[1],argv[2]);
	char *h_con1 = "okokok\r\n";
	
	
	
	httpclient_t 	ct = httpClientCreat("192.168.1.224","admin","fhjt12345");
#if 0	
	httpClientGet(ct,"/ISAPI/System/deviceInfo");
	printf("%s\r\n",ct->httpBuf);
	httpClearConn(ct);
#else	
	
	if(httpClientPut(ct,"/ISAPI/System/Serial/ports/1/Transparent/channels/1/close",h_con1)){
			printf("%s\r\n",ct->httpBuf);
			httpClearConn(ct);
		}
		if(httpClientPut(ct,"/ISAPI/System/Serial/ports/1/Transparent/channels/1/open",h_con1)){
			printf("%s\r\n",ct->httpBuf);
			httpClearConn(ct);
		}
	
		if(httpClientPut(ct,"/ISAPI/System/Serial/ports/1/Transparent/channels/1/transData",h_con1)){
			printf("%s\r\n",ct->httpBuf);
			httpClearConn(ct);
		}
	
	
#endif	
	httpclientFree(ct);
	return 0;
}