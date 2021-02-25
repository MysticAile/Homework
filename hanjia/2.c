#include <stdio.h>
#include <stdlib.h>
struct Space
{
	int car;	   //汽车编号
	int into_time; // 停入时间
	char empty;	   // 判断能否停车 “Y”可以，“N”不行。
} space[10];
typedef struct NODE
{
	char state; //状态 “A D E” A代表车辆进停车场，D代表车辆出停车场，E代表输入停止
	int car;	//编号
	int time;	//时间
	struct NODE *next;
} NODE;
NODE *creat_NODE()
{ //创建链表存储输入的信息
	NODE *head = NULL;
	char state;
	int car;
	int time;
	do
	{
		fflush(stdin);
		scanf("%c", &state);
		scanf("%d%d", &car, &time);
		if (state != 'E')
		{
			NODE *p = (NODE *)malloc(sizeof(NODE));
			p->state = state;
			p->car = car;
			p->time = time;
			p->next = NULL;
			NODE *last = head; // 如果last不是空则表明head已经存入数据。
			if (last != NULL)
			{
				while (last->next)
				{
					last = last->next;
				}
				last->next = p;
			}
			else
			{
				head = p;
			}
		}
	} while (state != 'E');
	return head;
}
int main(void)
{
	int n; //定义停车场车位个数
	scanf("%d", &n);
	int i; //初始化space，将n个车位初始为可以停车
	for (i = 0; i < n; i++)
	{
		space[i].empty = 'Y';
	}
	NODE *head = creat_NODE();
	int num = 0;	  //记录停入车辆个数
	int rret = 0;	  //用于判断是否需要等待
	int out_time = 0; //在a车要停入时没车位，b车出来后停入的 a车的时间改成b车出来的时间
	NODE *p = head;
	while (p)
	{
		if (p->state == 'A')
		{ //寻找是否有空车位
			for (i = 0; i < n; i++)
			{
				if (space[i].empty == 'Y')
				{
					if (out_time)
					{
						p->time = out_time;
						out_time = 0; //使用完后改回0
					}
					// 将车位信息改成该车的信息
					space[i].car = p->car;
					space[i].into_time = p->time;
					space[i].empty = 'N'; //车位改为不能停车状态
					p->state = '0';		  // 改变此信息状态，不再处理。
					printf("车#%d 在停车场 #%d位置\n", space[i].car, i + 1);
					num++; // 车辆停入，num加一
					break;
				}
			} // i等于n说明没有空车位
			if (i == n)
			{
				printf("车#%d 在等待\n", p->car);
				rret++; //记录有车在等待
			}
		}
		else if (p->state == 'D')//当车辆要出去时
		{
			int ret = 1; //用于判断有停车位里有没有该车，1为没有
			for (i = 0; i < n; i++)
			{
				if (space[i].car == p->car)
				{
					printf("车#%d 出,在停车场的时间为 %d小时，应付%d元\n", space[i].car, p->time - space[i].into_time,p->time - space[i].into_time); //如果num等于n就表面停车场停满了 ，rret 等于 1，则有车在等待入库，需要记录此车出去时间。
					if (rret)
					{
						out_time = p->time;
						p->state = '0';
						rret--;
						p = head;
					}
					num--;
					for (i; i < n - 1; i++)
					{
						space[i].car = space[i + 1].car;
						space[i].empty = space[i + 1].empty;
						space[i].into_time = space[i + 1].into_time;
					}
					space[i].empty = 'Y';
					p->state = '0';
					ret = 0;
					break;
				}
			}
			if (ret)
			{
				printf("未找到车\n");
			}
		}
		p = p->next;
	}
	system("pause");

	return 0;
}
