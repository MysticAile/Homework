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
void  CreateList_L(LinkList &L,int n);
void PrintList_L(LinkList L);
Status GetElem_L(LinkList &L,int i, ElemType &e);
Status  ListInsert_L(LinkList &L,int i,ElemType e); //����
Status ListDelete_L(LinkList &L,int i,ElemType &e); //ɾ��
int LocateElem_L(LinkList L,ElemType e);//���� 

//������
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
			printf("������Ԫ�صĸ���:");
			scanf("%d",&n);			
			CreateList_L(L,n);
			printf("�������\n");
			break;

		case 2:		
			PrintList_L(L);
			break;

		 case 3:
			printf("��������ҵ�Ԫ�ص�λ��:");
            scanf("%d",&i);
			e=GetElem_L(L,i,e);//ָ�������͵�ָ�����βΣ�ʵ����ͬ���͵ĺ�����equal
			if(i)
				printf("��%d��Ԫ����%d \n",i,e);
			else
				printf("����ʧ��!\n");
			break;

		 case 4:
			printf("����������λ��:");
            scanf("%d",&i);
			printf("������������Ԫ�ص�ֵ:");
			scanf("%d",&e);
			s=ListInsert_L(L,i,e);
			if(s)
				printf("����ɹ�!\n");
			else
				printf("����ʧ��!\n");
			break;

		 case 5:
			printf("����ɾ����λ��");
			scanf("%d",&i);
			e=ListDelete_L(L,i,e);
			if(e)
				printf("ɾ����Ԫ��%d�ɹ�\n",e);
			else
				printf("ɾ��ʧ��\n");
			break;

		 case 6:
			printf("��������ҵ�Ԫ�ص�ֵ:");
            scanf("%d",&e);
			i=LocateElem_L(L,e);
			if(i)
				printf("%d���߼�λ����%d\n",e,i);
			else
				printf("����ʧ��!\n");
			break;	
			
		case 0:
			printf("���������ллʹ�ã�\n\n");
			exit(0);
		}
	}
	return 0;
}

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
	L->next=NULL;
	printf("����������%d��Ԫ��:\n",n);
	for(i=n;i>=1;i--)
	{
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);	//��ʽ�����ַ���������
		p->next=L->next;
		L->next=p;
	}
}
//���������
void PrintList_L(LinkList L)
{
	LinkList p;
	p=L->next;
	printf("��������е�Ԫ��:\n");
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
           //P29 �㷨2.8

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



//���뺯��  
Status  ListInsert_L(LinkList &L,int i,ElemType e)
{
           //P29~30 �㷨2.9
	LinkList p,s;
	int j;
	p=L;
	j=0;
	while(p&&j<i-1) {p=p->next;++j;}    //Ѱ�ҵ�i-1�����
	if(!p||j>i-1) return ERROR;    //iС��1���ߴ��ڱ���1
	s=(LinkList)malloc(sizeof(LNode));    //�����½��
	s->data=e; 
	s->next=p->next;                      //����L��
	p->next=s;
	return OK;
}   //ListInsert_L



//ɾ������  
Status ListDelete_L(LinkList &L,int i,ElemType &e)
{
           //P30 �㷨2.10
	//�ڴ�ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
	LinkList p,q;
	int j;
	p=L;j=0;       //j=1;j<i;
	while(p->next&&j<i-1) {   //Ѱ�ҵ�i����㣬����pָ����ǰ��
		p=p->next;
		++j;
	}
	if(!(p->next)||j>i-1) return ERROR;   //ɾ��λ�ò�����
	q=p->next;p->next=q->next;            //ɾ�����ͷŽ��
	e=q->data;free(q);
	return OK;
}//ListDelete_L
 


//ȡԪ��
//���Ҹ���ֵ��λ��
int LocateElem_L(LinkList L,ElemType e)//�ҵ������߼�λ��,δ�ҵ�����0
{
	LinkList p;    //������������
	int i;		    //������������
	i=1;		    //��ǰԪ�ص��߼�λ��	
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
