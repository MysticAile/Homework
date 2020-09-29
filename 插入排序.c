#include <stdio.h>

void f(int a[],int n)
{
    int i,j,t;
    for(i=1;i<n;i++)
    {
        t=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(t<a[j])   a[j+1]=a[j];
            else break;
        }
        a[j+1]=t;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n],i;
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    f(a,n);
    
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}