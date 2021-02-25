#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1000;
const int alphanumber=26;
typedef struct {
    int weight;
    int parent,lchild,rchild;
}HufNode;//HuffmanTree的基本定义
typedef struct {
    int weight;
    char data;
    char code[maxn];//需要被建树的信息
}HufCode;
void Init(HufCode h[])//初始化输入数据
{
    FILE *f1=fopen("DataFile.data","r");
    for(int i=0;i<alphanumber;++i)
        fscanf(f1,"%c%d ",&h[i].data,&h[i].weight);

    fclose(f1);
}
void select(HufNode *h,int k,int &s1,int &s2)//选择两个最小的值
{
    int i;
    for(i=0; i<k && h[i].parent != 0; ++i);//选择一个父节点为0的根节点
        s1 = i;
    for(i=0; i<k; ++i){
        if(h[i].parent==0 && h[i].weight<h[s1].weight)
              s1 = i;
    }
    for(i=0; i<k; ++i){
        if(h[i].parent==0 && i!=s1)
            break;
    }
    s2 = i;
    for(i=0; i<k; ++i){
        if(h[i].parent==0 && i!=s1 && h[i].weight<h[s2].weight)
            s2 = i;
    }
}
void HuffmanTree(HufCode *h2,HufNode *h1,int n)
{
    char str[maxn];
    int m=2*n-1;
    for(int i=0;i<m;++i){
        if(i<n)//前n个全部是叶子节点，
            h1[i].weight=h2[i].weight;
        else//后面的是还没建成的树
            h1[i].weight==0;
        h1[i].lchild=h1[i].parent=h1[i].rchild=0;
    }
    int s1,s2;
    for(int i=n;i<m;++i){
        select(h1,i,s1,s2);
        h1[s1].parent=i;//建立二叉树
        h1[s2].parent=i;
        h1[i].lchild=s1;
        h1[i].rchild=s2;
        h1[i].weight=h1[s1].weight+h1[s2].weight;
    }
    str[n]='\0';
    int l;
    for(int i=0;i<n;++i){//从每个叶子节点开始倒序遍历
        l=n-1;//倒序赋值字符串
        for(int k=i,p=h1[k].parent;p;k=p,p=h1[k].parent){//沿着叶子回溯到根节点
            if(k==h1[p].lchild)
                str[l]='0';
            else
                str[l]='1';
            l--;
        }
        strcpy(h2[i].code,str+l+1);
       // printf("%c %s\n",h2[i].data,h2[i].code);
    }
}
void EnCodeing(HufCode hc[])
{
    FILE *f1=fopen("ToBeTran.data","r");
    FILE *f2=fopen("Code.txt","w");
    char str[maxn];
    while(fscanf(f1,"%s",str)!=EOF)
    {
        int len=strlen(str);
        for(int i=0;i<len;++i){
            int x=str[i]-'a';
            fprintf(f2,"%s",hc[x].code);
        }
        fprintf(f2," ");
    }
    fclose(f1);
    fclose(f2);
}
int Search(HufCode hc[],char *str)
{
    for(int i=0;i<alphanumber;++i)
        if(strcmp(hc[i].code,str)==0)
            return  i;
    return -1;
}
void DeCodeing(HufCode hc[])
{
    FILE *f1=fopen("CodeFile.data","r");
    FILE *f2=fopen("Textfile.txt","w");
    char str[maxn];
    while(fscanf(f1,"%s",str)!=EOF)
    {
        char a[maxn];
        memset(a,'\0',sizeof(a));
        int len=strlen(str),k=0;
        for(int i=0;i<len;++i){
            a[k]=str[i];
            a[k+1]='\0';
            int ans=Search(hc,a);
            if(ans!=-1){
                fprintf(f2,"%c",ans+'a');
                k=0;
                continue;
            }
            k++;
        }
        fprintf(f2," ");
    }

    fclose(f1);
    fclose(f2);
}
void OutPut()
{
    FILE *infile=fopen("DataFile.data","r");
    FILE *outfile=fopen("Code.txt","r");
    int w;
    char c;
    printf("各个字母及其权值\n");
    for(int i=0;i<alphanumber;++i){
        fscanf(infile,"%c %d ",&c,&w);
        printf("%c %d ",c,w);
    }

    infile=fopen("ToBeTran.data","r");
    printf("\n\n待编码的内容：\n");
    char str[maxn];
    while(fscanf(infile,"%s",str)!=EOF)
        printf("%s ",str);

    printf("\n编码后结果：\n");
    while(fscanf(outfile,"%s",str)!=EOF)
        printf("%s ",str);

    printf("\n\n待解码内容：\n");
    infile=fopen("CodeFile.data","r");
    while(fscanf(infile,"%s",str)!=EOF)
        printf("%s ",str);

    printf("\n解码结果：\n");
    outfile=fopen("Textfile.txt","r");
    while(fscanf(outfile,"%s",str)!=EOF)
        printf("%s ",str);
    printf("\n");

    fclose(infile);
    fclose(outfile);
}
int main()
{
    HufCode hc[maxn];
    HufNode tree[maxn];
    Init(hc);//初始化
    HuffmanTree(hc,tree,alphanumber);//建树
    EnCodeing(hc);//编码
    DeCodeing(hc);//解码
    OutPut();//输出结果
    return 0;
}