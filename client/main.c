#define _CRT_SECURE_NO_WARNINGS

#include "function.h"
#define PORT_NUM    4523
#define MAX_MSG_LEN 256
#define SERVER_IP "175.121.169.6"   //"175.121.169.6" 辑滚 IP 林家
int main()
{
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);//扩加 檬扁拳	
    
    //char server_ip[40] = "";
    //printf("辑滚 IP:");
    //gets_s(server_ip, sizeof(server_ip));

    SOCKET sock;
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//家南 积己
    if (sock == -1) {
        return -1;
    }

    SOCKADDR_IN servaddr = { 0 };//家南 林家
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    servaddr.sin_port = htons(PORT_NUM);

    int re = 0;
    re = connect(sock, (struct sockaddr*)&servaddr, sizeof(servaddr));//楷搬 夸没
    if (re == -1) {
        return -1;
    }

    _beginthread(RecvThreadPoint, 0, (void*)sock);

    char msg[MAX_MSG_LEN] = "";
    while (true) {
        //scanf("%s", msg);
        gets_s(msg, MAX_MSG_LEN);
        send(sock, msg, strlen(msg), 0);//价脚
        if (strcmp(msg, "exit") == 0) {
            break;
        }
    }

    closesocket(sock);//家南 摧扁
    WSACleanup();//扩加 秦力拳
    return 0;
}

void RecvThreadPoint(void* pin)
{
    SOCKET sock = (SOCKET)pin;
    char msg[MAX_MSG_LEN];
    int result;

    while (recv(sock, msg, MAX_MSG_LEN, 0)) {
        printf("%s", msg);

        result = strcmp(msg, "cls");

        if (result == 0) {
            system("cls");
        }

        result = strcmp(msg, "wait");

        if (result == 0) {
            getchar();
        }
    }
    closesocket(sock);
}