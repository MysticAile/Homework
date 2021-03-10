#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1000;
const int MAX=26;
typedef struct {
    int weight;
    int parent,lchild,rchild;
}Node;//�����������
typedef struct {
    int weight;
    char data;
    char code[maxn];
}Code;
void initialization(Code h[])//��ʼ��
{
    FILE *f1=fopen("DataFile.data","r");
    for(int i=0;i<MAX;++i)
        fscanf(f1,"%c%d ",&h[i].data,&h[i].weight);

    fclose(f1);
}
void HuffmanTree(Code *h2,Node *h1,int n)
{
    char str[maxn];
    int m=2*n-1;
    for(int i=0;i<m;++i){
        if(i<n)//ǰn��ȫ����Ҷ�ӽڵ㣬
            h1[i].weight=h2[i].weight;
        else
            h1[i].weight==0;
        h1[i].lchild=h1[i].parent=h1[i].rchild=0;
    }
    int s1,s2;
    for(int i=n;i<m;++i){
        select(h1,i,s1,s2);
        h1[s1].parent=i;//����������
        h1[s2].parent=i;
        h1[i].lchild=s1;
        h1[i].rchild=s2;
        h1[i].weight=h1[s1].weight+h1[s2].weight;
    }
    str[n]='\0';
    int l;
    for(int i=0;i<n;++i){//��ʼ�������
        l=n-1;
        for(int k=i,p=h1[k].parent;p;k=p,p=h1[k].parent){//����Ҷ�ӻ��ݵ����ڵ�
            if(k==h1[p].lchild)
                str[l]='0';
            else
                str[l]='1';
            l--;
        }
        strcpy(h2[i].code,str+l+1);
    }
}
void select(Node *h,int k,int &s1,int &s2)//ѡ��
{
    int i;
    for(i=0; i<k && h[i].parent != 0; ++i);//ѡ��һ�����ڵ�Ϊ0�ĸ��ڵ�
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
void BianMa(Code HC[])//���뺯��
{
    FILE *f1=fopen("ToBeTran.data","r");
    FILE *f2=fopen("Code.txt","w");
    char str[maxn];
    while(fscanf(f1,"%s",str)!=EOF)
    {
        int len=strlen(str);
        for(int i=0;i<len;++i){
            int x=str[i]-'a';
            fprintf(f2,"%s",HC[x].code);
        }
        fprintf(f2," ");
    }
    fclose(f1);
    fclose(f2);
}
void Decode(Code HC[])//���뺯��
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
            int ans=Search(HC,a);
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
int Search(Code HC[],char *str)
{
    for(int i=0;i<MAX;++i)
        if(strcmp(HC[i].code,str)==0)
            return  i;
    return -1;
}
void OutPut()//���
{
    FILE *infile=fopen("DataFile.data","r");
    FILE *outfile=fopen("Code.txt","r");
    int w;
    char c;
    printf("������ĸ����Ȩֵ\n");
    for(int i=0;i<MAX;++i){
        fscanf(infile,"%c %d ",&c,&w);
        printf("%c %d ",c,w);
    }

    infile=fopen("ToBeTran.data","r");
    printf("\n\n����������ݣ�\n");
    char str[maxn];
    while(fscanf(infile,"%s",str)!=EOF)
        printf("%s ",str);

    printf("\n���������\n");
    while(fscanf(outfile,"%s",str)!=EOF)
        printf("%s ",str);

    printf("\n\n���������ݣ�\n");
    infile=fopen("CodeFile.data","r");
    while(fscanf(infile,"%s",str)!=EOF)
        printf("%s ",str);

    printf("\n��������\n");
    outfile=fopen("Textfile.txt","r");
    while(fscanf(outfile,"%s",str)!=EOF)
        printf("%s ",str);
    printf("\n");

    fclose(infile);
    fclose(outfile);
}
int main(void)
{
    Code HC[maxn];
    Node tree[maxn];
    Init(HC);//��ʼ��
    HuffmanTree(HC,tree,MAX);//����
    BianMa(HC);//����
    Decode(HC);//����
    OutPut();//���
    system("pause");
    return 0;
}