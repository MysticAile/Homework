//输入n个朋友的信息，包括姓名、生日、电话号码，按照年龄从大到小的顺序依次输出通讯录,题目保证所有人的生日均不相同。
#include<stdio.h>
typedef struct 
	{
		char name[10];
		int bir;
 char num[17];
	}S;
int main()
{
    int n;
    scanf("%d",&n);
    S s[n],t;
    for(int i=0;i<n;i++)
    scanf("%s %d %s",&s[i].name,&s[i].bir,&s[i].num);
    
    for(int i=0;i<n;i++)
    {
       for(int j=i;j<n;j++)
       {
          if(s[i].bir>s[j].bir)
          {
            t=s[i];
            s[i]=s[j];
            s[j]=t;
           }
    
       }
    
    }
    for(int i=0;i<n;i++)
    printf("%s %d %s\n",s[i].name,s[i].bir,s[i].num);
    return 0;
}