#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNumber;
    char className[20];
    float internalMarks[5][2]; 
    float endTermMarks[5];    
    float internalPercentage;
    float endTermPercentage;
    float finalPercentage;
    int rank;
};

void calculateInternalPercentage(struct Student *student, int numOfSubjects) {
    for (int i = 0; i < numOfSubjects; i++) {
        float totalInternalMarks = student->internalMarks[i][0] + student->internalMarks[i][1];
        student->internalPercentage = (totalInternalMarks / 60) * 30; 
    }
}

void calculateEndTermPercentage(struct Student *student, int numOfSubjects) {
    for (int i = 0; i < numOfSubjects; i++) {
        student->endTermPercentage = (student->endTermMarks[i] / 100) * 70; 
    }
}

void calculateFinalPercentage(struct Student *student) {
    student->finalPercentage = student->internalPercentage + student->endTermPercentage;
}

void assignRank(struct Student *students, int numOfStudents) {
    for (int i = 0; i < numOfStudents; i++) {
        students[i].rank = 1;
        for (int j = 0; j < numOfStudents; j++) {
            if (students[j].finalPercentage > students[i].finalPercentage) {
                students[i].rank++;
            }
        }
    }
}

void displayStudentDetails(struct Student student) {

    printf("     STUDENT DETAILS      \n");
    printf("Roll Number: %d\n", student.rollNumber);
    printf("Name: %s\n", student.name);
    printf("Class: %s\n", student.className);
    printf("Subject\t\tIA 1\tIA 2\tEnd Term\n");
    printf("SCORE DETAILS\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d:\t%.2f\t\t%.2f\t\t%.2f\n",
               i + 1, student.internalMarks[i][0], student.internalMarks[i][1], student.endTermMarks[i]);
    }
    printf("IA: %.2f\n", student.internalPercentage);
    printf("End Term: %.2f\n", student.endTermPercentage);
    printf("Final Percentage: %.2f\n", student.finalPercentage);
    printf("RANK: %d\n", student.rank);

}

int compareNames(const void *a, const void *b) {
    struct Student *studentA = (struct Student *)a;
    struct Student *studentB = (struct Student *)b;
    return strcmp(studentA->name, studentB->name);
}

int main() {
    int numOfStudents;
    printf("Enter the number of students in the class: ");
    scanf("%d", &numOfStudents);

    struct Student *students = (struct Student *)malloc(numOfStudents * sizeof(struct Student));

    printf("Enter student details:\n");
    for (int i = 0; i < numOfStudents; i++) {
        printf("Student %d:\n", i + 1);

        getchar(); 

        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);

        printf("Semester: ");
        fgets(students[i].className, sizeof(students[i].className), stdin);

        printf("INTERNAL ASSESSMENT 1\n");
        for (int j = 0; j < 5; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &students[i].internalMarks[j][0]);
        }

        printf("INTERNAL ASSESSMENT 2\n");
        for (int j = 0; j < 5; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &students[i].internalMarks[j][1]);
        }

        printf("END TERM:\n");
        for (int j = 0; j < 5; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &students[i].endTermMarks[j]);
        }
    }

    qsort(students, numOfStudents, sizeof(struct Student), compareNames);
    for (int i = 0; i < numOfStudents; i++) {
        students[i].rollNumber = i + 1;
    }

    for (int i = 0; i < numOfStudents; i++) {
        calculateInternalPercentage(&students[i], 5);
        calculateEndTermPercentage(&students[i], 5);
        calculateFinalPercentage(&students[i]);
    }
    assignRank(students, numOfStudents);

    int rollNumber;
    printf("\nEnter the roll number of a student to display details: ");
    scanf("%d", &rollNumber);

    int studentIndex = -1;
    for (int i = 0; i < numOfStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            studentIndex = i;
            break;
        }
    }

    if (studentIndex != -1) {
        displayStudentDetails(students[studentIndex]);
    } else {
        printf("No student found with the given roll number.\n");
    }

    free(students);
    return 0;
}
