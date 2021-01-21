#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
    double num; //学号
    char sex[2];  //性别
    char name[20];  //名字
    int math,english,computer;  //数学  外语  电脑   成绩
    double ave;  //平均分
    int sum;   //总分
    struct student *next;
};
typedef struct student Student;    //将数组名命名为 Student
void showmainmenu(void);   //主菜单   
Student *input(void);   //创链表
void add(Student *head);  //加结点
void search_name(Student *head);  //查找姓名
void search_num(Student *head);   //查找学号
void modify(Student *head);   //输入学号修改学生成绩

int main(void)
{
    int choice;
    Student *head;
    while(1)
    {
        showmainmenu();
        printf("输入您的选项：");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0:  //退出
            printf("\n退出\n");
            exit(0);

            case 1:  //输入学生信息
            head=input();
            break;

            case 2:  //增加一个学生
            if(head==NULL)    //判断是否已经创建链表
            {
                printf("还没有学生信息呢，请先输入一个学生信息！");
            }
            else
            add(head);
            break;

            case 3:  //按姓名查找
            search_name(head);
            break;

            case 4:  //按学号查找
            search_num(head);
            break;

            case 5:  //输入学号修改成绩
            modify(head);
            break;
        }
        getchar();//吸收脏数据
    }
    return 0;
}

//展示主菜单
void showmainmenu(void)
{
    printf("\n┏━━━━━━━━━━━━━菜单━━━━━━━━━━━━━━┓");
	printf("\n┃ 1、输入学生信息（创建链表） \t┃");
	printf("\n┃ 2、增加一个学生信息\t\t┃");
	printf("\n┃ 3、按姓名查找\t\t\t┃");
	printf("\n┃ 4、按学号查找\t\t\t┃");
    printf("\n┃ 5、输入学号修改成绩\t\t┃");
    printf("\n┃ 6、删除一个学生信息\t\t┃");
    printf("\n┃ 7、将链表保存到文件中\t\t┃");
	printf("\n┃ 0、退出  \t\t\t┃");
	printf("\n┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	printf("\n━━请输入你的选择：");
}

//输入学生信息   创建链表
Student *input()
{
    Student *head,*p1,*p2;
    int num;
    char sex[2];  //性别
    char name[20];  //名字
    int math,english,computer;  //数学  外语  电脑   成绩
    double ave;  //平均分
    int sum;
    head=NULL;
    p1=(Student *)malloc(sizeof(Student));  //分配空间
    printf("输入学号：");   
    scanf("%d",&num);
    if(num==0)
        return head;    //如果学号为0，则结束
    else
        {
            p1->num=num;
            printf("输入姓名：");
            scanf("%s",name);
            strcpy(p1->name,name);
            fflush(stdin);  //清空缓存区
            printf("输入性别：");
            scanf("%s",sex);
            strcpy(p1->sex,sex);
            fflush(stdin);  //清空缓存区
            printf("输入数学成绩：");
            scanf("%d",&math);
            p1->math=math;
            fflush(stdin);  //清空缓存区
            printf("jiuzhe");
            printf("输入英语成绩：");
            scanf("%d",&english);
            p1->english=english;
            fflush(stdin);  //清空缓存区
            printf("输入电脑成绩：");
            scanf("%d",&computer);
            p1->computer=computer;
            sum=p1->math+p1->english+p1->computer;
            p1->sum=sum;
            ave=p1->sum/3.0;
            p1->ave=ave;
            p1->next=NULL;
            head=p1;
        }
        return head;
}

//增加一个学生信息,,增加到尾结点
void add(Student *head)
{
    Student *pnew,*tail,*n;
    double num;   //学号
    char sex[2];  //性别
    char name[20];  //名字
    int math,english,computer;  //数学  外语  电脑   成绩
    double ave;  //平均分
    int sum;
    printf("输入新增同学的学号：");
    scanf("%lf",&num);
    if(num==0)  //判断是否为零
    {
        printf("竟然是这个数字，看来您是不打算增加一个学生惹。");
        return;  //返回空值
    }
    else if(num==head->num)   //查重
    {
        printf("这个学号已经有了欸！");
        return;   //返回空值
    }
    else
    {
        pnew=(Student *)malloc(sizeof(Student));   //分配内存空间
        pnew->num=num;
        printf("输入姓名：");
        scanf("%s",&name);
        strcpy(pnew->name,name);
        printf("输入性别：");
        scanf("%s",&sex);
        strcpy(pnew->sex,sex);
        printf("输入数学成绩：");
        scanf("%d",&math);
        pnew->math=math;
        printf("输入英语成绩：");
        scanf("%d",&english);
        pnew->english=english;
        printf("输入电脑成绩：");
        scanf("%d",&computer);
        pnew->computer=computer;
        sum=pnew->math+pnew->english+pnew->computer;
        pnew->sum=sum;
        ave=pnew->sum/3.0;
        pnew->ave=ave;
        pnew->next=NULL;
        tail=head;
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
        tail->next=pnew;
    }
    return;
}

//按名字查找
void search_name(Student *head)
{
    char name[20];
    int x=0;
    Student *p=head,*str=NULL;
    printf("输入您要查找的学生的名字：");
    scanf("%s",name);
    for(;p!=NULL;p=p->next)
    {
        if(p->name==name)
        {
            str=p;
            p=str->next;
            break;
        }
    }
    if(str=NULL)
    {
        printf("没有找到这个名字的学生！");
        return;
    }
    else
    {
        printf("\t姓名     学号\t     性别\t    数学\t     英语\t     电脑\t     总分\t     平均分\n");
        printf("%s\t",str->name);
        printf("%lf\t",str->num);
        printf("%s\t",str->sex);
        printf("%d\t",str->math);
        printf("%d\t",str->english);
        printf("%d\t",str->computer);
        printf("%d\t",str->sum);
        printf("%.1lf\t",str->ave);
    }
}

//按学号查找
void search_num(Student *head)
{
    double num;
    Student *p=head,*str=NULL;
    printf("输入您要查找的学生的学号：");
    scanf("%lf",&num);
    for(;p!=NULL;p=p->next)
    {
        if(p->num==num)
        {
            str=p;
            p=str->next;
            break;
        }
    }
    if(str=NULL)
    {
        printf("没有找到这个学号的学生！");
        return;
    }
    else
    {
        printf("\t姓名     学号\t     性别\t    数学\t     英语\t     电脑\t     总分\t     平均分\t");
        printf("%s\t",str->name);
        printf("%lf\t",str->num);
        printf("%s\t",str->sex);
        printf("%d\t",str->math);
        printf("%d\t",str->english);
        printf("%d\t",str->computer);
        printf("%d\t",str->sum);
        printf("%.1lf\t",str->ave);
    }
}

//输入学号修改学生成绩
void modify(Student *head)
{
    double num;
    int course,score;
    Student *p=head,*str=NULL;
    printf("输入您要修改的学生成绩的学号：");
    scanf("%lf",&num);
    for(;p!=NULL;p=p->next)
    {
        if(p->num==num)
        {
            str=p;
            p=str->next;
            break;
        }
    }
    if(str=NULL)
    {
        printf("没有找到这个学号的学生！");
        return;
    }
    else
    {
        printf("选择要修改的学科：（1.高数，2.英语，3.电脑）");
        scanf("%d",&course);
        printf("输入新的成绩：");
        scanf("%d",&score);
           switch(course)
           {
               case 1:str->math=score;break;
               case 2:str->english=score;break;
               case 3:str->computer=score;break;
           }
    }
}