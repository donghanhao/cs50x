#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height:");
    }
    while (n < 1 || n > 8);
    for (int i = 0; i < n; i++)
    {
        for (int k = n - i - 1; k > 0; k--)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}