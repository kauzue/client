#pragma once
#include <WinSock2.h>
#include <Windows.h>
#include <process.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

#pragma comment(lib,"ws2_32")
#pragma warning(disable:4996)

IN_ADDR GetDefaultMyIP();
void RecvThreadPoint(void*pin);