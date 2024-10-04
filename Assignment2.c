#include <stdio.h>

int main() {
    float cgpa, back, attendance, projects;
    char communication_skills; // Declare communication_skills as a char

    // Get user inputs
    printf("Enter CGPA: ");
    scanf("%f", &cgpa);

    printf("Enter back (0 for none, 1 for one): ");
    scanf("%f", &back);

    printf("Enter attendance: ");
    scanf("%f", &attendance);

    printf("Enter number of projects: ");
    scanf("%f", &projects);

    printf("Enter communication skills (A/B/C): ");
    scanf(" %c", &communication_skills); // Read a single character input for skills

    // Check eligibility conditions
    if (cgpa >= 9 && back == 0 && attendance >= 90 && projects >= 10 && communication_skills == 'A') {
        printf("Student is eligible for 1st tier\n");
    } else if (cgpa < 9 && cgpa >= 7.5 && back == 1 && attendance < 90 && attendance >= 75 && projects > 5 && projects < 10 && communication_skills == 'B') {
        printf("Student is eligible for 2nd tier\n");
    } else {
        printf("Student is eligible for 3rd tier\n");
    }

    return 0;
}
