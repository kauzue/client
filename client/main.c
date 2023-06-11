#define _CRT_SECURE_NO_WARNINGS

#include "function.h"
#define PORT_NUM    1252
#define MAX_MSG_LEN 256
#define SERVER_IP "218.235.54.179"   //"192.168.55.101" 서버 IP 주소
#define NEW_GAME 0
#define CONTINUE 2
#define OPTION 4
#define EXIT 6

static enum KEY { UP, DOWN, LEFT, RIGHT, ENTER };

char msg[MAX_MSG_LEN] = "";
int esc = 0;

int main(){
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);//윈속 초기화

    //char server_ip[40] = "";
    //printf("서버 IP:");
    //gets_s(server_ip, sizeof(server_ip));

    SOCKET sock;
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//소켓 생성
    if (sock == -1) {
        return -1;
    }

    SOCKADDR_IN servaddr = { 0 };//소켓 주소
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    servaddr.sin_port = htons(PORT_NUM);

    int re = 0;
    re = connect(sock, (struct sockaddr*)&servaddr, sizeof(servaddr));//연결 요청
    if (re == -1) {
        return -1;
    }

    _beginthread(RecvThreadPoint, 0, (void*)sock);

    while (strcmp(msg, "esc") != 0) {
        while (strcmp(msg, "선택: ") == 0) {
            scanf("%s", msg);
            send(sock, msg, MAX_MSG_LEN, 0);//송신
        }
    }

    closesocket(sock);//소켓 닫기
    WSACleanup();//윈속 해제화
    return 0;
}

void RecvThreadPoint(void* pin)
{
    SOCKET sock = (SOCKET)pin;
    int result;

    while (recv(sock, msg, MAX_MSG_LEN, 0)) {
        printf("%s", msg);

        if (strcmp(msg, "cls") == 0) {
            system("cls");
        }

        if (strcmp(msg, "esc") == 0) {
            esc = 1;
        }

        if (strcmp(msg, "init") == 0) {
            Init();
        }

        if (strcmp(msg, "menu") == 0) {
            result = DrawMain();

            switch (result) {
            case NEW_GAME:
                strcpy(msg, "start game");
                send(sock, msg, MAX_MSG_LEN, 0);
            }
        }
    }
    closesocket(sock);
}

void Init()
{
    system("mode con cols=60 lines=20 | title LodgeEscape");
}

int DrawMain()
{
    int esc = 1;
    int x = 25;
    int y = 10;

    system("cls");

    MoveCursor(x - 2, y);
    printf("> New game");

    MoveCursor(x, y + 2);
    printf("Continue");

    MoveCursor(x, y + 4);
    printf("Option");

    MoveCursor(x, y + 6);
    printf("Exit");

    while (true) {
        int key = ControlKey();

        switch (key) {
        case UP:
            if (y > 10) {
                MoveCursor(x - 2, y);
                printf(" ");
                MoveCursor(x - 2, y = y - 2);
                printf(">");
            }
            break;

        case DOWN:
            if (y < 16) {
                MoveCursor(x - 2, y);
                printf(" ");
                MoveCursor(x - 2, y = y + 2);
                printf(">");
            }
            break;

        case ENTER:
            key = y - 10;
        }

    }
}

int ControlKey()
{
    int key = getch();

    if (key == 224) {
        key = getch();
    }

    if (key == 'w' || key == 'W' || key == 72) {
        return UP;
    }

    if (key == 's' || key == 'S' || key == 80) {
        return DOWN;
    }

    if (key == 'a' || key == 'A' || key == 75) {
        return LEFT;
    }

    if (key == 'd' || key == 'D' || key == 77) {
        return RIGHT;
    }

    if (key == 13 || key == 32) {
        return ENTER;
    }
}

void MoveCursor(int x, int y)
{
    HANDLE consolehandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consolehandle, pos);
}