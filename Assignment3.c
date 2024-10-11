#include <stdio.h>
#include <string.h>

#define MAX_MEMBERS 100
#define GUITAR_COST 2000
#define HARMONICA_COST 1500
#define BHARATNATYAM_COST 3000
#define ZUMBA_COST 2500

#define BASIC_PACKAGE_COST 3200 // Guitar + Harmonica for 1 month
#define PREMIUM_PACKAGE_COST_1 5000 // Bharatnatyam + Zumba for 1 month
#define PREMIUM_PACKAGE_COST_2 4000 // Harmonica + Bharatnatyam for 1 month
#define PREMIUM_PACKAGE_COST_3 4000 // Guitar + Zumba for 1 month
#define PREMIUM_PACKAGE_COST_4 4800 // Guitar + Bharatnatyam for 1 month

typedef struct {
    char name[50];
    int activity; 
    int months;
    int package; // New field to indicate if a package is selected
} Member;

void displayActivities();
void displayPackages();
void registerMember(Member *member);
int calculateCost(int months, int activity, int package);

int main() {
    Member members[MAX_MEMBERS];
    int memberCount = 0;

    while (1) {
        printf("\nPerforming Arts Club\n");
        printf("1. Register Member\n");
        printf("2. Display Member Information\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (memberCount < MAX_MEMBERS) {
                    registerMember(&members[memberCount]);
                    memberCount++;
                } else {
                    printf("Maximum member limit reached!\n");
                }
                break;

            case 2:
                for (int i = 0; i < memberCount; i++) {
                    printf("\nMember %d:\n", i + 1);
                    printf("Name: %s\n", members[i].name);
                    printf("Activity: ");
                    if (members[i].package) {
                        switch (members[i].package) {
                            case 1: printf("Basic Package (Guitar + Harmonica)\n"); break;
                            case 2: printf("Premium Package (Bharatnatyam + Zumba)\n"); break;
                            case 3: printf("Premium Package (Harmonica + Bharatnatyam)\n"); break;
                            case 4: printf("Premium Package (Guitar + Zumba)\n"); break;
                            case 5: printf("Premium Package (Guitar + Bharatnatyam)\n"); break;
                            default: printf("No valid package\n");
                        }
                    } else {
                        switch (members[i].activity) {
                            case 1: printf("Guitar\n"); break;
                            case 2: printf("Harmonica\n"); break;
                            case 3: printf("Bharatnatyam\n"); break;
                            case 4: printf("Zumba\n"); break;
                            default: printf("No activity selected\n");
                        }
                    }
                    printf("Months: %d\n", members[i].months);
                    printf("Total Cost: %d\n", calculateCost(members[i].months, members[i].activity, members[i].package));
                }
                break;

            case 3:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

void displayActivities() {
    printf("Available Activities:\n");
    printf("1 - Guitar (Rs%d per month)\n", GUITAR_COST);
    printf("2 - Harmonica (Rs%d per month)\n", HARMONICA_COST);
    printf("3 - Bharatnatyam (Rs%d per month)\n", BHARATNATYAM_COST);
    printf("4 - Zumba (Rs%d per month)\n", ZUMBA_COST);
}

void displayPackages() {
    printf("Available Packages:\n");
    printf("1 - Basic Package (Guitar + Harmonica) for Rs%d per month\n", BASIC_PACKAGE_COST);
    printf("2 - Premium Package (Bharatnatyam + Zumba) for Rs%d per month\n", PREMIUM_PACKAGE_COST_1);
    printf("3 - Premium Package (Harmonica + Bharatnatyam) for Rs%d per month\n", PREMIUM_PACKAGE_COST_2);
    printf("4 - Premium Package (Guitar + Zumba) for Rs%d per month\n", PREMIUM_PACKAGE_COST_3);
    printf("5 - Premium Package (Guitar + Bharatnatyam) for Rs%d per month\n", PREMIUM_PACKAGE_COST_4);
}

void registerMember(Member *member) {
    printf("Enter your name: ");
    scanf(" %[^\n]", member->name); 

    displayActivities();
    printf("Choose an activity (1-4) or 0 for package: ");
    scanf("%d", &member->activity);
    
    if (member->activity == 0) {
        displayPackages();
        printf("Choose a package (1-5): ");
        scanf("%d", &member->package);
        if (member->package < 1 || member->package > 5) {
            printf("Invalid package selection, defaulting to no activity.\n");
            member->package = 0;
        }
    } else {
        member->package = 0; // No package selected
    }

    printf("Enter the number of months you want to perform the activity/package: ");
    scanf("%d", &member->months);
}

int calculateCost(int months, int activity, int package) {
    if (package > 0) {
        switch (package) {
            case 1: return months * BASIC_PACKAGE_COST;
            case 2: return months * PREMIUM_PACKAGE_COST_1;
            case 3: return months * PREMIUM_PACKAGE_COST_2;
            case 4: return months * PREMIUM_PACKAGE_COST_3;
            case 5: return months * PREMIUM_PACKAGE_COST_4;
        }
    } else {
        switch (activity) {
            case 1: return months * GUITAR_COST;
            case 2: return months * HARMONICA_COST;
            case 3: return months * BHARATNATYAM_COST;
            case 4: return months * ZUMBA_COST;
        }
    }
    return 0; 
}

