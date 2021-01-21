#include <stdio.h> //对数组里面的数从大到小进行冒泡排序
int a, i, j;//定义全局变量
void remake(int x[], int b)//冒泡排序函数
{

    if (x[i] < x[j])//判断大小，如果前面的小于后面的就进行交换
    {
        a = x[i];//用a作为中间参数进行数据交换
        x[i] = x[j];
        x[j] = a;
    }
}
int main(void)
{
    int n[5];
    printf("Enter ");//输入数组中的数据
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &n[i]);
    }
    for (i = 0; i < 4; i++)//开始遍历循环
    {
        for (j = i + 1; j < 5; j++)
        {
            remake(n, 5); //调用函数
        }
    }
    for (i = 0; i < 5; i++)//输出数组中的数据
    {
        printf("%5d", n[i]);
    }
    printf("\n");
    return 0;
}