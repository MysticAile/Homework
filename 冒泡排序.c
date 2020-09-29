#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n],i;
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    int j,t;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
               t=a[j+1];
               a[j+1]=a[j];
               a[j]=t;
            }
        }
    }
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
   
    return 0;
}