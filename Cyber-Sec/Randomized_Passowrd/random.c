#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define max_psw_length 50

char* merge_arrays(char arr1[], int n1, char arr2[], int n2, char arr3[], int n3) {
    char* res = (char*)malloc((n1 + n2 + n3 + 1) * sizeof(char));
    if (res == NULL) {
        return NULL; // Handle memory allocation failure
    }

    // Copy elements from the first array
    memcpy(res, arr1, n1 * sizeof(char));

    // Copy elements from the second array
    memcpy(res + n1, arr2, n2 * sizeof(char));

    // Copy elements from the third array
    memcpy(res + n1 + n2, arr3, n3 * sizeof(char));

    res[n1 + n2 + n3] = '\0'; // adding in a null terminator

    return res; // Return the merged array
}

int main(){
    char psw[max_psw_length + 1]; //creation of the array and +1 to handle null

    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    // Define a list of common ASCII special characters that are generally accepted
    char special_characters[] = {
        '_', '.', '-', '!', '@', '*', '$', '?', '&', '%',
        ';', '=', '^', '+', '[', ']', '~', '`',
        '|', '/', '}', '{', ':', '>', '<', '"', '#', ','};

    // Define a list of numbers (0-9) to check if password contains at least one number
    char required_numbers[] =  {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    int n1 = sizeof(alphabet) / sizeof(alphabet[0]); // Size of the alphabet array
    int n2 = sizeof(special_characters) / sizeof(special_characters[0]); // Size of special characters array
    int n3 = sizeof(required_numbers) / sizeof(required_numbers[0]); // Size of numbers array

    int combined_size = n1 + n2 + n3; // Total size of the combined array

    // Merge the arrays into one combined array
    char* combined_pointer = merge_arrays(alphabet, n1, special_characters, n2, required_numbers, n3);

    if (combined_pointer == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit if memory allocation fails
    }

    printf("Hello! Welcome to the Randomized Password Program.\n");
    printf("----------------------------------------------------------------------------------------------\n");

    printf("The following Will be used to randomly create a password\n");

    // Printing lowercase letters
    printf("Lower Case: ");
    for(int i = 0; i < n1; i++){ // Use n1 here instead of sizeof(alphabet)
        printf("(%c)", alphabet[i]); // Lowercase
    }

    // Printing uppercase letters
    printf("\nUpper Case: ");
    for(int i = 0; i < n1; i++){ // Use n1 here instead of sizeof(alphabet)
        printf("(%c)", toupper(alphabet[i])); // Convert each lowercase letter to uppercase
    }

    // Printing special characters
    printf("\nSpecial Characters: ");
    for(int i = 0; i < n2; i++){ // Use n2 here instead of sizeof(special_characters)
        printf("(%c)", special_characters[i]); // Special characters
    }
    printf("\n----------------------------------------------------------------------------------------------\n");

    // Start of the randomization process
    srand(time(NULL)); // Changing the seed for randomness

    int random_value = (rand() % 36) + 15; // Random password length between 15 and 50

    printf("Password length: %d\n", random_value);  // Print the random password length for debugging

    // Start the randomization of the password
    for (int i = 0; i < random_value; i++) {
        // Generate a random index for the combined array
        int random_index = rand() % combined_size;
        
        // Select the character from the combined array
        psw[i] = combined_pointer[random_index];
    }

    psw[random_value] = '\0'; // Null-terminate the password string

    // User response variable, modified for safety
    char user_response[4]; // To hold the user's response (YES/NO)

    // Print the generated password
    printf("Generated Password: %s\n", psw);

    // Ask the user if they want to keep the password
    printf("Do you want to keep this password? (YES/NO): ");
    scanf("%3s", user_response); // Modified to limit input to 3 characters

    // Compare user input without worrying about case
    if (strcasecmp(user_response, "YES") == 0) {
        printf("Password kept: %s\n\n", psw);
        printf("*************************************************\n");
        printf("*Congrats! You now have a strong password ready!*"); // decided to add some flare
        printf("\n*************************************************\n");


        return 0;  // Exit the program if YES
    } else if (strcasecmp(user_response, "NO") == 0) {
        printf("Generating a new password...\n\n");
        return main();  // Restart the process by calling main again
    } else {
        printf("Invalid response. Please type YES or NO.\n");
        return 1;  // Exit if invalid response
    }
}
