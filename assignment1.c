#include <stdio.h>
#include <string.h>

#define N 16

int main() 

{

    printf("Welcome to Password Validity Checker!\n");

    printf("Create a password having minimum 8 characters . Password should have at least one of: \n1. Small letter (a to z) \n2. Capital Letter (A to Z) \n3. Numeric Value (0 to 9) \n4. Given Special Characters (!, @, #, $)\n");


    int i, s = 0, c = 0, n = 0, sp = 0;

    char pwd[N];


    printf("Enter a password: ");

    scanf("%15s", pwd);


    int length = strlen(pwd);

    if (length >= 8) { // Check minimum length

        for (i = 0; i < length; i++) {

            if (pwd[i] >= 'a' && pwd[i] <= 'z') 

            {

                s++;

            } else if (pwd[i] >= 'A' && pwd[i] <= 'Z') 

            {

                c++;

            } else if (pwd[i] >= '0' && pwd[i] <= '9') 

            {

                n++;

            } else if (pwd[i] == '!' || pwd[i] == '@' || pwd[i] == '#' || pwd[i] == '$') 

            {

                sp++;

            }

        }


        if (s > 0 && c > 0 && n > 0 && sp > 0) {

            printf("Valid Password!\n");

        } else 

        {

            if (s == 0) 

            {

                printf("Password doesn't contain small letters (a to z).\n");

            }

            if (c == 0) 

            {

                printf("Password doesn't contain capital letters (A to Z).\n");

            }

            if (n == 0) 

            {

                printf("Password doesn't contain numeric values (0 to 9).\n");

            }

            if (sp == 0) 

            {

                printf("Password doesn't contain any of the given special characters (!, @, #, $).\n");

            }

        }

    } else {

        printf("Error: Password must have minimum 8 characters.\n");

    }


    printf("Exiting Password Validity Checker.\n");

    return 0;

}



