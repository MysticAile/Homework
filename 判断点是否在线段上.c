//�жϵ�A(x,y)�Ƿ���B(x1,y1)��C(x2,y2)���ɵ��߶���
#include<stdio.h>
int main()
{
    double x,y;//A��
    double x1,y1,x2,y2;//B��C��
    scanf("%lf %lf %lf %lf %lf %lf",&x,&y,&x1,&y1,&x2,&y2);
    if(x1!=x2) 
    {
      if((x-x1)*(x-x2)<=0 && (y-y1)*(y-y2)<=0)//��֤�����߶η�Χ��
      {
        if(y==(y1-y2)/(x1-x2)*(x-x1)+y1)
        printf("��");
        else printf("��");
      }
      else printf("��");
    }
    else //�߶δ�ֱ��X��
    {
       if(x==x1 && (y-y1)*(y-y2)<=0) 
       printf("��");
       else printf("��");
    }
    return 0;
}