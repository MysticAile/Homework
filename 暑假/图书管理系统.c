现需要用c语言开发一款客户管理系统, 系统必须用链表实现。
管理对象为客户，其节点定义如下，请在空行位置补充你认为必要的两个属性：
struct MyNode
{       int    ID;               //编号(不重复)
        char Name[40];   //名称
        int    age;            //年龄
        _________________;  //补充属性1
        _________________;  //补充属性2
        struct MyNode *   next;
}; 
要求实现的功能包括以下几条，请补充你认为必要的6，7两个功能。每条功能必须用函数实现，函数名称如下，函数参数及返回类型可自行定义；
1，        从特定文件读入信息：      ReadFromFile();
2，        将信息写入特定文件:        WriteToFile();
3，        显示链表所有信息：         Display();
4，        添加录入节点信息:           InputRecord();
5，        删除特定节点信息:         DeleteRecord();
 
6，        ______________________：    ___________;
7,           ______________________:      ___________; 

请完成主程序及各功能模块，所有代码放在一个源文件中并提交该文件内容。（注：补充部分雷同者判定为作弊）
*/
#include <stdio.h>
#include <stdlib.h>
#define FILENAME "d:\\Nodes.dat"
struct MyNode
{   
    int ID;
    char Name[40];
    int age;
    int phonenum;
    char Company[40];
    struct MyNode *next;
};
typedef struct MyNode NODE;
void showMenu(void);
NODE *Create(void);
void WriteToFile(NODE *head);
NODE *ReadFromFile(void);
void Display(NODE *head);
void InputRecord(NODE *head);
NODE *Find2(NODE *head, int num);
NODE *DeleteRecord(NODE *head);
int Check(NODE *head, int num);
void Find(NODE *head);
void Update(NODE *head);
void Free(NODE *head);
int main(void)
{
    int choice, x = 1;
    NODE *head;
    while (x != 0)
    {
        showMenu();
        scanf("%d", &choice);
        system("cls");
        switch (choice)
        {
        case 0:
            x = 0;
            Free(head);
            break;
        case 1:
            head = Create();
            if (head == NULL)
                break;
            WriteToFile(head);
            printf("Success!\n");
            break;
        case 2:
            head = ReadFromFile();
            if (head == NULL)
            {
                printf("No find! Please Enter ID!\n");
            }
            else
            {
                InputRecord(head);
            }
            WriteToFile(head);
            printf("Success!\n");
            break;
        case 3:
            head = ReadFromFile();
            if (head == NULL)
            {
                printf("No find! Please Enter ID!\n");
            }
            else
            {
                head = DeleteRecord(head);
                WriteToFile(head);
                printf("Success!\n");
            }
            break;
        case 4:
            head = ReadFromFile();
            if (head == NULL)
            {
                printf("No find! Please Enter ID!\n");
            }
            else
            {
                Display(head);
            }
            break;
        case 5:
            head = ReadFromFile();
            if (head == NULL)
            {
                printf("No find! Please Enter ID!\n");
            }
            else
            {
                Find(head);
            }
            break;
        case 6:
            head = ReadFromFile();
            if (head == NULL)
            {
                printf("No find! Please Enter ID!\n");
            }
            else
            {
                Update(head);
                WriteToFile(head);
            }
            break;
        default:

            break;
        }
    }
    fflush(stdin);
    getchar();
    return 0;
}
void showMenu(void)
{
    printf("                        ------------------\n");
    printf("                          *NODE system*\n");
    printf("                        ------------------\n\n");
    printf("            **********************************************\n\n");
    printf("            ******************************************\n\n");
    printf("               * 1-Read                    2-Add   *\n\n");
    printf("               * 3-Delete                  4-Show   *\n\n");
    printf("               * 5-Find                    6-Update   *\n\n");
    printf("               * 0-Exit                                 *\n\n");
    printf("               **********************************************\n\n");
    printf("               **********************************************\n\n");
    printf("please Enter Choice:");
}
NODE *Create(void)
{
    NODE *head, *tail, *pnew;
    head = NULL;
    int num;
    while (1)
    {
        do
        {
            printf("Please Enter ID:");
            scanf("%d", &num);
            if (num == -1)
            {
                return head;
            }
        } while (Check(head, num) == 1);
        pnew = (NODE *)malloc(sizeof(NODE));
        pnew->ID = num;
        printf("Please Enter Name:");
        scanf("%s", pnew->Name);
        printf("Please Enter age");
        scanf("%d", &pnew->age);
        printf("Please Enter phonenum:");
        scanf("%d", &pnew->phonenum);
        printf("Please Enter Company:");
        scanf("%s", pnew->Company);
        pnew->next = NULL;
        if (head == NULL)
            head = pnew;
        else
            tail->next = pnew;
        tail = pnew;
    }
    return head;
}
int Check(NODE *head, int num)
{
    NODE *p = head;
    while (p != NULL)
    {
        if (p->ID == num)
        {
            printf("Num Error!\n");
            return 1;
        }
        p = p->next;
    }
    if (p == NULL)
        return 0;
}
void WriteToFile(NODE *head)
{
    FILE *fp;
    NODE *p;
    fp = fopen(FILENAME, "wb");
    if (fp == NULL)
    {
        printf("WriteToFile fopen fail\n");
        return;
    }
    p = head;
    while (p != NULL)
    {
        fwrite(p, sizeof(NODE), 1, fp);
        p = p->next;
    }
    fclose(fp);
    return;
}
NODE *ReadFromFile(void)
{
    NODE *head = NULL, *tail, *p;
    FILE *fp;
    fp = fopen(FILENAME, "rb");
    if (fp == NULL)
    {
        printf("ReadFromFile fopen fail\n");
        return NULL;
    }
    while (!feof(fp))
    {
        p = (NODE *)malloc(sizeof(NODE));
        if (fread(p, sizeof(NODE), 1, fp) > 0)
        {
            p->next = NULL;
            if (head == NULL)
            {
                head = p;
            }
            else
            {
                tail->next = p;
            }
            tail = p;
        }
        else
        {
            free(p);
        }
    }
    fclose(fp);
    return head;
}
void Display(NODE *head) //打印链表
{
    NODE *p;
    p = head;
    if (head == NULL)
    {
        printf("head is NULL ,Can not show\n");
        return;
    }
    printf("                                    NODE \n");
    printf("            ==========================================================\n");
    printf("             ID        Name     age    phonenum    Company\n");
    while (p != NULL)
    {
        printf("\t%10d%10s%10d%10d%10s\n", p->ID, p->Name, p->age, p->phonenum, p->Company);
        p = p->next;
    }
    printf("            ==========================================================\n");
    return;
}
void InputRecord(NODE *head)
{
    int num;
    NODE *pnew, *tail;
    do
    {
        printf("Please new ID:");
        scanf("%d", &num);
        if (num == -1)
        {
            printf("ID is -1,Error\n");
            return;
        }
    } while (Check(head, num) == 1);
    pnew = (NODE *)malloc(sizeof(NODE));
    pnew->ID = num;
    printf("Please Enter new Name:");
    scanf("%s", pnew->Name);
    printf("Please Enter new age");
    scanf("%d", &pnew->age);
    printf("Please Enter new phonenum:");
    scanf("%d", &pnew->phonenum);
    printf("Please Enter new Company:");
    scanf("%s", pnew->Company);
    pnew->next = NULL;
    tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = pnew;
    return;
}

NODE *DeleteRecord(NODE *head)
{
    NODE *p, *a;
    int num;
    printf("Please Enter Delete ID:");
    scanf("%d", &num);
    p = Find2(head, num);
    if (p == NULL)
    {
        printf("No Find!\n");
    }
    if (p == head)
    {
        head = p->next;
        free(p);
        return head;
    }
    a = head;
    while (a->next != p)
    {
        a = a->next;
    }
    a->next = p->next;
    free(p);
    return head;
}
NODE *Find2(NODE *head, int num)
{
    NODE *p = head;
    while (p != NULL)
    {
        if (p->ID == num)
            return p;
        p = p->next;
    }
    return NULL;
}
void Find(NODE *head)
{
    int num;
    NODE *p;
    printf("Please Enter Find Num:");
    scanf("%d", &num);
    p = Find2(head, num);
    if (p == NULL)
    {
        printf("No Find!\n");
        return;
    }
    printf("                                    NODE \n");
    printf("            ==========================================================\n");
    printf("             ID        Name     age    phonenum    Company\n");
    printf("\t%10d%10s%10d%10d%10s\n", p->ID, p->Name, p->age, p->phonenum, p->Company);
    p = p->next;
    printf("            ==========================================================\n");
    return;
}
void Update(NODE *head)
{
    NODE *p;
    int num, new_num;
    printf("Please Update ID:");
    scanf("%d", &num);
    p = Find2(head, num);
    if (p == NULL)
    {
        printf("No Find,can not Update!\n");
        return;
    }
    do
    {
        printf("Please new_ID:");
        scanf("%d", &new_num);
        if (new_num == -1)
        {
            printf("ID is -1,Error!\n");
            return;
        }
    } while (Check(head, new_num) == 1);
    p->ID = new_num;
    printf("Please Enter new Name:");
    scanf("%s", p->Name);
    printf("Please Enter new age");
    scanf("%d", &p->age);
    printf("Please Enter new phonenum:");
    scanf("%d", &p->phonenum);
    printf("Please Enter new Company:");
    scanf("%s", p->Company);
}
void Free(NODE *head)
{
    NODE *p;
    p = head;
    while (p != NULL)
    {
        head = p->next;
        free(p);
        p = head;
    }
    return;
}