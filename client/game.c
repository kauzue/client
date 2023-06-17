#include "game.h"
#include "function.h"

void StartPlayer1()
{
    int x = 2;
    int y = 3;

    MoveCursor(x - 2, y - 3);
    printf("ģ���� �Բ� ������ ��԰� ������ ���ڸ��� �츮�� ���� ���� �����. \n");

    MoveCursor(x - 2, y - 2);
    printf("�ῡ�� ����� ������ �ѷ����� ������ �ƴ� �ٸ� ���ó�� ������. \n");

    MoveCursor(x - 2, y);
	printf("> ���� �ѷ����� \n");

    MoveCursor(x, y + 1);
	printf("�� �����ϱ� \n");

    MoveCursor(x, y + 2);
	printf("menu");

    while (true) {
        int key = ControlKey();

        switch (key) {
        case UP:
            if (y > 3) {
                MoveCursor(x - 2, y);
                printf(" ");
                MoveCursor(x - 2, --y);
                printf(">");
            }
            break;

        case DOWN:
            if (y < 5) {
                MoveCursor(x - 2, y);
                printf(" ");

                MoveCursor(x - 2, ++y);
                printf(">");
            }
            break;

        case ENTER:
            system("cls");
            return;
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