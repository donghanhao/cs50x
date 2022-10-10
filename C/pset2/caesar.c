#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// wether argv are all digits
bool only_digits(string argv[]);

int main(int argc, string argv[])
{
    // get right command line argument
    if (argc != 2 || !only_digits(argv))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // translate string k into integar k
    int k = atoi(argv[1]);

    // get input from user
    string plaintext = get_string("plaintext:  ");

    // transform each plaintext letter into ciphertext letter
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", ((plaintext[i] - 65 + k) % 26 + 65));
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", ((plaintext[i] - 97 + k) % 26 + 97));
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}


bool only_digits(string argv[])
{
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            return false;
        }
    }
    return true;
}