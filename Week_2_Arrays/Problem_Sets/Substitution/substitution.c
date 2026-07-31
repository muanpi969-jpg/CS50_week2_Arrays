#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Check for exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Check key length
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Check that key contains only letters and no duplicates
    bool seen[26] = {false};

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }

        int index = toupper(key[i]) - 'A';

        if (seen[index])
        {
            printf("Key must not contain duplicate characters.\n");
            return 1;
        }

        seen[index] = true;
    }

    // Get plaintext
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // Encrypt plaintext
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];

        if (isalpha(c))
        {
            int index = toupper(c) - 'A';
            char cipher_char = key[index];

            if (isupper(c))
            {
                printf("%c", toupper(cipher_char));
            }
            else
            {
                printf("%c", tolower(cipher_char));
            }
        }
        else
        {
            // Non-alphabetical characters unchanged
            printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}
