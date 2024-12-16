#include <stdio.h>
#include <string.h>

#define max_psw_length 50 // Setting max length of a password to be 50

int main()
{
    char psw[max_psw_length];

    printf("Input a password: ");
    // Limiting the input to max_psw_length - 1 to avoid buffer overflow
    scanf("%s", psw); // Using %49s to prevent buffer overflow

    // Loop until the password is valid
    while (strlen(psw) < 15 || strlen(psw) > 50) {
        printf("Please ensure the password is at least 15 characters and no more than 50\n");
        printf("Input a password: ");

        
        // Again limiting input to prevent buffer overflow
        scanf("%s", psw); // Using %49s to prevent buffer overflow
    }

    printf("This Password is accepted\n");
    return 0;
}
