/*����һ���ַ���������һ��ѧ���ĳ��ڼ�¼��
�����¼���������������ַ���
'A':ȱ��
'L':�ٵ�
'P':����
���һ��ѧ���ĳ��ڼ�¼�в�����һ��'A'(ȱ��)���Ҳ���������������'L'(�ٵ�),��ô���ѧ���ᱻ����.
��������ڼ�¼�ж����Ƿ�ᱻ����.*/
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