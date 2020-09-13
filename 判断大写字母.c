/*在以下情况，视为正确：1.全部大写 2.全部小写 3.首字母大写，其它小写*/
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