#include <stdio.h>

void tobinary(int n, char prefix[3])
{
    int i;
    int a[4];

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

void converter(char c)
{
    int i;
    char list1[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char list2[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for (i = 0; i < 26; i++)
    {
        if (c == list1[i])
        {
            tobinary(i + 1, "010");
            i = 26;
        }
        if (c == list2[i])
        {
            tobinary(i + 1, "011");
            i = 26;
        }
    }
}

int main()
{

    int i;
    char text[10];

    printf("Welcome to binary converter\nEnter text: ");
    scanf("%s", text);

    for (i = 0; i < 10; i++)
    {
        converter(text[i]);
    }

    printf("\n");
    return 0;
}