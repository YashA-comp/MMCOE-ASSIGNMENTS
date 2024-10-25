#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 11 // 10 digits + null terminator

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    int isFavorite; // 0 = not favorite, 1 = favorite
    int isBlocked;  // 0 = not blocked, 1 = blocked
} Contact;

void addContact(Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Address book is full!\n");
        return;
    }
   
    printf("Enter name: ");
    scanf("%s", contacts[*count].name);
   
    printf("Enter phone: ");
    scanf("%s", contacts[*count].phone);
   
    // Validate phone number length
    if (strlen(contacts[*count].phone) != 10) {
        printf("Please ensure phone number has 10 digits.\n");
        return; // Exit the function if the phone number is invalid
    }

    contacts[*count].isFavorite = 0; // Default to not favorite
    contacts[*count].isBlocked = 0;  // Default to not blocked
    (*count)++;
    printf("Contact added successfully!\n");
}

void viewContacts(Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts available.\n");
        return;
    }
   
    for (int i = 0; i < count; i++) {
        if (!contacts[i].isBlocked) {
            printf("Name: %s, Phone: %s, Favorite: %s\n",
                   contacts[i].name,
                   contacts[i].phone,
                   contacts[i].isFavorite ? "Yes" : "No");
        }
        else
        {
            if (contacts[i].isBlocked)
            {
            printf("Name: %s, Phone: %s, BLOCKED CONTACT", contacts[i].name, contacts[i].phone);
            }
        }
    }
}

void deleteContact(Contact contacts[], int *count, char *name) {
    if (*count == 0) {
        printf("No contacts available.\n");
        return;
    }
   
    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void searchContact(Contact contacts[], int count, char *name) {
    if (count == 0) {
        printf("No contacts available.\n");
        return;
    }
   
    for (int i = 0; i < count; i++)
    {
        if (contacts[i].isBlocked)
        {
            printf("Name: %s, Phone: %s, BLOCKED CONTACT",
                   contacts[i].name,
                   contacts[i].phone);
        }
        else
        {
            printf("Name: %s, Phone: %s, Favorite: %s\n",
                   contacts[i].name,
                   contacts[i].phone,
                   contacts[i].isFavorite ? "Yes" : "No");
        }
    }
    return;
}

void toggleFavorite(Contact contacts[], int count, char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            contacts[i].isFavorite = !contacts[i].isFavorite;
            printf("Contact '%s' marked as %s.\n", contacts[i].name,
                   contacts[i].isFavorite ? "favorite" : "not favorite");
            return;
        }
    }
    printf("Contact not found.\n");
}

void toggleBlock(Contact contacts[], int count, char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            contacts[i].isBlocked = !contacts[i].isBlocked;
            printf("Contact '%s' has been %s.\n", contacts[i].name,
                   contacts[i].isBlocked ? "blocked" : "unblocked");
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;

    int choice;
    do {
        printf("\n1. Add Contact\n2. View Contacts\n3. Delete Contact\n4. Search Contact\n5. Favorite\n6. Block\n7. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addContact(contacts, &count); break;
            case 2: viewContacts(contacts, count); break;
            case 3: {
                if (count == 0) {
                    printf("No contacts available to delete.\n");
                    break;
                }
                char name[NAME_LENGTH];
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteContact(contacts, &count, name);
                break;
            }
            case 4: {
                if (count == 0) {
                    printf("No contacts available to search.\n");
                    break;
                }
                char name[NAME_LENGTH];
                printf("Enter name to search: ");
                scanf("%s", name);
                searchContact(contacts, count, name);
                break;
            }
            case 5: {
                if (count == 0) {
                    printf("No contacts available to favorite.\n");
                    break;
                }
                char name[NAME_LENGTH];
                printf("Enter name to favorite: ");
                scanf("%s", name);
                toggleFavorite(contacts, count, name);
                break;
            }
            case 6: {
                if (count == 0) {
                    printf("No contacts available to block.\n");
                    break;
                }
                char name[NAME_LENGTH];
                printf("Enter name to block: ");
                scanf("%s", name);
                toggleBlock(contacts, count, name);
                break;
            }
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}

