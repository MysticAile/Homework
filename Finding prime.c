//ɸ��������(�ռ任ʱ��)
//˼·:��2~n�е��������г�����Ȼ���2��ʼ���Ȼ���n����2�����б�����
//Ȼ�����һ��ʣ�µ�����ʼ(��Ȼ������)��ʼ,
//����n���ڵ����б������ʣ�µ�������������
#include <stdio.h>
#define MAX_NUM 100
int IsPrime[MAX_NUM + 1];//ע���±�
int main()
{
    for (int i = 2; i <= MAX_NUM; i++) //��ʼ������������������
        IsPrime[i] = 1;
    for (int i = 2; i <= MAX_NUM; i++) //ÿ�ν�һ�����������б������Ϊ������
        if (IsPrime[i])                //ֻ��������ı���
            for (int j = 2 * i; j <= MAX_NUM; j += i)
                IsPrime[j] = 0;
    for (int i = 2; i <= MAX_NUM; i++)
        if (IsPrime[i])
            printf("%d\t",i);
    return 0;
}