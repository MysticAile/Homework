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
    Snode node;            //数据域
    struct linknode *next; //指针
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
bool MgPath(int xi, int yi, int xe, int ye); //求解迷宫

void InitStack(Stack **s) //初始化栈
{
    *s = (Stack *)malloc(sizeof(Stack));
    (*s)->next = NULL;
}
void DestoryStack(Stack *s) //销毁栈
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
bool StackEmpty(Stack *s) //判断栈是否为空
{
    return (s->next == NULL);
}
void Push(Stack *s, int x1, int y1, int d1) //进栈
{
    Stack *p = (Stack *)malloc(sizeof(Stack));
    p->node.x = x1;
    p->node.y = y1;
    p->node.di = d1;
    p->next = s->next; //链式栈,此处采用的是头插法建立的,因为栈的特性是先进后出,每次采用头插法头指针指向栈顶元素
    s->next = p;
}
bool Pop(Stack *s) //出栈
{
    Stack *p;
    if (s->next == NULL)
        return false;
    p = s->next;
    s->next = p->next;
    free(p);
    return true;
}
bool GetTop(Stack *s, Snode *t) //取栈顶元素
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
    Push(s, xi, yi, -1);   //入口进栈，方位设置为-1;
    mg[xi][yi] = -1;       //当前方块访问完成之后标记为-1表示已经走过
    while (!StackEmpty(s)) //栈不为空
    {
        GetTop(s, &t);
        x = t.x;
        y = t.y;
        di = t.di;              //取栈顶方块
        if (x == xe && y == ye) //找到了出口,输出路径
        {
            printf("迷宫路径如下:\n");
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
        while (di < 4 && find == 0) //找到下一个可走方块
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
                find = 1; //找到一个相邻的方块
        }
        if (find == 1)
        {
            Push(s, x, y, t.di);
            mg[x][y] = -1; //避免走到重复方块
        }
        else //相邻方块都不可以走
        {
            mg[x][y] = 0; //标记还原
            Pop(s);
        }
    }
    return false; //表示没有路径
}
int main(void)
{
    if (!MgPath(1, 1, M, N))
        printf("该迷宫无解!");
}