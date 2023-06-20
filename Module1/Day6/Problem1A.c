#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

double calculateVolume(struct Box box) {
    return box.length * box.width * box.height;
}

double calculateSurfaceArea(struct Box box) {
    double topBottom = 2 * box.length * box.width;
    double frontBack = 2 * box.length * box.height;
    double sides = 2 * box.width * box.height;
    return topBottom + frontBack + sides;
}

int main() {
    struct Box myBox;

    printf("Enter the length of the box: ");
    scanf("%lf", &myBox.length);

    printf("Enter the width of the box: ");
    scanf("%lf", &myBox.width);

    printf("Enter the height of the box: ");
    scanf("%lf", &myBox.height);

    double volume = calculateVolume(myBox);
    double surfaceArea = calculateSurfaceArea(myBox);

    printf("The volume of the box is: %lf\n", volume);
    printf("The surface area of the box is: %lf\n", surfaceArea);

    return 0;
}
