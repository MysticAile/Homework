//判断点A(x,y)是否在B(x1,y1)与C(x2,y2)连成的线段上
#include<stdio.h>
int main()
{
    double x,y;//A点
    double x1,y1,x2,y2;//B、C点
    scanf("%lf %lf %lf %lf %lf %lf",&x,&y,&x1,&y1,&x2,&y2);
    if(x1!=x2) 
    {
      if((x-x1)*(x-x2)<=0 && (y-y1)*(y-y2)<=0)//保证点在线段范围内
      {
        if(y==(y1-y2)/(x1-x2)*(x-x1)+y1)
        printf("在");
        else printf("否");
      }
      else printf("否");
    }
    else //线段垂直于X轴
    {
       if(x==x1 && (y-y1)*(y-y2)<=0) 
       printf("在");
       else printf("否");
    }
    return 0;
}