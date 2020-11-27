//百鸡问题：n元钱买n只鸡,公鸡每只5元，母鸡每只3元，小鸡1元3只，
//n元钱必须刚好买n只鸡，而且鸡必须整只买，不能劈开买,求有多少种买法 
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	if(n<500 && n>=0)
	{
		int cnt=0,sum=0;
		int i,j,m;
		for(i=0;i<=n;i+=3)
		{   
			for(j=0;j<=n-i;j++)
			{ 
				m=n-i-j;
				if(i/3+3*j+5*m == n)
				{
					cnt++;
					sum+=m;
				}
			}
		}
		if(cnt==0)  printf("0 -1");
		else printf("%d %d",cnt,sum);
	}
	return 0;
}         