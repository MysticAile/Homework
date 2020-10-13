//Ԥ��������
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
//���ݽṹ
typedef int Status;
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
//��������
int menu_select();
int menu_select();
void CreateList_L(LinkList &L,int n);
void PrintList_L(LinkList L);
//������
int main()
{
    LinkList L;
    int n;
    for(;;)
    {
        switch(menu_select())
        {
        case 1:
            printf("������Ԫ�صĸ���:");
            scanf("%d",&n);
            CreateList_L(L,n);
            printf("�������\n");
            break;
        case 2:
            PrintList_L(L);
            break;
        case 3:
            printf("���ò��Һ���(��֪λ����Ԫ��)\n");
            break;
        case 4:
            printf("���ò��뺯��\n");
            break;
        case 5:
            printf("����ɾ������\n");
            break;
        case 6:
            printf("���ò��Һ�������֪Ԫ����λ��\n");
            break;
        case 0:
            printf("���������ллʹ��\n\n");
            exit(0);                        
        }
    }
    return 0;
}
//�˵�����
int menu_select()
{
	int sn;
	printf("\n��ʾ�˵�\n");
	printf("1.����\n"); 
	printf("2.��ʾ\n");
	printf("3.ȡԪ��\n");
	printf("4.����\n");
	printf("5.ɾ��\n");
	printf("6.����\n");
	printf("0.�˳�\n");
	printf("���� 0-6:");
	for(;;)
	{
		scanf("%d",&sn);
		if(sn<0||sn>6)
			printf("\n���������ѡ0��6��");
		else
			break;
	}
	return sn;
}
//����������ͷ�巨����֪���Ա�ĳ���
void CreateList_L(LinkList &L,int n)
{
    LinkList p;
    int i;
    L=(LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    printf("����������%d��Ԫ��:\n",n);
    for(i=n;i>=1;i--)
    {
        p=(LinkList)malloc(sizeof(LNode));
        scanf("%d",&p->data);//��ʽ�����ַ���������
        p->next=L->next;
        L->next = p;
    }
}
//���������
void PrintList_L(LinkList L)
{
    LinkList p;
    p = L->next;
    printf("���������е�Ԫ��:\n");
    while(p)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}
//ȡԪ�غ���
Status GetElem_L(LinkList &L,int i, ElemType &e)
{
    LinkList p;
    p=L;
    j=0;
    while(p&&j<i-1)
    {
        p = p->next;
        ++j;
    }//Ѱ�ҵ�i-1�����
    if(!p||j>i-1)
        return ERROR;//iС��1���ߴ��ڱ���1
    s=(LinkList)malloc(sizeof(LNode));//�����½��
    s->data = e;
    s->next = p->next;//����L��
    p->next = s;
    return OK;    
}