//���׹�ʽ
//��ʽ:s=sqrt(p*(p-a)*(p-b)*(p-c))
//p=a+b+c/2;

#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, c, p, area;
    printf("�����������ε����߳�\n");
    scanf("%lf%lf%lf", &a, &b, &c);
    p = (a + b + c) / 2;
    area = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("%.2f", area);
    return 0;
}