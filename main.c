#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

// Structure to store student data
struct Student {
    char name[MAX_NAME_LENGTH];
    int age;
    int rollNumber;
};

// Function prototypes
void addStudent();
void viewStudents();
void searchStudent();

int main() {
    int choice;

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addStudent() {
    struct Student student;
    FILE *file = fopen("students.txt", "a");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nEnter Student Name: ");
    scanf("%s", student.name);
    printf("Enter Student Age: ");
    scanf("%d", &student.age);
    printf("Enter Student Roll Number: ");
    scanf("%d", &student.rollNumber);

    fprintf(file, "%s %d %d\n", student.name, student.age, student.rollNumber);
    fclose(file);

    printf("Student added successfully!\n");
}

void viewStudents() {
    struct Student student;
    FILE *file = fopen("students.txt", "r");

    if (file == NULL) {
        printf("No students found. Please add students first.\n");
        return;
    }

    printf("\nStudent Records:\n");
    printf("Name\t\tAge\tRoll Number\n");

    while (fscanf(file, "%s %d %d", student.name, &student.age, &student.rollNumber) != EOF) {
        printf("%s\t\t%d\t%d\n", student.name, student.age, student.rollNumber);
    }

    fclose(file);
}

void searchStudent() {
    struct Student student;
    FILE *file = fopen("students.txt", "r");
    char searchName[MAX_NAME_LENGTH];
    int found = 0;

    if (file == NULL) {
        printf("No students found. Please add students first.\n");
        return;
    }

    printf("\nEnter the name of the student to search: ");
    scanf("%s", searchName);

    while (fscanf(file, "%s %d %d", student.name, &student.age, &student.rollNumber) != EOF) {
        if (strcmp(student.name, searchName) == 0) {
            printf("\nStudent Found!\n");
            printf("Name: %s\n", student.name);
            printf("Age: %d\n", student.age);
            printf("Roll Number: %d\n", student.rollNumber);
            found = 1;
            break;
        }
    }

    fclose(file);

    if (!found) {
        printf("\nStudent not found.\n");
    }
}
