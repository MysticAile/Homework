/*给定一个字符串来代表一个学生的出勤记录，
这个记录仅包含以下三个字符：
'A':缺勤
'L':迟到
'P':到场
如果一个学生的出勤记录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到),那么这个学生会被奖赏.
根据其出勤记录判断其是否会被奖赏.*/
#include<stdio.h>
void f(char * s)
{
    int i,cnt=0;
    int l=strlen(s);
    int flag=0;
    for(i=0;i<l;i++)
    {
        if(s[i]=='A')
          if((++cnt)>1)
            flag=1;
        if(s[i]=='L'&&s[i+1]=='L'&&s[i+2]=='L')
        flag=1;
    }
    if(!flag)  printf("Ture");
    else  printf("False");
}
int main()
{
    char *s;
    gets(&s);
    f(&s);
    return 0;
}