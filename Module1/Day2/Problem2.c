#include <stdio.h>

void swap(void* a, void* b, size_t size) {
    unsigned char* ptr1 = (unsigned char*)a;
    unsigned char* ptr2 = (unsigned char*)b;

    for (size_t i = 0; i < size; i++) {
        unsigned char temp = *(ptr1 + i);
        *(ptr1 + i) = *(ptr2 + i);
        *(ptr2 + i) = temp;
    }
}

int main() {
    int x = 10;
    int y = 20;
    
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y, sizeof(int));
    printf("After swap: x = %d, y = %d\n", x, y);

    double a = 3.14;
    double b = 2.71;
    
    printf("Before swap: a = %lf, b = %lf\n", a, b);
    swap(&a, &b, sizeof(double));
    printf("After swap: a = %lf, b = %lf\n", a, b);

    return 0;
}
