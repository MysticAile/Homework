/*选取一个好长好长的DNA序列（DNA序列可能包含26个小写英文字母).
每次选择两个区间，询问如果用两个区间里的 DNA 序列分别生产出来两只兔子是否一模一样.
注意两个兔子一模一样只可能是他们的 DNA 序列一模一样.
第一行DNA,第二行一个数字,表示询问次数.
接下来 m 行，每行四个数字,分别表示此次询问的两个区间.
对于每次询问，输出一行表示结果。*/
#include<stdio.h>

int main()
{
    char *s;
    gets(s);
    int q;
    scanf("%d",&q);
    int a[q][4],i,j;
    for(i=0;i<q;i++)
       for(j=0;j<4;j++)
          scanf("%d",&a[i][j]);
/*    aabbaabb
      3
      1 3 5 7
      1 3 6 8
      1 2 1 2   */
    int cnt,m,n;
    for(i=0;i<q;i++)
    {  
       cnt=0;
       j=0;
       m=a[i][j];
       n=a[i][j+2];
       if(a[i][1]-a[i][0]==a[i][3]-a[i][2])//判断两个区间是都一样长
       {
             while(s[m-1]==s[n-1] && m<=a[i][1])
             {
                 m++;
                 n++;
                 cnt++;
             }
             if(cnt==a[i][1]-a[i][0]+1) printf("Yes\n");
             else printf("No\n");
        }
        else printf("No\n");
    }
    return 0;
}