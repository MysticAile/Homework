/**
���е���ʽ�洢�ṹ������������ʵ��
��������洢�Ķ��г�Ϊ���ӣ�������ò���ͷ�ڵ�ĵ�����ʵ�֡�
ͨ������ͷ�Ͷ�β����ָ�������
�������: 
��1���洢����Ԫ�صĵ�����ڵ�
��2��ָ���ͷ�Ͷ�βָ�������ͷ�ڵ�
����ѭ��������
���ӵ�4Ҫ�أ�
�ӿյ�����:front=rear=NULL
��������:������
����e����:������e�Ľڵ���뵽�������β
���Ӳ���:ɾ��������������ݽڵ�
**/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ElemType int
typedef struct Qnode //���ݽڵ�
{
    ElemType data; //����Ԫ��
    struct Qnode *next;

} QNode;
typedef struct
{
    QNode *front; //ָ��ͷ�ڵ�
    QNode *rear;  //ָ��β�ڵ�
} LiQueue;

void InitQueue(LiQueue **q);           //��ʼ������
void DestroyQueue(LiQueue *q);         //���ٶ���
bool QueueEmpty(LiQueue *q);           //�ж϶����Ƿ�Ϊ��
void EnQueue(LiQueue **q, ElemType e); //����
bool DeQueue(LiQueue *q, ElemType *e); //����
int main()
{
}
void InitQueue(LiQueue **q)
{
    (*q) = (LiQueue *)malloc(sizeof(LiQueue));
    (*q)->front = (*q)->rear = NULL;
}
void DestroyQueue(LiQueue *q)
{
    QNode *p = q->front, *r; //pָ���ͷ�����ݽڵ�
    if (p != NULL)
    {
        r = p->next;
        while (r != NULL)
        {
            free(p);
            p = r;
            r = p->next;
        }
    }
    free(p);
    free(q); //�ͷ����ӽڵ�ռ�õĿռ�
}
bool QueueEmpty(LiQueue *q)
{
    return (q->rear == NULL);
}
void EnQueue(LiQueue *q, ElemType e)
{
    QNode *p;
    p = (QNode *)malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    if (q->rear == NULL) //������Ϊ��,�½ڵ��Ƕ��׽ڵ����Ƕ�β�ڵ�
        q->front = q->rear = p;
    else
    {
        q->rear->next = p; //��*p�ڵ�������β,����rearָ����
        q->rear = p;
    }
}
bool DeQueue(LiQueue *q, ElemType *e)
{
    QNode *t;
    if (q->rear == NULL)
        return false;        //����Ϊ��
    t = q->front;            //tָ���һ�����ݽڵ�
    if (q->front == q->rear) //������ֻ��һ���ڵ�ʱ
        q->front = q->rear = NULL;
    else //�������ж���ڵ�ʱ
        q->front = q->front->next;
    *e = t->data;
    free(t);
    return true;
}