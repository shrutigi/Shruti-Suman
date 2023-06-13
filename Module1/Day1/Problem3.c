#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int rollNo;
    char name[50];
    float physicsMarks, mathMarks, chemistryMarks;
    float totalMarks, percentage;

    printf("Enter the Roll No: ");
    scanf("%d", &rollNo);

    printf("Enter the Name: ");
    scanf(" %[^\n]s", name);

    printf("Enter the Marks of Physics: ");
    scanf("%f", &physicsMarks);

    printf("Enter the Marks of Math: ");
    scanf("%f", &mathMarks);

    printf("Enter the Marks of Chemistry: ");
    scanf("%f", &chemistryMarks);

    // Calculate the total marks and percentage
    totalMarks = physicsMarks + mathMarks + chemistryMarks;
    percentage = (totalMarks / 300) * 100;

    printf("Roll No: %d\n", rollNo);
    printf("Name: %s\n", name);
    printf("Physics Marks: %.2f\n", physicsMarks);
    printf("Math Marks: %.2f\n", mathMarks);
    printf("Chemistry Marks: %.2f\n", chemistryMarks);
    printf("Total Marks: %.2f\n", totalMarks);
    printf("Percentage: %.2f%%\n", percentage);

    return 0;
}
