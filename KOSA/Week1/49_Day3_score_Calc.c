#include <stdio.h>

#include "Test_header.h"

#if FILE_NUM == 49

int my_main(void) {

    int score = 0;

    do {

        printf("성적을 입력하세요 : ");

        scanf("%d", &score);

        if (score > 100 || score < 0) {

            continue;

        }

        break;

    } while (1);

    switch (score) {

        case 100: case 99: case 98:

        case 97: case 96: case 95:

            printf("%d : A+\n", score);

            break;

        case 94: case 93: case 92:

        case 91: case 90:

            printf("%d : A\n", score);

            break;

        case 89: case 88: case 87:

        case 86: case 85:

            printf("%d : B+\n", score);

            break;

        case 84: case 83: case 82:

        case 81: case 80:

            printf("%d : B\n", score);

            break;

        case 79: case 78: case 77:

        case 76: case 75:

            printf("%d : C+\n", score);

            break;

        case 74: case 73: case 72:

        case 71: case 70:

            printf("%d : C\n", score);

            break;

        case 69: case 68: case 67:

        case 66: case 65:

            printf("%d : D+\n", score);

            break;

        case 64: case 63: case 62:

        case 61: case 60:

            printf("%d : D\n", score);

            break;

        default:

            printf("%d : F\n", score);

            break;

    }

    return 0;

}

#endif