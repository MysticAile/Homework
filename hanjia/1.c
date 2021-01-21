#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define M 8
#define N 8
typedef struct node
{
    int x, y, di;
} Snode;
typedef struct linknode
{
    Snode node;            //������
    struct linknode *next; //ָ��
} Stack;
int mg[M + 2][N + 2] =
    {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
     {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
     {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
     {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
     {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
     {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
     {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
     {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
     {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
void InitStack(Stack **s);
bool StackEmpty(Stack *s);
bool Pop(Stack *s);
void Push(Stack *s, int x1, int y1, int d1);
bool GetTop(Stack *s, Snode *t);
void DestoryStack(Stack *s);
bool MgPath(int xi, int yi, int xe, int ye); //����Թ�

void InitStack(Stack **s) //��ʼ��ջ
{
    *s = (Stack *)malloc(sizeof(Stack));
    (*s)->next = NULL;
}
void DestoryStack(Stack *s) //����ջ
{
    Stack *p = s, *q = s->next;
    while (q != NULL)
    {
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}
bool StackEmpty(Stack *s) //�ж�ջ�Ƿ�Ϊ��
{
    return (s->next == NULL);
}
void Push(Stack *s, int x1, int y1, int d1) //��ջ
{
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->node.x = x1;
    p->node.y = y1;
    p->node.di = d1;
    p->next = s->next; //��ʽջ,�˴����õ���ͷ�巨������,��Ϊջ���������Ƚ����,ÿ�β���ͷ�巨ͷָ��ָ��ջ��Ԫ��
    s->next = p;
}
bool Pop(Stack *s) //��ջ
{
    Stack *p;
    if (s->next == NULL)
        return false;
    p = s->next;
    s->next = p->next;
    free(p);
    return true;
}
bool GetTop(Stack *s, Snode *t) //ȡջ��Ԫ��
{
    if (s->next == NULL)
        return false;
    *t = s->next->node;
}
bool MgPath(int xi, int yi, int xe, int ye)
{
    Snode t;
    int x, y, di, k = 0, find;
    Stack *s;
    InitStack(&s);
    Push(s, xi, yi, -1);   //��ڽ�ջ����λ����Ϊ-1;
    mg[xi][yi] = -1;       //��ǰ����������֮����Ϊ-1��ʾ�Ѿ��߹�
    while (!StackEmpty(s)) //ջ��Ϊ��
    {
        GetTop(s, &t);
        x = t.x;
        y = t.y;
        di = t.di;              //ȡջ������
        if (x == xe && y == ye) //�ҵ��˳���,���·��
        {
            printf("�Թ�·������:\n");
            while (GetTop(s, &t) && Pop(s))
            {
                k++;
                printf("(%d,%d,%d) ", t.x, t.y, t.di);
                if (k % 5 == 0)
                    printf("\n");
            }
            printf("\n");
            return true;
        }
        find = 0;
        di = 0;
        while (di < 4 && find == 0) //�ҵ���һ�����߷���
        {

            di++;
            switch (di)
            {
            case 0:
                x = t.x - 1, y = t.y - 1, t.di = 0;
                break;
            case 1:
                x = t.x, y = t.y + 1, t.di = 1;
                break;
            case 2:
                x = t.x + 1, y = t.y, t.di = 2;
                break;
            case 3:
                x = t.x, y = t.y - 1, t.di = 3;
                break;
            }

            if (mg[x][y] == 0)
                find = 1; //�ҵ�һ�����ڵķ���
        }
        if (find == 1)
        {
            Push(s, x, y, t.di);
            mg[x][y] = -1; //�����ߵ��ظ�����
        }
        else //���ڷ��鶼��������
        {
            mg[x][y] = 0; //��ǻ�ԭ
            Pop(s);
        }
    }
    return false; //��ʾû��·��
}
int main(void)
{
    if (!MgPath(1, 1, M, N))
        printf("���Թ��޽�!");
}