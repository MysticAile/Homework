#include <stdio.h> //��������������Ӵ�С����ð������
int a, i, j;//����ȫ�ֱ���
void remake(int x[], int b)//ð��������
{

    if (x[i] < x[j])//�жϴ�С�����ǰ���С�ں���ľͽ��н���
    {
        a = x[i];//��a��Ϊ�м�����������ݽ���
        x[i] = x[j];
        x[j] = a;
    }
}
int main(void)
{
    int n[5];
    printf("Enter ");//���������е�����
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &n[i]);
    }
    for (i = 0; i < 4; i++)//��ʼ����ѭ��
    {
        for (j = i + 1; j < 5; j++)
        {
            remake(n, 5); //���ú���
        }
    }
    for (i = 0; i < 5; i++)//��������е�����
    {
        printf("%5d", n[i]);
    }
    printf("\n");
    return 0;
}