//预编译命令
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2

//数据结构定义
typedef int Status;
typedef int TElemType; //数据元素为整型
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//函数声明
int menu_select();
Status InitBiTree(BiTree &T);
Status CreateBiTree(BiTree &T);
void PreOrderTraverse(BiTree T, Status (*Visit)(TElemType));
Status PrintElem(TElemType e);
void DisplayTree(BiTree T, int i);

void input(TElemType a[], int n);
void output(TElemType a[], int n);
int Locate(TElemType a[], TElemType ch, int m, int n);
//主函数
int main()
{
	BiTree T;
	Status s;
	for (;;)
	{
		switch (menu_select())
		{
		case 1:
			s = InitBiTree(T);
			if (s)
				printf("初始化成功\n");
			else
				printf("初始化失败\n");
			break;
		case 2:
			printf("请输入二叉树的扩展先序序列：");
			s = CreateBiTree(T);
			if (s)
				printf("创建成功\n");
			else
				printf("创建失败\n");
			break;
		case 3:
			printf("先序遍历序列为：\n");
			PreOrderTraverse(T, PrintElem);
			break;
		case 4:
			printf("输出中序遍历序列\n");
			break;
		case 5:
			printf("输出后序遍历序列\n");
			break;
		case 6:
			printf("凹入显示\n");
			DisplayTree(T, 0);
			break;
		case 7:
			printf("求二叉树叶子结点的个数\n");
			break;
		case 8:
			printf("求二叉树深度\n");
			break;
		case 9:
			printf("查找等于给定值的结点\n");
			break;
		case 10:
			printf("销毁二叉树\n");
			break;
		case 0:
			printf("程序结束，谢谢使用！\n\n");
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
	printf("1.初始化一个空树（空树）\n");
	printf("2.用扩展的先序序列的方式创建二叉树\n");
	printf("3.输出先序遍历序列\n");
	printf("4.输出中序遍历序列\n");
	printf("5.输出后序遍历序列\n");
	printf("6.凹入显示二叉树（中序）删除\n");
	printf("7.求二叉树的叶结点的个数查找\n");
	printf("8.求二叉树的深度查找\n");
	printf("9.查找二叉树中的某个给定值\n");
	printf("10.销毁二叉树\n");
	printf("0.退出\n");
	printf("输入 0-10:");
	for (;;)
	{
		scanf("%d", &sn);
		if (sn < 0 || sn > 10)
			printf("\n输入错误，重选0－10：");
		else
			break;
	}
	return sn;
}
//初始化函数定义
Status InitBiTree(BiTree &T)
{
	T = NULL;
	return OK;
}
//创建二叉树
Status CreateBiTree(BiTree &T)
{
	TElemType ch;
	scanf("%d", &ch);
	if (ch == 0) //输入为0的元素
		T = NULL;
	else
	{
		T = (BiTNode *)malloc(sizeof(BiTNode));
		if (!T)
			exit(OVERFLOW);
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}
//先序遍历
void PreOrderTraverse(BiTree T, Status (*Visit)(TElemType))
{
	if (T)
	{
		Visit(T->data); // 先访问根结点
		PreOrderTraverse(T->lchild, Visit);
		PreOrderTraverse(T->rchild, Visit);
	}
}
//打印一个数据元素函数
Status PrintElem(TElemType e)
{
	printf("%d\t", e);
	return OK;
}
//中序凹入显示
void DisplayTree(BiTree T, int i)
{
	int j;
	if (T == NULL)
		return;
	if (T->lchild != NULL)
		DisplayTree(T->lchild, i + 1);
	for (j = 1; j <= i; j++)
		printf("\t");
	printf("       %d", T->data);
	for (j = i + 1; j <= 8; j++)
		printf("--------");
	printf("\n");
	if (T->rchild != NULL)
		DisplayTree(T->rchild, i + 1);
}
//输入遍历序列数组
void input(TElemType a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
}
//输出输入的数组
void output(TElemType a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}
//定位根结点的下标
int Locate(TElemType a[], TElemType ch, int m, int len)
{
	int i = m;
	while (i < m + len && a[i] != ch)
	{
		i++;
	}
	return i;
}