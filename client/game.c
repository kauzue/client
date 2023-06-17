#include "game.h"
#include "function.h"

void StartPlayer1()
{
    int x = 2;
    int y = 3;

    MoveCursor(x - 2, y - 3);
    printf("친구와 함께 여관에 놀러왔고 여관에 들어서자마자 우리는 졸려 잠이 들었다. \n");

    MoveCursor(x - 2, y - 2);
    printf("잠에서 깨어나서 주위를 둘러보니 여관이 아닌 다른 장소처럼 보였다. \n");

    MoveCursor(x - 2, y);
	printf("> 주위 둘러보기 \n");

    MoveCursor(x, y + 1);
	printf("몸 수색하기 \n");

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
    printf("> 로그인 정보");

    MoveCursor(x, y + 1);
    printf("로그아웃");

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