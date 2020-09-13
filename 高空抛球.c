#include<stdio.h>
int main()
{
    int n,i;
    double sum,H,h;
    scanf("%lf %d",&h,&n);
    if(n==0) 
    printf("0.0 0.0");
    else if(n==1)
    printf("%.1f %.1f",h,h/2.0);
    else
    {
        sum=h*1.0;
        for(i=2;i<=n;i++)
        {
        h=h/2.0;
        sum+=2*h;
        H=h;
        }
    printf("%.1f %.1f",sum,H/2.0);
    }
    return 0;
}