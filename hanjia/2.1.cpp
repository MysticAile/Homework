#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 3;           //停车场所能容纳车的数量
typedef pair<int, int> time; //时间 XX:XX
typedef struct
{
    string car_number;
    time reach, leave;
} Car;      
typedef struct
{
    Car *stack[MAX + 1];
    int top;
} SqStack;
typedef struct car
{
    Car *data;
    struct car *next;
} Link;
typedef struct Node
{
    Link *head; //队头指针
    Link *rear; //对尾指针
} NODE;
void Crate(SqStack *s, int n);                      //初始化停车场
void print(Car *p);                                 //输出汽车离开信息
void Arrive(SqStack *A, NODE *B, int n);            //汽车进入停车场
int Cratelink(NODE *Q);                             //初始化便道
void Leave(SqStack *A, SqStack *C, NODE *B, int n); //汽车离开停车场
int main(void)
{
    SqStack Enter, Num;
    NODE Waitcar;
    int ch, n;
    n = MAX;
    Crate(&Enter, n);
    Crate(&Num, n);
    Cratelink(&Waitcar);
    while (1)
    {
        cout << "       停车场管理系统     " << endl;
        cout << " *******************************" << endl;
        cout << "       1.车辆进站      " << endl;
        cout << "       2.车辆出站      " << endl;
        cout << "       3.退出系统      " << endl;
        cout << "Please Enter : 1~3: " << endl;
        cin >> ch;
        if (ch > 3 || ch < 1)
        {
            do
            {
                cout << "输入有误,请重新输入" << endl;
                cin >> ch;
            } while (ch <= 3 && ch >= 1);
        }
        switch (ch)
        {
        case 1:
            Arrive(&Enter, &Waitcar, n);
            break;
        case 2:
            Leave(&Enter, &Num, &Waitcar, n);
            break;
        case 3:
            exit(0);
        default:
            break;
        }
    }
}
void Crate(SqStack *s, int n) //初始化停车场
{
    int i = 0;
    s->top = 0;
    s->stack[s->top] = NULL;
}
int Cratelink(NODE *Q) //初始化便道队列
{
    Q->head = new Link;
    if (Q->head != NULL)
    {
        Q->head->next = NULL;
        Q->rear = Q->head;
        return 1;
    }
    else
        return 0;
}
void Arrive(SqStack *A, NODE *B, int n) //汽车进入停车场
{
    Car *p;
    Link *t;
    char c;
    p = new Car;
    cout << "请输入车牌号:" << endl;
    cin >> p->car_number;
    if (A->top < n)
    {
        A->top++;
        cout << "请输入到达的时间:" << endl;
        cin >> p->reach.first >> c >> p->reach.second;
        cout << "车辆在停车场的位置为" << A->top << endl
             << endl;
        A->stack[A->top] = p;
    }
    else
    {
        cout << "停车场已经满了,需要等候" << endl;
        t = new Link;
        t->data = p;
        t->next = NULL;
        B->rear->next = t;
        B->rear = t;
    }
}
void Leave(SqStack *A, SqStack *C, NODE *B, int n) //汽车离开停车场
{
    int room;   //车所要离开位置
    Car *p, *t; //p保存要离开的车
    Link *q;
    cout << "请输入要离开的车所在的位置" << endl;
    cin >> room;
    while (A->top > room) //借助另一个栈完成车的让道
    {
        C->top++;
        C->stack[C->top] = A->stack[A->top];
        A->stack[A->top] = NULL;
        A->top--;
    }
    p = A->stack[A->top];
    A->stack[A->top] = NULL;
    A->top--;
    while (C->top >= 1)
    {
        A->top++;
        A->stack[A->top] = C->stack[C->top];
        C->stack[C->top] = NULL;
        C->top--;
    }
    print(p);
    if ((B->head != B->rear) && A->top < n)
    {
        q = B->head->next;
        t = q->data;
        A->top++;
        cout << "便道上汽车进入停车场，该车的车牌号为:"
             << t->car_number << endl;
        cout << "该车进入停车场的位置为:" << A->top << endl;
        B->head->next = q->next;
        if (q == B->rear)
            B->rear = B->head;
        A->stack[A->top] = t;
        free(q);
    }
}
void print(Car *p) //打印汽车离开信息
{
    int A1, A2, B1, B2, t, h, m; //h小时 m分钟
    char ch;                     //处理输入时间的 ：
    cout << "请输入离开的时间: " << endl;
    cin >> p->leave.first >> ch >> p->leave.second;
    A1 = p->reach.first, A2 = p->reach.second, B1 = p->leave.first, B2 = p->leave.second;
    t = (B1 - A1) * 60 + B2 - A2;
    if (t >= 60)
    {
        h = t / 60;
        m = t - 60 * h;
    }
    else
    {
        h = 0;
        m = t;
    }
    cout << "       出站车辆的信息" << endl;
    cout << "    *******************************" << endl;
    cout << "车牌号: " << p->car_number << endl;
    cout << "进入停车场的时间     " << endl;
    cout << p->reach.first << ":" << p->reach.second << endl;
    cout << "出停车场的时间        " << endl;
    cout << p->leave.first << ":" << p->leave.second << endl;
    cout << "停留的时间：  " << endl;
    cout << h << "h" << m << "m" << endl;
    cout << "车辆应付费用(每分钟0.1元):" << endl;
    cout << 0.1 * t << "元" << endl
         << endl;

    free(p); //释放节点
}
