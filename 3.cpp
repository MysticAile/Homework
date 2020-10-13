//预编译命令
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
//数据结构
typedef int Status;
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
//函数声明
int menu_select();
int menu_select();
void CreateList_L(LinkList &L,int n);
void PrintList_L(LinkList L);
//主函数
int main()
{
    LinkList L;
    int n;
    for(;;)
    {
        switch(menu_select())
        {
        case 1:
            printf("请输入元素的个数:");
            scanf("%d",&n);
            CreateList_L(L,n);
            printf("创建完成\n");
            break;
        case 2:
            PrintList_L(L);
            break;
        case 3:
            printf("调用查找函数(已知位序找元素)\n");
            break;
        case 4:
            printf("调用插入函数\n");
            break;
        case 5:
            printf("调用删除函数\n");
            break;
        case 6:
            printf("调用查找函数（已知元素找位序）\n");
            break;
        case 0:
            printf("程序结束，谢谢使用\n\n");
            exit(0);                        
        }
    }
    return 0;
}
//菜单函数
int menu_select()
{
	int sn;
	printf("\n显示菜单\n");
	printf("1.创建\n"); 
	printf("2.显示\n");
	printf("3.取元素\n");
	printf("4.插入\n");
	printf("5.删除\n");
	printf("6.查找\n");
	printf("0.退出\n");
	printf("输入 0-6:");
	for(;;)
	{
		scanf("%d",&sn);
		if(sn<0||sn>6)
			printf("\n输入错误，重选0－6：");
		else
			break;
	}
	return sn;
}
//创建单链表，头插法，已知线性表的长度
void CreateList_L(LinkList &L,int n)
{
    LinkList p;
    int i;
    L=(LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    printf("请逆序输入%d个元素:\n",n);
    for(i=n;i>=1;i--)
    {
        p=(LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->data);//格式输入字符串补出来
        p->next=L->next;
        L->next = p;
    }
}
//输出单链表
void PrintList_L(LinkList L)
{
    LinkList p;
    p = L->next;
    printf("输入链表中的元素:\n");
    while(p)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}
//取元素函数
Status GetElem_L(LinkList &L,int i, ElemType &e)
{
    LinkList p;
    p=L;
    j=0;
    while(p&&j<i-1)
    {
        p = p->next;
        ++j;
    }//寻找第i-1个结点
    if(!p||j>i-1)
        return ERROR;//i小于1或者大于表长加1
    s=(LinkList)malloc(sizeof(LNode));//生成新结点
    s->data = e;
    s->next = p->next;//插入L中
    p->next = s;
    return OK;    
}