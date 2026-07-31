#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // Get text from user
    string text = get_string("Text: ");

    int letters = 0;
    int words = 0;
    int sentences = 0;

    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        // Count letters
        if (isalpha(text[i]))
        {
            letters++;
        }

        // Count words (spaces + 1)
        if (text[i] == ' ')
        {
            words++;
        }

        // Count sentences
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // Number of words = spaces + 1
    words++;

    // Calculate L and S
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;

    // Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    // Output result
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
