#include <stdio.h>         //ÓÃwÊä³öW
void draw(int n)
{
    int i, j, k, r, m;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= 2; j++)
        {
            for (r = 1; r < i; r++)
                printf(" ");
            printf("w");
            for (k = 1; k <= 2 * n - 2 * i; k++)
                printf(" ");
            printf("w");
            for (m = 1; m <= i; m++)
                printf(" ");
        }
        printf("\n");
    }
}
int main(void)
{
    int n;
    printf("Enter n:\n");
    scanf("%d", &n);
    draw(n);
    return 0;
}