#include <stdio.h>

//if-else
int findBiggest1(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

//Ternary operator
int findBiggest2(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

int main() {
    int num1, num2;


    int max1 = findBiggest1(23, 32);
    printf("if-else:  %d\n", max1);

    int max2 = findBiggest2(21, 12);
    printf("Ternary operator: %d\n", max2);

    return 0;
}
