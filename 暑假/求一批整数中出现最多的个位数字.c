#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d\n",&n);
	if(n>0 && n<=1000)
	{
		int a[10]={0},i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
      if(m==0) a[0]++;
			while(m>0)
			{
			a[m%10]++;
			m=m/10;
			}
		}
		int max=a[0];
		for(i=0;i<10;i++)
		if(a[i]>max)	max=a[i];
	
		for(i=0;i<10;i++)
		if(max==a[i])	printf("%d ",i);
	}    
	return 0;
}    