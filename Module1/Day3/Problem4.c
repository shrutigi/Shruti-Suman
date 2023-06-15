#include <stdio.h>

void findSmallestAndLargestDigits(int n, int numbers[]);

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int numbers[n];

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    findSmallestAndLargestDigits(n, numbers);

    return 0;
}

void findSmallestAndLargestDigits(int n, int numbers[]) {
    int smallestDigit = 9;
    int largestDigit = 0;

    for (int i = 0; i < n; i++) {
        int tempNum = numbers[i];

        while (tempNum > 0) {
            int digit = tempNum % 10;  
            if (digit < smallestDigit) {
                smallestDigit = digit;
            }

            if (digit > largestDigit) {
                largestDigit = digit;
            }

            tempNum /= 10;  
        }
    }

    if (smallestDigit == 9 && largestDigit == 0) {
        printf("Not Valid\n");
    } else {
        printf("Smallest digit: %d\n", smallestDigit);
        printf("Largest digit: %d\n", largestDigit);
    }
}
