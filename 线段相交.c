#include<stdio.h>
double f(double x,double y,double x1,double y1,double x2,double y2)
{
    int a;//1����  ��;0����  ��
    if(x1!=x2) 
    {
      if((x-x1)*(x-x2)<=0 && (y-y1)*(y-y2)<=0)//��֤�����߶η�Χ��
      {
        if(y==(y1-y2)/(x1-x2)*(x-x1)+y1)
        a=0;
        else a=1;
      }
      else a=1;
    }
    else //�߶δ�ֱ��X��
    {
       if(x==x1 && (y-y1)*(y-y2)<=0) 
       a=0;
       else a=1;
    }
    return a;
}
int main()
{
    double x1,y1,x2,y2,x3,y3,x4,y4;
    scanf("%lf %lf %lf %lf %lf %lf",
    &x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
    //�����һ���߶ε������˵�A,B��������ڶ����������˵�C,D
    if(x1==x2 && x3==x4) printf("��");
    if(x1==x2 && x3!=x4)
    {
      double k,m;
      int a1,a2;
      k=(y3-y4)/(x3-x4);
      //CDֱ�߷���:y=k*(x-x3)+y3;
      m=k*(x1-x3)+y3;//��ֱ�߽���(x1,m)
      a1=f(x1,m,x1,y1,x2,y2);
      a2=f(x1,m,x3,y3,x4,y4);
    if(a1==0 && a2==0) printf("��");
    else printf("��");
    }
    if(x1!=x2 && x3==x4)
    {
      double k,m;
      int a1,a2;
      k=(y1-y2)/(x1-x2);
      //ABֱ�߷���:y=k*(x-x1)+y1;
      m=k*(x3-x1)+y3;//��ֱ�߽���(x3,m)
      a1=f(x1,m,x1,y1,x2,y2);
      a2=f(x1,m,x3,y3,x4,y4);
    if(a1==0 && a2==0) printf("��");
    else printf("��");
    }
    if(x1!=x2 && x3!=x4)
    {
       double k1,k2,m,n;
       int a1,a2;
       k1=(y1-y2)/(x1-x2);
       k2=(y3-y4)/(x3-x4);
       if(k1==k2) printf("��");
       else
       {
          m=(k1*x1-k2*x3+y3-y1)/(k1-k2);
          n=k1*(m-x1)+y1;
          //��������(m,n)
          a1=f(m,n,x1,y1,x2,y2);
          a2=f(m,n,x3,y3,x4,y4);
         if(a1==0 && a2==0) printf("��");
         else printf("��");
       }
    }
    return 0;
}