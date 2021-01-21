#include <stdio.h>//对数组元素选择排序
int main(void)
{
    int n, i, j, a[5], num, max;
    printf("Enter :");
    for (i = 0; i < 5; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < 5; i++)
    {
        num = i;
        for (j = i; j < 5; j++)
        {
            if (a[j] > a[num])
                num = j;
        }
        max = a[num];
        a[num] = a[i];
        a[i] = max;
    }
    for (i = 0; i < 5; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", a[i]);
    }
    return 0;
}