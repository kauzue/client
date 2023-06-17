﻿#define _CRT_SECURE_NO_WARNINGS

#include "main.h"
#include "game.h"
#include "function.h"

int chapter = 0;
int ending = 0;
char msg[MAX_MSG_LEN] = "";

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

    int esc = 0;

    _beginthread(RecvThreadPoint, 0, (void*)sock, esc);

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

void RecvThreadPoint(void* pin, int esc)
{
    SOCKET sock = (SOCKET)pin;
    int result;

    while (recv(sock, msg, MAX_MSG_LEN, 0)) {
        if (strcmp(msg, "cls") == 0) {
            system("cls");
        }

        else if (strcmp(msg, "esc") == 0) {
            esc = 1;
        }

        else if (strcmp(msg, "init") == 0) {
            Init();
        }

        else if (strcmp(msg, "pause") == 0) {
            system("pause");
        }

        else if (strcmp(msg, "menu") == 0) {
            result = DrawMain(ending);

            switch (result) {
            case NEW_GAME:
                strcpy(msg, "start game");
                send(sock, msg, MAX_MSG_LEN, 0);
                break;

            case CONTINUE:
                strcpy(msg, "continue");
                send(sock, msg, MAX_MSG_LEN, 0);
                break;

            case OPTION:
                result = Option();
                switch (result) {
                case LOGIN_DATA:
                    strcpy(msg, "login data");
                    send(sock, msg, MAX_MSG_LEN, 0);
                    break;

                case LOGOUT:
                    strcpy(msg, "logout");
                    send(sock, msg, MAX_MSG_LEN, 0);
                    break;

                }
                break;

            case CHAPTER:
                strcpy(msg, "chapter");
                send(sock, msg, MAX_MSG_LEN, 0);
                break;

            case ENDING:
                strcpy(msg, "ending");
                send(sock, msg, MAX_MSG_LEN, 0);
                break;

            case EXIT:
                strcpy(msg, "esc");
            }
        }

        else if (strcmp(msg, "player1") == 0) {
            StartPlayer1();
        }

        else {
        printf("%s", msg);
        }
    }
    closesocket(sock);
}