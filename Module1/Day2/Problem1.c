#include <stdio.h>

void print(double num) {
    unsigned long long* ptr = (unsigned long long*)&num; 
    unsigned long long exponent = (*ptr & 0x7FF0000000000000) >> 52; 

    // Print in hexadecimal format
    printf("Exponent (hex): 0x%llx\n", exponent);

    // Print in binary format
    printf("Exponent (binary): 0b");
    for (int i = 11; i >= 0; i--) {
        unsigned long long bit = (exponent >> i) & 1;
        printf("%lld", bit);
    }
    printf("\n");
}

int main() {
    double x = 0.7;
    print(x);

    return 0;
}
