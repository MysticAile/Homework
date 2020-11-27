/*�����������ռ�Ч��*/
/*������Ļ�������
  ���� ���� ɾ�� ����*/
#include <stdio.h>
typedef int ElemType;
typedef struct Node /*�ڵ����Ͷ���*/
{
    ElemType data;
    struct Node *next;

} Node, *Linklist;       /*  *LinklistΪ�ṹָ������*/
Linklist CreatFromHead() /*ͷ�巨����*/
{
    Linklist L;
    Node *s;
    int flag = 1;
    char c;
    L = (Linklist)malloc(sizeof(Node));
    L->next = NULL;
    while (flag)
    {
        c = getchar();
        if (c != 'n')
        {
            s = (Node *)malloc(sizeof(Node));
            s->data = c;
            s->next = L->next;
            L->next = s;
        }
        else
        {
            flag = 0;
        }
    }
    return L;
}
Linklist CreatFromTail() /*���¼ӵĽڵ����β��*/
{
    Linklist L;
    Node *r, *s;
    int flag = 1;
    char c;
    L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
    r = L;
    while (flag)
    {
        c = getchar();
        if (c != 'n')
        {
            s = (Node *)malloc(sizeof(Node));
            s->data = c;
            r->next = s;
            r = s;
        }
        else
        {
            flag = 0;
            r->next = NULL;
        }
    }
    return L;
}
void InsList(Linklist L, int i, ElemType e)
{
    /*��ͷ���ĵ�����L�еĵ�i���ڵ�֮ǰ����ֵΪe���½ڵ�*/
    Node *pre, *s;
    pre = L;
    int k = 0;
    while (pre != NULL && k < i - 1)
    {
        /*���ҵ���i-1������Ԫ�صĴ洢λ��,ʹָ��Preָ����*/
        pre = pre->next;
        k = k + 1;
    }
    if (k != i - 1)
    {
        printf("�����λ�ò�����");
        return;
    }
    s = (Node *)malloc(sizeof(Node));
    s->data = e;
    s->next = pre->next;
    pre->next = s;
}
void DellList(Linklist L, int i, ElemType *e)
{ /*�ڴ�ͷ���ĵ�����L��ɾ����i��Ԫ�أ���������ֵ������*e��*/
    Node *p, *r;
    p = L;
    int k = 0;
    while (p->next != NULL && k < i - 1) /*Ѱ�ұ�ɾ�����i��ǰ�����*/
    {
        p = p->next;
        k = k + 1;
    }
    if (k != i - 1)
    /* ��whileѭ������Ϊp->next=NULL��������*/
    {
        printf("ɾ������λ��i������");
        return -1;
    }
    r = p->next;
    p->next = p->next->next; /*�ͷű�ɾ���Ľ����ռ���ڴ�ռ�*/
    free(r);
}
int ListLength(Linklist L) /*LΪ��ͷ���ĵ�����*/
{
    Node *p;
    p = L->next;
    int j = 0; /*������ŵ�����ĳ���*/
    while (p != NULL)
    {
        p = p->next;
        j++;
    }
    return j;
}
Node *Get(Linklist L, int i)
{
    Node *p;
    p = L;
    int j = 0;
    /*��ͷ��㿪ʼɨ�� */
    while ((p->next != NULL) && (j < i))
    {
        p = p->next;
        j++;
        /*ɨ����һ���*/
    }
    /*��ɨ��������� */
    if (i == j)
        return p;
    /*�ҵ��˵�i�����*/
    else
        return NULL;
    /*�Ҳ�����i��0��i >n*/
}
Node *Locate(Linklist L, ElemType key)
{
    Node *p;
    p = L->next;
    /*�ӱ��е�һ�����Ƚ�*/
    while (p != NULL)
        if (p->data != key)
            p = p->next;
        else
            break;
    /*�ҵ����key���˳�ѭ�� */
    return p;
}
/*��֪���Ե������ʾ���ϣ����輯��A�õ�����LA��ʾ������B��
������LB��ʾ������㷨���������ϵĲ��A-B�� ? �㷨˼�룺�ɼ�������Ĺ����֪�����ϵĲ�A-B�а�����������
����A�������ڼ���B��Ԫ�ء����������ǣ����ڼ���A�е�ÿ��Ԫ
��e���ڼ���B������LB�н��в��ң���������e��ͬ��Ԫ�أ����
LA�н���ɾ��*/
void Difference(Linklist LA, Linklist LB) /*���㷨���������ϵĲ*/
{
    Node *pre, *p, *r, *q;
    pre = LA;
    p = LA->next; /*p����е�ĳһ��㣬preʼ��ָ��p��ǰ��*/
    while (p != NULL)
    {
        q = LB->next; /*ɨ��LB�еĽ�㣬Ѱ����LA��*P�����ͬ�Ľ��*/
        while (q != NULL && q->data != p->data)
            q = q->next;
        if (q != NULL)
        {
            r = p;
            pre->next = p->next;
            p = p->next;
            free(r);
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}