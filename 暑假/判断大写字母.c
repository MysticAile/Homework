/*�������������Ϊ��ȷ��1.ȫ����д 2.ȫ��Сд 3.����ĸ��д������Сд*/
#include "stdio.h"
int f(char ch)
{
    if(ch>='A'&&ch<='Z')  return 1;
    else return 0;
}
int main()
{
    char *s;
    gets(s);
    int len=strlen(s);
    int flag,cnt=0;
    for(int i=0;i<len;i++)
    {
       flag=f(s[i]);
       if(flag==1) cnt++;
    }
    if(cnt==0 || cnt==len)  printf("Ture\n");
    else 
    {
        if(cnt==1 && f(s[0])==1)  printf("Ture\n");
        else printf("False");
    }
    return 0;
}