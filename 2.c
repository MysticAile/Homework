//预编译命令
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define LIST_INIT_SIZE 10 // 表存储空间的初始分配量
#define LISTINCRMENT 2   // 线性表存储空间的分配增量
//数据结构
typedef int Status;
typedf int ElemType;
typedef struct 
{
    ElemType *elem;   // 存储空间基址
    int length;       // 当前长度
    int listsize;     // 当前分配的存储容量（以sizeof(ElemType)为单位）
}Sqlist;
//函数声明
int menu_select();
Status InitList_Sq(Sqlist &L);
Status CreatList_Sq(SqList &L,int n);
void PrintList_Sq(SqList L);
//主函数
int main()
{
    
}
//菜单函数
int menu_select()
{
    int sn;
    printf("\n显示菜单\n");
    printf("1.初始化\n");
    printf("2.创建\n");
    printf("3.显示\n");
    printf("4.插入\n");
    printf("5.删除\n");
    printf("6.查找\n");
    printf("输入 0-6:");
    for(;;)
    {
        scanf("%d",&sn);
        if(sn<0||sn>6)
            printf("\n输入错误,重选0-6: ");
        else
        {
            break;
        }

    }
    return sn;
}
//初始化空的动态顺序表函数
Status InitList_Sq(Sqlist &L)
{
    L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemTyp));
    if(!L.elem)   return(OVERFLOW);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}
//创建动态顺序表（输入n个元素）
Status CreatList_Sq(SqList &L,int n)
{
    int i;
    if(n>L.listsize)
        return(ERROR);
    printf("输入%d个整型数：",n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&L.elem[i-1]);//类c代码中无格式输入字符串，需要补充
    }    
    L.length=n;
    return OK;
}
//输出顺序表元素
void PrintList_Sq(SqList L)
{
    int i;
    for(i=1;i<=L.length;i++)
    {
        printf("%d\t",L.elem[i-1]);
    }
    printf("\n");
}