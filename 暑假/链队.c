/**
����һ������ͷ�ڵ�ֻ��һ��β�ڵ�ָ��rear��ѭ��
������洢���У���ƶ��еĳ�ʼ�������Ӻͳ��ӵ��㷨
���ӵ�4Ҫ�أ�
�ӿ�������rear=NULL
����������������
����e������������e�Ľڵ���뵽�������β
���Ӳ�����ɾ���������׽ڵ�
**/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ElemType int
typedef struct node
{
    int data;
    struct node *next;
} LinkList;
void InitQueue(LinkList **rear) //��ʼ��
{
    (*rear) = (LinkList *)malloc(sizeof(LinkList));
    *rear = NULL;
}
bool QueueEmpty(LinkList *rear) //�жϿ������㷨
{
    return (rear == NULL);
}
void EnQueue(LinkList *rear, ElemType x)
{
    LinkList *p;
    p = (LinkList *)malloc(sizeof(LinkList));
    p->data = x;
    if (rear == NULL)
    {
        p->next = p;
        rear = p;
    }
    else
    {
        p->next = rear->next;
        rear->next = p;
        rear = p;
    }
}
bool DeQueue(LinkList *rear, ElemType *x) //��������
{
    LinkList *q;
    if (rear == NULL)
        return false;            //�ӿ�
    else if (rear->next == rear) //ԭ����ֻ��һ���ڵ�
    {
        x = rear->data;
        free(rear);
    }
    else
    {
        q = rear->next;
        x = q->data;
        rear->next = q->next;
        free(q);
    }
    return true;
}