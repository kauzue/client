#include "function.h"

IN_ADDR GetDefaultMyIP()
{
    char localhostname[MAX_PATH];
    IN_ADDR addr = { 0, };
    if (gethostname(localhostname, MAX_PATH) == SOCKET_ERROR)
    {
        return addr;
    }
    HOSTENT* ptr = gethostbyname(localhostname);
    while (ptr && ptr->h_name)
    {
        if (ptr->h_addrtype == PF_INET)
        {
            memcpy(&addr, ptr->h_addr_list[0], ptr->h_length);
            break;
        }
        ptr++;
    }
    return addr;
}

void Init()
{
    system("mode con cols=80 lines=25 | title LodgeEscape");
}

int DrawMain(int ending)
{
    int x = 35;
    int y = 6;

    system("cls");

    MoveCursor(x - 2, y);
    printf("> New game");

    MoveCursor(x, y + 2);
    printf("Continue");

    MoveCursor(x, y + 4);
    printf("Option");

    MoveCursor(x, y + 6);
    printf("Chapter");

    if (ending != 0) {
        MoveCursor(x, y + 8);
        printf("Ending");

        MoveCursor(x, y + 10);
        printf("Exit");
    }

    else {
        MoveCursor(x, y + 8);
        printf("Exit");
    }

    while (true) {
        int key = ControlKey();

        switch (key) {
        case UP:
            if (y > 6) {
                MoveCursor(x - 2, y);
                printf(" ");
                MoveCursor(x - 2, y = y - 2);
                printf(">");
            }
            break;

        case DOWN:
            if (y < 16) {
                if (ending != 0 || y != 14) {
                    MoveCursor(x - 2, y);
                    printf(" ");

                    MoveCursor(x - 2, y = y + 2);
                    printf(">");
                }
            }
            break;

        case ENTER:
            system("cls");

            if (ending == 0 && y == 14) {
                key = y - 4;
            }

            else {
                key = y - 6;
            }

            return;
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