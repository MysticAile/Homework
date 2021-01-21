#include <stdio.h>//直接插入排序，从小到大
int main(void)
{
    int a[5],i,j;//定义数组及变量
    printf("Enter: ");//输入数组中的元素
    for(i=0;i<5;i++)//循环遍历存入数据
    {
        scanf("%d",&a[i]);
    }
    for (i = 1; i < 5; i++)//遍历插入
    {
        int temp = a[i];//定义中间变量
        j = i - 1;
        while (temp < a[j])//当前一个数小于后一个数，则进行交换
        {
            a[j + 1] = a[j];
            j--;
            if (j == -1)//超出数组范围则退出
            {
                break;
            }
        }
        a[j + 1] = temp;
    }
    for (i = 0; i < 5; i++)//输出数组中的数据
    {
        printf("%d\t", a[i]);
    }
    return 0;
}