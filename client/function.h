#pragma once
#pragma warning(disable:4996)

#define MAX_MSG_LEN 256

#include <WinSock2.h>
#include <stdbool.h>

enum KEY { UP, DOWN, LEFT, RIGHT, ENTER };

IN_ADDR GetDefaultMyIP();
void Init();
int DrawMain(int ending);
int ControlKey();
void MoveCursor(int x, int y);
void Option_Menu(sock);