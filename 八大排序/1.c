#include <stdio.h> //对数组里面的数从大到小进行冒泡排序
int a, i, j;
void remake(int x[], int b)
{

    if (x[i] < x[j])
    {
        a = x[i];
        x[i] = x[j];
        x[j] = a;
    }
}
int main(void)
{
    int n[5];
    printf("Enter ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &n[i]);
    }
    for (i = 0; i < 4; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            remake(n, 5); 
            
        }
    }
    for (i = 0; i < 5; i++)
    {
        printf("%5d", n[i]);
    }
    printf("\n");
    return 0;
}