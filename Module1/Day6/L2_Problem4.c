#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int age;
};

struct Student* modifyStudent(struct Student *student) {

    printf("Enter the modified details:\n");
    printf("Name: ");
    scanf("%s", student->name);
    printf("Age: ");
    scanf("%d", &(student->age));

    return student;
}

int main() {
    struct Student *student = (struct Student*)malloc(sizeof(struct Student));

    if (student == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    printf("Enter student details:\n");
    printf("Name: ");
    scanf("%s", student->name);
    printf("Age: ");
    scanf("%d", &(student->age));
    struct Student *modifiedStudent = modifyStudent(student);
    printf("\nModified Student Details:\n");
    printf("Name: %s\n", modifiedStudent->name);
    printf("Age: %d\n", modifiedStudent->age);

    free(student);

    return 0;
}
