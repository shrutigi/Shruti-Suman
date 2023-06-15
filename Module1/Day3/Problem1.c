#include <stdio.h>

void printNumbers(int n);
void printSpaces(int n);
void printPattern(int n);

int main() {
    int n = 10;

    printf("Enter the number of rows: ");
    //scanf("%d", &n);

    printPattern(n);

    return 0;
}

void printNumbers(int n) {
    int i;
    for (i = 1; i <= n; i++) {
        printf("%d", i);
    }
}

void printSpaces(int n) {
    int i;
    for (i = 1; i <= 2 * n - 3; i++) {
        printf(" ");
    }
}

void printPattern(int n) {
    int i;
    for (i = n; i >= 1; i--) {
        printNumbers(i);

        if (i != 1) {
            printSpaces(i);
        }

        if (i != n) {
            printNumbers(i);
        }

        printf("\n");
    }
}
