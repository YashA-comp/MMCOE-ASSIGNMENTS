
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    int prn;
    char name[50];
    char batch[10];
    char mentor[50];
    float attendance; // Assuming attendance is in percentage
    float percentage; // Assuming percentage is the grading criterion
} Student;


int compareStudents(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    
   
    if (studentB->percentage != studentA->percentage)
        return (studentB->percentage - studentA->percentage) > 0 ? 1 : -1;

    // If percentages are the same, compare by PRN (ascending order)
    return studentA->prn - studentB->prn;
}

void displayStudent(Student student) {
    printf("PRN: %d\n", student.prn);
    printf("Name: %s\n", student.name);
    printf("Batch: %s\n", student.batch);
    printf("Mentor: %s\n", student.mentor);
    printf("Attendance: %.2f%%\n", student.attendance);
    printf("Percentage: %.2f%%\n\n", student.percentage);
}

int main() {
    int n; 
    
 
    printf("Enter the number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive number.\n");
        return 1;
    }

    
    Student *students = (Student *)malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

 
    for (int i = 0; i < n; i++) {
        printf("Enter details for Student %d:\n", i + 1);
        
 
        printf("PRN: ");
        if (scanf("%d", &students[i].prn) != 1 || students[i].prn <= 0) {
            printf("Invalid PRN. It must be a positive integer.\n");
            free(students);
            return 1;
        }

        // Get Name
        printf("Name: ");
        scanf("%*c%49[^\n]", students[i].name); // Read a line with spaces
        
        // Get Batch
        printf("Batch: ");
        scanf("%*c%9[^\n]", students[i].batch); // Batch has a max of 9 characters

        // Get Mentor
        printf("Mentor: ");
        scanf("%*c%49[^\n]", students[i].mentor);

        // Get Attendance (ensure it is a valid percentage)
        printf("Attendance (in %%): ");
        if (scanf("%f", &students[i].attendance) != 1 || students[i].attendance < 0.0 || students[i].attendance > 100.0) {
            printf("Invalid attendance. It must be between 0 and 100.\n");
            free(students);
            return 1;
        }

        // Get Percentage (ensure it is a valid percentage)
        printf("Percentage (in %%): ");
        if (scanf("%f", &students[i].percentage) != 1 || students[i].percentage < 0.0 || students[i].percentage > 100.0) {
            printf("Invalid percentage. It must be between 0 and 100.\n");
            free(students);
            return 1;
        }

        printf("\n");
    }

   
    qsort(students, n, sizeof(Student), compareStudents);


    printf("Sorted Student Information by Percentage (Descending) and then PRN (Ascending):\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        displayStudent(students[i]);
    }


    free(students);

    return 0;
}
