#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[20];
    float marks;
};

void readStudents(struct Student *students, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", students[i].name);

        printf("Marks: ");
        scanf("%f", &(students[i].marks));
    }
}

void writeStudents(struct Student *students, int n) {
    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++) {
        printf("\nDetails for student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }
}

float computeAverageMarks(struct Student *students, int n) {
    float totalMarks = 0;
    for (int i = 0; i < n; i++) {
        totalMarks += students[i].marks;
    }

    return totalMarks / n;
}

void findStudentsAboveBelowAverage(struct Student *students, int n, float averageMarks) {
    printf("\nStudents scoring above average marks:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].marks > averageMarks) {
            printf("%s\n", students[i].name);
        }
    }

    printf("\nStudents scoring below average marks:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].marks < averageMarks) {
            printf("%s\n", students[i].name);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    readStudents(students, n);

    writeStudents(students, n);

    float averageMarks = computeAverageMarks(students, n);
    printf("\nAverage marks: %.2f\n", averageMarks);

    findStudentsAboveBelowAverage(students, n, averageMarks);

    free(students);

    return 0;
}
