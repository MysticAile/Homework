//����n�����ѵ���Ϣ���������������ա��绰���룬��������Ӵ�С��˳���������ͨѶ¼,��Ŀ��֤�����˵����վ�����ͬ��
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