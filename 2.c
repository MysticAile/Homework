//Ԥ��������
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define LIST_INIT_SIZE 10 // ��洢�ռ�ĳ�ʼ������
#define LISTINCRMENT 2   // ���Ա�洢�ռ�ķ�������
//���ݽṹ
typedef int Status;
typedf int ElemType;
typedef struct 
{
    ElemType *elem;   // �洢�ռ��ַ
    int length;       // ��ǰ����
    int listsize;     // ��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ��
}Sqlist;
//��������
int menu_select();
Status InitList_Sq(Sqlist &L);
Status CreatList_Sq(SqList &L,int n);
void PrintList_Sq(SqList L);
//������
int main()
{
    
}
//�˵�����
int menu_select()
{
    int sn;
    printf("\n��ʾ�˵�\n");
    printf("1.��ʼ��\n");
    printf("2.����\n");
    printf("3.��ʾ\n");
    printf("4.����\n");
    printf("5.ɾ��\n");
    printf("6.����\n");
    printf("���� 0-6:");
    for(;;)
    {
        scanf("%d",&sn);
        if(sn<0||sn>6)
            printf("\n�������,��ѡ0-6: ");
        else
        {
            break;
        }

    }
    return sn;
}
//��ʼ���յĶ�̬˳�����
Status InitList_Sq(Sqlist &L)
{
    L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemTyp));
    if(!L.elem)   return(OVERFLOW);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}
//������̬˳�������n��Ԫ�أ�
Status CreatList_Sq(SqList &L,int n)
{
    int i;
    if(n>L.listsize)
        return(ERROR);
    printf("����%d����������",n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&L.elem[i-1]);//��c�������޸�ʽ�����ַ�������Ҫ����
    }    
    L.length=n;
    return OK;
}
//���˳���Ԫ��
void PrintList_Sq(SqList L)
{
    int i;
    for(i=1;i<=L.length;i++)
    {
        printf("%d\t",L.elem[i-1]);
    }
    printf("\n");
}