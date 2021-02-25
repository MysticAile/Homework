#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define M 8
#define N 8
typedef struct node
{
    int x, y, di;
} Snode;
typedef struct link
{
    Snode node;            //������
    struct link *next; //ָ��
} NODE;
int Maze[M + 2][N + 2] = //�����Թ�
    {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
     {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
     {1, 1, 1, 1, 0, 1, 0, 1, 1, 1},
     {1, 0, 0, 1, 0, 0, 1, 0, 1, 1},
     {1, 1, 0, 0, 1, 0, 0, 0, 0, 1},
     {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
     {1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
     {1, 0, 0, 0, 0, 1, 1, 1, 0, 1},
     {1, 0, 0, 0, 0, 1, 1, 1, 0, 1},
     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
void Create(NODE **s); //��ʼ��
void Destroy(NODE *s); //����
bool Judge(NODE *s);   //�ж�ջ��
void Enter(NODE *s, int x1, int y1, int d1);//��ջ
bool Out(NODE *s);//��ջ
bool GetTop(NODE *s, Snode *t);//���ջ��Ԫ��

bool MazePath(int xi, int yi, int xe, int ye); //����Թ�
int main(void)
{
    if (!MazePath(1, 1, M, N))
        printf("���Թ��޽�!");
    system("pause");
}

void Create(NODE **s)
{
    *s = (NODE *)malloc(sizeof(NODE));
    (*s)->next = NULL;
}
void Destroy(NODE *s)
{
    NODE *p = s, *q = s->next;
    while (q != NULL)//��������ջ
    {
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}

void Enter(NODE *s, int x1, int y1, int d1) //��ջ
{
    NODE *p = (NODE *)malloc(sizeof(NODE)); //ͷ�巨
    p->node.x = x1;
    p->node.y = y1;
    p->node.di = d1;
    p->next = s->next;
    s->next = p;
}
bool Out(NODE *s) //��ջ
{
    NODE *p;
    if (s->next == NULL)
        return false;
    p = s->next;
    s->next = p->next;
    free(p);
    return true;
}
bool Judge(NODE *s) //�ж�ջ�Ƿ��ǿ�ջ
{
    return (s->next == NULL);
}
bool GetTop(NODE *s, Snode *t) //���ջ��Ԫ��
{
    if (s->next == NULL)
        return false;
    *t = s->next->node;
}
bool MazePath(int xi, int yi, int xe, int ye)//���Թ�·��
{
    Snode t;
    int x, y, di, k = 0, find;//��������
    NODE *s;
    Create(&s);//����ջ
    Enter(s, xi, yi, -1); //��ʼ��ջ
    Maze[xi][yi] = -1;      //�Ѿ��߹��ı�Ϊ-1
    while (!Judge(s))     //ջ��Ϊ��
    {
        GetTop(s, &t);//���ջ��Ԫ��
        x = t.x;
        y = t.y;
        di = t.di;             
        if (x == xe && y == ye) //���·��
        {
            printf("�Թ�·������:\n");
            while (GetTop(s, &t) && Out(s))//��������Թ�·��
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
        while (di < 4 && find == 0) //����Ѱ��·��
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
            if (Maze[x][y] == 0)//�ж��Թ��иõ��Ƿ�Ϊ��
                find = 1;
        }
        if (find == 1)
        {
            Enter(s, x, y, t.di);
            Maze[x][y] = -1; //�����ߵ��ظ���·��
        }
        else //��������ͬ
        {
            Maze[x][y] = 0;
            Out(s);//��ջ
        }
    }
    return false;
}