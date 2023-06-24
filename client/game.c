#include "game.h"
#include "function.h"

int Player1_Chapter1(int stage)
{
    int x = 2;
    int y = 5;

    switch (stage) {
    case 1: {
        MoveCursor(x - 2, y - 5);
        printf("ģ���� �Բ� ������ ��԰� ������ ���ڸ��� �츮�� ���� ���� �����. \n");

        MoveCursor(x - 2, y - 4);
        printf("�ῡ�� ����� ������ �ѷ����� ������ �ƴ� �ٸ� ���ó�� ������. \n");

        MoveCursor(x - 2, y - 2);
        printf("�ൿ ���� \n");

        MoveCursor(x - 2, y);
        printf("> �� �����ϱ� \n");

        MoveCursor(x, y + 1);
        printf("menu");

        while (true) {
            int key = ControlKey();

            switch (key) {
            case UP:
                if (y > 5) {
                    MoveCursor(x - 2, y);
                    printf(" ");
                    MoveCursor(x - 2, --y);
                    printf(">");
                }
                break;

            case DOWN:
                if (y < 6) {
                    MoveCursor(x - 2, y);
                    printf(" ");

                    MoveCursor(x - 2, ++y);
                    printf(">");
                }
                break;

            case ENTER:
                MoveCursor(x, y + 3);
                return y - 4;
            }
        }
    }

    case 2: {
        MoveCursor(x - 2, y + 6);
        printf("�ൿ ���� \n");

        MoveCursor(x - 2, y = y + 8);
        printf("> �� �����ϱ� \n");

        MoveCursor(x, y + 1);
        printf("menu");

        while (true) {
            int key = ControlKey();

            switch (key) {
            case UP:
                if (y > 13) {
                    MoveCursor(x - 2, y);
                    printf(" ");
                    MoveCursor(x - 2, --y);
                    printf(">");
                }
                break;

            case DOWN:
                if (y < 14) {
                    MoveCursor(x - 2, y);
                    printf(" ");

                    MoveCursor(x - 2, ++y);
                    printf(">");
                }
                break;

            case ENTER:
                return;
            }
        }
    }
    }
}

int Option()
{
    int x = 2;
    int y = 0;

    MoveCursor(x - 2, y);
    printf("> �α��� ����");

    MoveCursor(x, y + 1);
    printf("�α׾ƿ�");

    while (true) {
        int key = ControlKey();

        switch (key) {
        case UP:
            if (y > 0) {
                MoveCursor(x - 2, y);
                printf(" ");
                MoveCursor(x - 2, --y);
                printf(">");
            }
            break;

        case DOWN:
            if (y < 1) {
                MoveCursor(x - 2, y);
                printf(" ");

                MoveCursor(x - 2, ++y);
                printf(">");
            }
            break;

        case ENTER:
            system("cls");
            return y;
        }
    }
}

int Menu()
{
    int x = 2;
    int y = 2;
    MoveCursor(x - 2, y - 2);
    printf("�޴� \n \n");

    MoveCursor(x - 2, y);
    printf("> item");

    MoveCursor(x, y + 2);
    printf("save");

    MoveCursor(x, y + 4);
    printf("continue");

    MoveCursor(x, y + 6);
    printf("option");

    MoveCursor(x, y + 8);
    printf("exit");

    while (true) {
        int key = ControlKey();

        switch (key) {
        case UP:
            if (y > 2) {
                MoveCursor(x - 2, y);
                printf(" ");
                MoveCursor(x - 2, y = y - 2);
                printf(">");
            }
            break;

        case DOWN:
            if (y < 10) {
                MoveCursor(x - 2, y);
                printf(" ");

                MoveCursor(x - 2, y = y + 2);
                printf(">");
            }
            break;

        case ENTER:
            system("cls");
            return (y - 2) / 2;
        }
    }
}