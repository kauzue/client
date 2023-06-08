#define _CRT_SECURE_NO_WARNINGS

#include "function.h"
#define PORT_NUM    1252
#define MAX_MSG_LEN 256
#define SERVER_IP "192.168.55.101"   //"192.168.55.101" 서버 IP 주소
int exit = 0;

int main()
{
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

    char msg[MAX_MSG_LEN] = "";
    while (!exit) {
        //scanf("%s", msg);
        gets_s(msg, MAX_MSG_LEN);
        send(sock, msg, strlen(msg), 0);//송신
        if (strcmp(msg, "exit") == 0) {
            break;
        }
    }

    closesocket(sock);//소켓 닫기
    WSACleanup();//윈속 해제화
    return 0;
}

void RecvThreadPoint(void* pin)
{
    SOCKET sock = (SOCKET)pin;
    char msg[MAX_MSG_LEN];
    int result;

    while (recv(sock, msg, MAX_MSG_LEN, 0)) {
        printf("%s", msg);

        if (srtcmp(msg, "cls") == 0) {
            system("cls");
        }

        if (strcmp(msg, "exit") == 0) {
            exit = 1;
        }

        if (strcmp(msg, "init") == 0) {
            Init();
        }
    }
    closesocket(sock);
}

void Init()
{
    system("mode con cols = 514 lines = 416 | title Lodge Escape");
}