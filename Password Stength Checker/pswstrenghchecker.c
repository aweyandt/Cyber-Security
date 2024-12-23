#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Define a maximum length for the password
#define max_psw_length 50 // Setting max length of a password to be 50

// Function to check if any character from the 'targets' list exists in the 'array'
// 'array' is the string being checked (the password), and 'targets' are the characters we are looking for (e.g., special characters or numbers)
bool contains(const char *array, size_t array_size, const char *targets, size_t target_size)
{
    size_t i, j;

    // Iterate through each character in 'array'
    for (i = 0; i < array_size; i++)
    {
        // Check against each character in the 'targets' array
        for (j = 0; j < target_size; j++)
        {
            if (array[i] == targets[j]) // If a match is found
            {
                return true; // Return true if a match is found
            }
        }
    }
    return false; // Return false if no match is found
}

int main()
{
    // Declare a character array for the password, with space for the null terminator
    char psw[max_psw_length + 1]; // Extra space for null terminator

    // Define a list of common ASCII special characters that are generally accepted
    char special_characters[] = {
        '_', '.', '-', '!', '@', '*', '$', '?', '&', '%',
        ';', '=', '^', '+', '[', ']', '~', '`',
        '|', '/', '}', '{', ':', '>', '<', '"', '#', ','};

    // Define a list of numbers (0-9) to check if password contains at least one number
    char required_numbers[] =  {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    // Calculate the size of special_characters and required_numbers arrays
    size_t special_char_size = sizeof(special_characters) / sizeof(special_characters[0]);
    size_t number_size = sizeof(required_numbers) / sizeof(required_numbers[0]);

    // Prompt the user to input a password
    printf("Enter a password (between 15 and 50 characters): ");
    // Limit the input to max_psw_length to avoid buffer overflow, using %49s to allow space for the null terminator
    scanf("%49s", psw); // Using %49s to prevent buffer overflow

    // Loop to ensure the password is between 15 and 50 characters long
    while (strlen(psw) < 15 || strlen(psw) > 50)
    {
        printf("\nERROR: Password must be between 15 and 50 characters long.\n");
        printf("Please enter a valid password: ");
        scanf("%49s", psw); // Limit input size to prevent overflow
    }

    printf("\nYour password meets the length requirements.\n");

    // Check if the password contains any special characters
    while (!contains(psw, strlen(psw), special_characters, special_char_size))
    {
        printf("\nERROR: Your password must contain at least one special character.\n");
        printf("Please enter a new password: ");
        scanf("%49s", psw); // Limit input size to avoid overflow
    }
    printf("\nYour password contains at least one special character.\n");

    // Debugging: Print the password after the special character check
    printf("Current password after special character check: %s\n", psw);

    // Check if the password contains at least one number
    while (!contains(psw, strlen(psw), required_numbers, number_size))
    {
        printf("\nERROR: Your password must contain at least one number.\n");
        printf("Please enter a new password: ");
        scanf("%49s", psw); // Limit input size to avoid overflow
    }
    printf("\nYour password contains at least one number.\n");

    printf("-----------------------------------------------\n");

    printf("The password you have entered passes all 3 tests. Good job!");

    return 0; // Exit the program
}
