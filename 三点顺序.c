#include<stdio.h>
int main()
{
	   double x1,y1,x2,y2,x3,y3;//A(x1,y1),B(x2,y2),C(x3,y3)������
    scanf("%lf %lf\n%lf %lf\n%lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
		  double cos;
    cos=(x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
    if(cos>0) printf("��ʱ��");
    if(cos<0) printf("˳ʱ��");
    /*���ַ���:���AB*AC>0,��������ABC����ʱ���
    ���AB*AC<0,��������ABC��˳ʱ���
    ����AB=(x2-x1,y2-y1)
    ����AC=(x3-x1,y3-y1)
    AB*AC=(x2-x1)*(y3-y1)-(x3-x1)*(y2-y1)    */
    return 0;
}