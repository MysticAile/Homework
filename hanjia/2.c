#include <stdio.h>
#include <stdlib.h>
struct Space
{
	int car;	   //�������
	int into_time; // ͣ��ʱ��
	char empty;	   // �ж��ܷ�ͣ�� ��Y�����ԣ���N�����С�
} space[10];
typedef struct NODE
{
	char state; //״̬ ��A D E�� A��������ͣ������D��������ͣ������E��������ֹͣ
	int car;	//���
	int time;	//ʱ��
	struct NODE *next;
} NODE;
NODE *creat_NODE()
{ //��������洢�������Ϣ
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
			NODE *last = head; // ���last���ǿ������head�Ѿ��������ݡ�
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
	int n; //����ͣ������λ����
	scanf("%d", &n);
	int i; //��ʼ��space����n����λ��ʼΪ����ͣ��
	for (i = 0; i < n; i++)
	{
		space[i].empty = 'Y';
	}
	NODE *head = creat_NODE();
	int num = 0;	  //��¼ͣ�복������
	int rret = 0;	  //�����ж��Ƿ���Ҫ�ȴ�
	int out_time = 0; //��a��Ҫͣ��ʱû��λ��b��������ͣ��� a����ʱ��ĳ�b��������ʱ��
	NODE *p = head;
	while (p)
	{
		if (p->state == 'A')
		{ //Ѱ���Ƿ��пճ�λ
			for (i = 0; i < n; i++)
			{
				if (space[i].empty == 'Y')
				{
					if (out_time)
					{
						p->time = out_time;
						out_time = 0; //ʹ�����Ļ�0
					}
					// ����λ��Ϣ�ĳɸó�����Ϣ
					space[i].car = p->car;
					space[i].into_time = p->time;
					space[i].empty = 'N'; //��λ��Ϊ����ͣ��״̬
					p->state = '0';		  // �ı����Ϣ״̬�����ٴ���
					printf("��#%d ��ͣ���� #%dλ��\n", space[i].car, i + 1);
					num++; // ����ͣ�룬num��һ
					break;
				}
			} // i����n˵��û�пճ�λ
			if (i == n)
			{
				printf("��#%d �ڵȴ�\n", p->car);
				rret++; //��¼�г��ڵȴ�
			}
		}
		else if (p->state == 'D')//������Ҫ��ȥʱ
		{
			int ret = 1; //�����ж���ͣ��λ����û�иó���1Ϊû��
			for (i = 0; i < n; i++)
			{
				if (space[i].car == p->car)
				{
					printf("��#%d ��,��ͣ������ʱ��Ϊ %dСʱ��Ӧ��%dԪ\n", space[i].car, p->time - space[i].into_time,p->time - space[i].into_time); //���num����n�ͱ���ͣ����ͣ���� ��rret ���� 1�����г��ڵȴ���⣬��Ҫ��¼�˳���ȥʱ�䡣
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
				printf("δ�ҵ���\n");
			}
		}
		p = p->next;
	}
	system("pause");

	return 0;
}
