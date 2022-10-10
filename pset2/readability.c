#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// name functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

// main body
int main(void)
{
    // get input text from user
    string text = get_string("Text:");

    // calculate letters, words, and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // calculate variables which will be used in formula
    float L = (float)letters / words * 100.0;
    float S = (float)sentences / words * 100.0;

    // Coleman-Liau index formula
    float index = 0.0588 * L - 0.296 * S - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        int X = index + 0.5;
        printf("Grade %i\n", X);
    }

}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // count every alphabet or number letter
        if (isalnum(text[i]))
        {
            letters++;
        }
    }
    return letters;
}


int count_words(string text)
{
    int words = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // count every word by space
        if (isspace(text[i]))
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // count every sentence by ".!?"
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}