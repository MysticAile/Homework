//����N��ְԱ����Ϣ�������������������ʡ��������ʺ�֧����Ҫ���д����˳�����ÿλְԱ��������ʵ�����ʣ�ʵ������=��������+��������-֧������
#include<stdio.h>
typedef struct 
	{
		char name[10];
		float a;
 float b;
 float c;
 float sum;
	}S;
int main()
{
    int n;
    scanf("%d",&n);
    S s[n];
    for(int i=0;i<n;i++)
	   {
       scanf("%s",&s[i].name);
       scanf("%f",&s[i].a);
       scanf("%f",&s[i].b);
       scanf("%f",&s[i].c);
       s[i].sum=s[i].a + s[i].b - s[i].c;
    }
    for(int i=0;i<n;i++)
    printf("%s %.2f\n",s[i].name,s[i].sum);
    return 0;
}