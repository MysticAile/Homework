#include <stdio.h>
#include <math.h>

void f(int n)
{
    int j,k;
    for(int i=1;i<=n;i++)
    {
        for(k=1;k<=abs(i-(n/2+1));k++)
        printf(" ");
        
        for(j=1;j<=n-2*abs(i-(n/2+1));j++)
        printf("*");
    
        printf("\n");
    }
}
int main(void)
{
    int n;//需打印的菱形行数.
    scanf("%d",&n);
    if(n%2==0)  printf("None");
    else f(n);//行数为奇数才可以打印出来.
    return 0;
}