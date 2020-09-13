//输入等腰三角形的高度，输出由星号组成的等腰三角形
#include<stdio.h>
int main(void)
{
    int n,i,j,cnt;
    int flag=1;
    scanf("%d",&n);
      for(i=0;i<n;i++)
     { for(j=i;j<n-1;j++)
       printf(" ");
    
       printf("*");
       for(cnt=1;cnt<=i;cnt++)
       printf(" *");
       
       printf("\n");
    }
}