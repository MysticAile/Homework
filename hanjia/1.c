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
    Snode node;            //数据域
    struct link *next; //指针
} NODE;
int Maze[M + 2][N + 2] = //创建迷宫
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
void Create(NODE **s); //初始化
void Destroy(NODE *s); //销毁
bool Judge(NODE *s);   //判断栈空
void Enter(NODE *s, int x1, int y1, int d1);//进栈
bool Out(NODE *s);//出栈
bool GetTop(NODE *s, Snode *t);//获得栈顶元素

bool MazePath(int xi, int yi, int xe, int ye); //求解迷宫
int main(void)
{
    if (!MazePath(1, 1, M, N))
        printf("该迷宫无解!");
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
    while (q != NULL)//遍历销毁栈
    {
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}

void Enter(NODE *s, int x1, int y1, int d1) //进栈
{
    NODE *p = (NODE *)malloc(sizeof(NODE)); //头插法
    p->node.x = x1;
    p->node.y = y1;
    p->node.di = d1;
    p->next = s->next;
    s->next = p;
}
bool Out(NODE *s) //出栈
{
    NODE *p;
    if (s->next == NULL)
        return false;
    p = s->next;
    s->next = p->next;
    free(p);
    return true;
}
bool Judge(NODE *s) //判断栈是否是空栈
{
    return (s->next == NULL);
}
bool GetTop(NODE *s, Snode *t) //获得栈顶元素
{
    if (s->next == NULL)
        return false;
    *t = s->next->node;
}
bool MazePath(int xi, int yi, int xe, int ye)//求迷宫路径
{
    Snode t;
    int x, y, di, k = 0, find;//创建变量
    NODE *s;
    Create(&s);//创建栈
    Enter(s, xi, yi, -1); //开始进栈
    Maze[xi][yi] = -1;      //已经走过的标为-1
    while (!Judge(s))     //栈不为空
    {
        GetTop(s, &t);//获得栈顶元素
        x = t.x;
        y = t.y;
        di = t.di;             
        if (x == xe && y == ye) //输出路径
        {
            printf("迷宫路径如下:\n");
            while (GetTop(s, &t) && Out(s))//遍历输出迷宫路径
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
        while (di < 4 && find == 0) //继续寻找路径
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
            if (Maze[x][y] == 0)//判断迷宫中该点是否为零
                find = 1;
        }
        if (find == 1)
        {
            Enter(s, x, y, t.di);
            Maze[x][y] = -1; //避免走到重复的路径
        }
        else //进入死胡同
        {
            Maze[x][y] = 0;
            Out(s);//出栈
        }
    }
    return false;
}