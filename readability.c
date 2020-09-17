#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
// Prompt user for string of text.
    string text = get_string("Text: ");
    int letters = 0;
    int words = 0;
    int sentences = 0;

//loop for letter count
    for (int i = 0, n = strlen(text); i < n; i++)
    {   
        // only count letters that are upper or lowercase using typec function.
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    //   printf("%i letter(s)\n", letters);


//loop for word count
    for (int i = 0, n = strlen(text); i < n; i++)
    {   
        if (isspace(text[i]))
        {
            words++;
        }
    }
//  printf("%i word(s)\n", words + 1);


//loop for sentence count
    for (int i = 0, n = strlen(text); i < n; i++)
    {   
        if ((text[i] == '!') || (text[i] == '.') || (text[i] == '?'))
        {
            sentences++;
        }
    }
//  printf("%i sentence(s)\n", sentences);

//calculate index.
    float L = (float) letters / (words + 1) * 100;
    float S = (float) sentences / (words + 1) * 100;
    int index = round((float) 0.0588 * L - (float) 0.296 * S - (float) 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

//function isalpha will probably look like this.
// for (int i = 0, n = strlen(text); i < n; i++)
// {
//     if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
//     {
//         letters++;
//     }
// }
//  printf("%i letter(s)\n", letters);

