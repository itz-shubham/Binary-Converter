/*
 *Program to convert the string to binary in a special way.
 *if a character is in capital case then it's binary will contains leading "010".
 *if a character is in small case then it's binary will contains leading "011".
 */
#include <stdio.h>
#include <stdlib.h>

/*convert the received number to binary and print the same with leading prefix received in argument*/
void tobinary(int n, const char *prefix)
{
    int i;
    int a[5];

    printf("%s", prefix);

    for (i = 4; i >= 0; i--)
    {
        a[i] = n % 2;
        n = n / 2;
    }

    for (i = 0; i < 5; i++)
    {
        printf("%d", a[i]);
    }
    printf(" ");
}

/*convert the received character to binary with the help of 'tobinary()' function*/
void converter(char c)
{
    if (c >= 65 && c <= 90) /*for capitalCase letter*/
    {
        tobinary((c - 65) + 1, "010");
    }
    else if (c >= 97 && c <= 122) /*for smallCase letter*/
    {
        tobinary((c - 97) + 1, "011");
    }
    else
        printf("{Not supported characters}");
}

/*take input of text from user in received string (char*) and returns the base address of same string (it's needed because may be the base address of the string get changed).*/
char *inputText(char *string)
{
    string = (char *)calloc(1, 1 * sizeof(char));
    char ch, i = 0;
    while (1)
    {
        ch = getchar();
        if (ch == '\n')
        {
            /*adding NULL to terminate string */
            string[i] = '\0';
            break;
        }
        /* Reallocating memory for the string.*/
        string = (char *)realloc(string, (i + 2) * sizeof(char));
        string[i++] = ch; /*adding data to string*/
    }
    return string;
}

int main()
{

    int i;
    char *text = NULL;

    printf("Welcome to binary converter\nEnter text: ");
    text = inputText(text);

    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ') /*skip space */
            continue;
        converter(text[i]);
    }
    free(text); // free allocated memory
    printf("\n");
    return 0;
}