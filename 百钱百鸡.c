//�ټ����⣺nԪǮ��nֻ��,����ÿֻ5Ԫ��ĸ��ÿֻ3Ԫ��С��1Ԫ3ֻ��
//nԪǮ����պ���nֻ�������Ҽ�������ֻ�򣬲���������,���ж������� 
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