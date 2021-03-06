//枚举算法
/**
任务描述：
一张单据上有一个5位数的编码，因为保管不善，其百位数已经变得模糊不请。但是知道这个
5位数是57和67的倍数。现在要设计一个算法，输出所有满足这些条件的5位数，并统计这样
的数的个数。
每一行对应一个测试样例，每一行包含4个数字，依次是万位数，千位数，十位数和个位数。
输 出：
每组测试样例的结果输出占一行，第一个数字表示满足条件的编码个数，后面按升序输出所有
满足条件的编码，数字与数字之间用空格隔开。
**/
//题解此处的枚举对象为百位数 i属于0~9之间
#include <stdio.h>
int main()
{
    int d1, d2, d3, d4, d5, count = 0, result[10], i, iValue;
    scanf("%d %d %d %d", &d1, &d2, &d4, &d5);
    for (i = 0; i < 10; i++)
    {
        iValue = 0;
        iValue = d5 * 10000 + d4 * 1000 + i * 100 + d2 * 10 + d1;
        if (iValue % 57 == 0 && iValue % 67 == 0)
        {
            result[count] = iValue;
            count++;
        }
    }
    printf("%d\n", count);
    for (i = 0; i < count; i++)
        printf("%d\t", result[i]);
    return 0;
}
/**扩展如果题目模糊数字变成2位 
 :1?3?5 二重循环
 :??265 此类也可采用二重循环 注意首位不为0，也可采用改变枚举对象两位一起10~99
 **/