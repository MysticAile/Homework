/*栈
栈是一种只能在一端进行插入或删除操作的线性表。
栈只能选取同一个端点进行插入和删除操作
栈的几个概念
允许进行插入、删除操作的一端称为栈顶。 
表的另一端称为栈底。 
当栈中没有数据元素时，称为空栈。 
栈的插入操作通常称为进栈或入栈。 
栈的删除操作通常称为退栈或出栈。
栈的主要特点是“后进先出”，即后进栈的元素先出栈。栈也称为后进先出表。

约定top总是指向栈顶元素，初始值为-1 
当top=MaxSize-1时不能再进栈－栈满
进栈时top增1，出栈时top减1
栈空条件：top=-1
栈满条件：top=MaxSize-1
进栈e操作：top++; 将e放在top处
退栈操作：从top处取出元素e; top--;
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 20
#define ElemType int

typedef struct
{
    ElemType data[MaxSize];
    int top; //栈顶指针
} SqStack;
void InitStack(SqStack **s) //初始化栈
{
    (*s) = (SqStack *)malloc(sizeof(SqStack));
    (*s)->top = -1;
}
void DestroyStack(SqStack *s) //销毁栈
{
    free(s);
}
bool StackEmpty(SqStack *s) //判断栈是否为空
{
    return (s->top == -1);
}
bool Push(SqStack *s, int e) //进栈
{
    if (s->top == MaxSize - 1) //栈满的情况，即栈上溢出
        return false;
    s->top++;            //栈顶指针加1
    s->data[s->top] = e; //元素e放在栈顶指针处
    return true;
}
bool Pop(SqStack *s, int *e) //出栈
{
    if (s->top == -1)
        return false;
    *e = s->data[s->top]; //取栈定指针元素
    s->top--;
    return true;
}
bool GetTop(SqStack *s, int *e) //取栈顶元素
{
    if (s->top == -1) //栈为空的情况，栈下溢出
        return false;
    *e = s->data[s->top]; // 取栈顶指针元素的元素
    return true;
}
bool Match(char exp[], int n, SqStack *st)//匹配括号是否匹配
{
    int i = 0;
    int e;
    bool match = true;     //配对是为true，否则为false
    InitStack(&st);        //初始化栈
    while (i < n && match) //扫描exp中的所有字符
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') //遇到字符为左括号时候进栈
        {
            Push(st, exp[i]);
        }
        else
        {
            if (GetTop(st, &e) == true)
            {

                if ((exp[i] == ')' && char(e) == '(') || (exp[i] == '}' && char(e) == '{') || (exp[i] == ']' && char(e) == '['))
                    Pop(st, &e); //将栈定元素出栈
                else
                    match = false;
            }
            else
                match = false;
        }
        i++; //继续处理其它字符
    }
    if (!StackEmpty(st))
        match = false; //栈不为空表示不匹配
    DestroyStack(st);  //销毁栈
    return match;
}
void ShowMenu()
{
    printf("\n**************************\n");
    printf("\n1.栈的基本操作\n");
    printf("2.数值转化\n");
    printf("3.括号匹配\n");
    printf("\n输入你的选择\n");
}
int main()//主函数
{
    SqStack *S;
    int choice, n, i, e, k;
    char str[100];
    while (1)
    {
        ShowMenu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            InitStack(&S);
            printf("初始化栈成功\n");
            printf("创建n个元素的顺序栈\n");
            printf("请输入n的大小\n");
            scanf("%d", &n);
            printf("请在下面输入%d个元素\n", n);
            for (i = 0; i < n; i++)
            {
                scanf("%d", &e);
                Push(S, e);
            }
            GetTop(S, &e);
            printf("\n取出栈顶元素:%d\n", e);
            Pop(S, &e);
            printf("\n出栈元素为:%d\n", e);
            if (!StackEmpty(S))
            {
                printf("栈不为空\n");
            }
            else
            {
                printf("栈为空\n");
            }
            printf("\n输出顺序栈结果如下:\n");
            while (!StackEmpty(S))
            {
                Pop(S, &e);
                printf("%d\t", e);
            }
            DestroyStack(S);
            break;
        case 2:
            printf("\n请输入你要转化的进制\n");
            scanf("%d", &k);
            printf("\n请输入你的数据\n");
            scanf("%d", &n);
            InitStack(&S);
            while (n)
            {
                Push(S, n % k);
                n = n / k;
            }
            printf("转化结果如下\n");
            while (!StackEmpty(S))
            {
                Pop(S, &e);
                printf("%d", e);
            }

            DestroyStack(S);
            break;
        case 3:
            printf("输入你要检验匹配表达式\n");
            scanf("%s", str);
            if (Match(str, strlen(str), S))
                printf("表达式匹配\n");
            else
                printf("表达式不匹配\n");
            break;
        }
    }
}
