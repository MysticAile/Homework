//ŷ������㷨 (շת�����)
//˼·��
// 1.��������������
// 2.��m/n,����Ϊr,���r=0,��n�����Լ�����㷨����������ִ�е�����
//3.��nֵ����m����r��ֵ����n������ִ�еڶ���
#include <stdio.h>
int FindDivisor(int m, int n)
{
    if (m % n == 0)
        return n;
    else
        return FindDivisor(n, m % n);
}
int main()
{
    int m, n;
    printf("������ m n:\t");
    scanf("%d %d", &m, &n);
    printf("���Լ��Ϊ:%d", FindDivisor(m, n));
}