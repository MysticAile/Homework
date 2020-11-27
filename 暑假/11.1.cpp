#include <stdio.h>
#include <math.h>
int narcissistic(int number);
void Print(int m, int n);

int main(void)
{
    int m, n;
    printf("Enter m and n:");
    scanf("%d%d", &m, &n);
    if (narcissistic(m))
        printf("%d is a narcissistic number\n", m); //判断上边界
    Print(m, n);
    if (narcissistic(n))
        printf("%d is a narcissistic number\n", n); //判断下边界

    return 0;
}
int narcissistic(int number)
{
    int sum = 0, i = 0, r = 0, number2 = number, count = 0;
    int a[10];
    if (number >= 100 && number <= 10000)
    {
        do=
        {
            number /= 10;
            count++;
        } while (number > 0); /*计算数字的位数*/
        number = number2;
        do
        {
            a[i] = number % 10;
            sum += pow(a[i], count);
            number /= 10;
            i++;
        } while (number > 0);
    }
    if (sum == number2)
        r = 1;
    return r;
}
void Print(int m, int n)
{
    int i, j = 0, number = 0, sum = 0, count = 0;
    int a[10];
    if (m < 100)
        m = 100;
    if (m > 10000)
        n = 10000;
    if (m <= n)
    {
        for (i = m + 1; i <= n - 1; i++)
        {
            number = i;
            count = 0;
            do
            {
                number /= 10;
                count++;
            } while (number > 0);
            number = i;
            sum = 0;
            j = 0; /*循环嵌套一定要注意外层变量可能需要归零*/
            do
            {
                a[j] = number % 10;
                sum += pow(a[j], count);
                number /= 10;
                j++;
            } while (number > 0);
            if (sum == i)
                printf("%d\n", i);
        }
    }
}
