//��8*8���������ϰڷŰ˸��ʺ�,���������ʺ󶼲��ܶ����ܴ���ͬһ�С��С�б����,���ж����ְڷ�.
#include <stdio.h>
#define max 8
int queen[max], sum=0; // maxΪ����������� 
void f() //������лʺ������ 
{
    int i;
    for(i=0;i<max;i++)
    printf("(%d,%d) ", i, queen[i]);
    printf("\n");
    sum++;
}
int check(int n) 
{
    int i;
    for(i=0;i<n;i++) 
    {
        if(queen[i] == queen[n] || abs(queen[i] - queen[n]) == (n - i))
        return 1;
    }
    return 0;
}
void put(int n) //nΪ������ 
{
    int i;
    for(i=0;i<max;i++)
    {
        queen[n] = i; //���ʺ�ڵ���ǰѭ������λ�� 
        if(!check(n))
        {
            if(n == max - 1)  f(); /* ���ȫ���ںã���������лʺ������ */
            else  put(n + 1); /* ��������ڷ���һ���ʺ� */
        }
    }
}
int main()
{
    put(0); //�Ӻ�����Ϊ0��ʼ���γ��� 
    printf("%d", sum);
    return 0;
}