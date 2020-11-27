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
void  CreateList_L(LinkList &L,int n);
void PrintList_L(LinkList L);
Status GetElem_L(LinkList &L,int i, ElemType &e);
Status  ListInsert_L(LinkList &L,int i,ElemType e); //插入
Status ListDelete_L(LinkList &L,int i,ElemType &e); //删除
int LocateElem_L(LinkList L,ElemType e);//查找 

//主函数
int main()
{	
	LinkList L;
	Status s;
	int n,i,e;
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
			printf("请输入查找的元素的位置:");
            scanf("%d",&i);
			e=GetElem_L(L,i,e);//指向函数类型的指针作形参，实参用同类型的函数名equal
			if(i)
				printf("第%d个元素是%d \n",i,e);
			else
				printf("查找失败!\n");
			break;

		 case 4:
			printf("请输入插入的位序:");
            scanf("%d",&i);
			printf("请输入插入的新元素的值:");
			scanf("%d",&e);
			s=ListInsert_L(L,i,e);
			if(s)
				printf("插入成功!\n");
			else
				printf("插入失败!\n");
			break;

		 case 5:
			printf("输入删除的位序：");
			scanf("%d",&i);
			e=ListDelete_L(L,i,e);
			if(e)
				printf("删除了元素%d成功\n",e);
			else
				printf("删除失败\n");
			break;

		 case 6:
			printf("请输入查找的元素的值:");
            scanf("%d",&e);
			i=LocateElem_L(L,e);
			if(i)
				printf("%d的逻辑位序是%d\n",e,i);
			else
				printf("查找失败!\n");
			break;	
			
		case 0:
			printf("程序结束，谢谢使用！\n\n");
			exit(0);
		}
	}
	return 0;
}

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
	L->next=NULL;
	printf("请逆序输入%d个元素:\n",n);
	for(i=n;i>=1;i--)
	{
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);	//格式输入字符串补出来
		p->next=L->next;
		L->next=p;
	}
}
//输出单链表
void PrintList_L(LinkList L)
{
	LinkList p;
	p=L->next;
	printf("输出链表中的元素:\n");
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
           //P29 算法2.8

	int j;
	LinkList p;
	p=L->next;
	j=1;
	while(p&&j<i){
		p=p->next;
		++j;
	}
	if(!p||j>i) return ERROR;
	e=p->data;
	return e; 
} 



//插入函数  
Status  ListInsert_L(LinkList &L,int i,ElemType e)
{
           //P29~30 算法2.9
	LinkList p,s;
	int j;
	p=L;
	j=0;
	while(p&&j<i-1) {p=p->next;++j;}    //寻找第i-1个结点
	if(!p||j>i-1) return ERROR;    //i小于1或者大于表长加1
	s=(LinkList)malloc(sizeof(LNode));    //生成新结点
	s->data=e; 
	s->next=p->next;                      //插入L中
	p->next=s;
	return OK;
}   //ListInsert_L



//删除函数  
Status ListDelete_L(LinkList &L,int i,ElemType &e)
{
           //P30 算法2.10
	//在带头结点的单链线性表L中，删除第i个元素，并有e返回其值
	LinkList p,q;
	int j;
	p=L;j=0;       //j=1;j<i;
	while(p->next&&j<i-1) {   //寻找第i个结点，并令p指向其前趋
		p=p->next;
		++j;
	}
	if(!(p->next)||j>i-1) return ERROR;   //删除位置不合理
	q=p->next;p->next=q->next;            //删除并释放结点
	e=q->data;free(q);
	return OK;
}//ListDelete_L
 


//取元素
//查找给定值的位序
int LocateElem_L(LinkList L,ElemType e)//找到返回逻辑位序,未找到返回0
{
	LinkList p;    //补出变量定义
	int i;		    //补出变量定义
	i=1;		    //当前元素的逻辑位序	
	p=L->next;
	while(p!=NULL){
		if(p->data!=e)
		{
			i++;
			p=p->next;
		}
		else 
			break;
	}
	if(p==NULL) return 0;
	return i;
	
}
