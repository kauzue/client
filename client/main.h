#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#pragma comment(lib,"ws2_32")

#define PORT_NUM    1252
#define SERVER_IP "192.168.0.47"   //"192.168.55.101" 辑滚 IP 林家, "218.235.54.179" 辑滚 IP 林家
#define NEW_GAME 0
#define CONTINUE 2
#define OPTION 4
#define CHAPTER 6
#define ENDING 8
#define EXIT 10

void RecvThreadPoint(void* pin, int esc);