#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <errno.h>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ev.h>


#include "AllKillServer.h"
#include "AllKillClient.h"
#include "AllKillPlayer.h"

#include "daemonize.h"
#include "log.h"


Log xt_log;

int main(int argc,char** argv)
{
	int is_daemonize=0;
	std::string conf_file;    //保存配置文件名

	int oc;
	char ic;

	///---读取参数
	while((oc=getopt(argc,argv,"Df:"))!=-1)
	{
		switch(oc)
		{
			case 'D':
				is_daemonize=1;
				break;
			case 'f':
				conf_file=std::string(optarg);
				break;
			case '?':
				ic=(char) optopt;
				printf("invalid \'%c\'\n",ic);
				break;
			case ':':
				printf("lack option arg\n");
				break;
		}
	}

	if (conf_file == "")
	{
		printf("no config file\n");
		return -1;
	}

	if (is_daemonize)
	{
		printf("begin daemonize\n");
		daemonize();
	}

	signal(SIGPIPE,SIG_IGN);

	// 创建事件循环对象
	struct ev_loop* loop = ev_loop_new(0);

	AllKillServer* server = new AllKillServer;
	if (server->start(loop, conf_file) < 0)
	{
		printf("start server failed.\n");
		goto error;
	}
	else 
	{
		printf("start server success\n");
	}

	// 进入事件循环
	ev_loop(loop,0);

	delete server;

	ev_loop_destroy(loop);


#ifdef AK_DEBUG
	printf("server close(client_nu=%d,player_nu=%d)\n",AllKillClient::ms_objectNu,AllKillPlayer::ms_objectNu);
#endif 

	return 0;

error:
	delete server;
	return -1;

}















