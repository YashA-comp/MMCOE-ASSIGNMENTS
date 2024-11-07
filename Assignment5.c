 #include <stdio.h>
#include <string.h>

#define MAX_DONORS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 11
#define ADDRESS_LENGTH 100
#define BLOOD_TYPE_LENGTH 4 // A+, A-, B+, B-, AB+, AB-, O+, O-

typedef struct {
    char name[NAME_LENGTH];
    int age;
    char phone[PHONE_LENGTH];
    char address[ADDRESS_LENGTH];
    char bloodType[BLOOD_TYPE_LENGTH];
} Donor;

int isValidBloodType(char *bloodType) {
    const char *validBloodTypes[] = {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};
    for (int i = 0; i < 8; i++) {
        if (strcmp(bloodType, validBloodTypes[i]) == 0) {
            return 1; // Valid blood type
        }
    }
    return 0; // Invalid blood type
}

void addDonor(Donor donors[], int *count) {
    if (*count >= MAX_DONORS) {
        printf("Blood bank is full!\n");
        return;
    }

    // Read name (single word, no spaces)
    printf("Enter name: ");
    scanf("%s", donors[*count].name);

    // Read age
    printf("Enter age: ");
    if (scanf("%d", &donors[*count].age) != 1) {
        printf("Invalid age input.\n");
        return;
    }

    // Check if the donor is of legal age (18 or older)
    if (donors[*count].age < 18) {
        printf("You are not of age to donate blood. Deleting this donor...\n");
        getchar(); // Consume the leftover newline character
        return; // Skip adding this donor
    }

    // Read phone (single word, no spaces)
    printf("Enter phone: ");
    scanf("%s", donors[*count].phone);

    // Read address (multiple words, with spaces)
    printf("Enter address: ");
    getchar(); // Consume leftover newline character from previous input
    scanf("%[^\n]%*c", donors[*count].address); // Read entire line including spaces

    // Read blood type (single word, no spaces)
    printf("Enter blood type (A+, A-, B+, B-, AB+, AB-, O+, O-): ");
    scanf("%s", donors[*count].bloodType);

    // Validate blood type
    if (!isValidBloodType(donors[*count].bloodType)) {
        printf("Invalid blood type. Please enter a valid blood type.\n");
        return; // Exit the function if blood type is invalid
    }

    (*count)++;
    printf("Donor added successfully!\n");
}

void viewDonors(Donor donors[], int count) {
    if (count == 0) {
        printf("No donors available.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        printf("Name: %s, Age: %d, Phone: %s, Address: %s, Blood Type: %s\n",
               donors[i].name,
               donors[i].age,
               donors[i].phone,
               donors[i].address,
               donors[i].bloodType);
    }
}

void deleteDonor(Donor donors[], int *count, char *name) {
    if (*count == 0) {
        printf("No donors available.\n");
        return;
    }

    for (int i = 0; i < *count; i++) {
        if (strcmp(donors[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                donors[j] = donors[j + 1];
            }
            (*count)--;
            printf("Donor '%s' deleted successfully!\n", name);
            return;
        }
    }
    printf("Donor not found.\n");
}

void searchDonorByArea(Donor donors[], int count, char *area) {
    if (count == 0) {
        printf("No donors available.\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        // Check if the area (address) contains the search term
        if (strstr(donors[i].address, area) != NULL) {
            printf("Name: %s, Age: %d, Phone: %s, Address: %s, Blood Type: %s\n",
                   donors[i].name,
                   donors[i].age,
                   donors[i].phone,
                   donors[i].address,
                   donors[i].bloodType);
            found = 1;
        }
    }

    if (!found) {
        printf("No donors found in the specified area.\n");
    }
}

void searchDonorByBloodType(Donor donors[], int count, char *bloodType) {
    if (count == 0) {
        printf("No donors available.\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        // Check if the donor's blood type matches the search term
        if (strcmp(donors[i].bloodType, bloodType) == 0) {
            printf("Name: %s, Age: %d, Phone: %s, Address: %s\n",
                   donors[i].name,
                   donors[i].age,
                   donors[i].phone,
                   donors[i].address);
            found = 1;
        }
    }

    if (!found) {
        printf("No donors found with blood type '%s'.\n", bloodType);
    }
}

int main() {
    Donor donors[MAX_DONORS];
    int count = 0;

    int choice;
    do {
        printf("\n1. Add Donor\n2. View Donors\n3. Delete Donor\n4. Search Donor by Area\n5. Search Donor by Blood Type\n6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addDonor(donors, &count); break;
            case 2: viewDonors(donors, count); break;
            case 3: {
                if (count == 0) {
                    printf("No donors available to delete.\n");
                    break;
                }
                char name[NAME_LENGTH];
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteDonor(donors, &count, name);
                break;
            }
            case 4: {
                if (count == 0) {
                    printf("No donors available to search.\n");
                    break;
                }
                char area[ADDRESS_LENGTH];
                printf("Enter area to search for donors: ");
                getchar(); // Consume leftover newline
                scanf("%[^\n]%*c", area); // Read entire line (address)
                searchDonorByArea(donors, count, area);
                break;
            }
            case 5: {
                if (count == 0) {
                    printf("No donors available to search.\n");
                    break;
                }
                char bloodType[BLOOD_TYPE_LENGTH];
                printf("Enter blood type to search for donors (A+, A-, B+, B-, AB+, AB-, O+, O-): ");
                scanf("%s", bloodType);
                searchDonorByBloodType(donors, count, bloodType);
                break;
            }
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}

