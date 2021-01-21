#include <stdio.h>//快速排序，从小到大
int a[5];
void sort(int left, int right)
{
    int i, j, min, k;
    if (left > right)
    {
        return;
    }
    min = a[left];
    i = left;
    j = right;
    while (i != j)
    {
        while (a[j] >= min && i < j)
        {
            j--;
        }
        while (a[i] <= min && i < j)
        {
            i++;
        }
        if (i != j)
        {
            k = a[i];
            a[i] = a[j];
            a[j] = k;
        }
    }
    a[left] = a[i];
    a[i] = min;
    sort(left, i - 1);
    sort(i + 1, right);
}
int main(void)
{
    int i;
    printf("Enter:\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n");
    sort(0, 4);
    for (i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}