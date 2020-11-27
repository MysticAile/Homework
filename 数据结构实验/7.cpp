//Ԥ��������
#include<stdio.h>
#include<stdlib.h>
#include<Queue.h>  //���е�ʵ��
#include<Stack.h>  //ջ��ʵ��	
#define MAX_VERTEX_NUM 20
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
//���ݽṹ
typedef int Status;
typedef int InfoType;	//��ؼ�·����ʱ��������Ż���Ȩֵ
typedef int VertexType;
typedef enum {DG,DN,UDG,UDN} GraphKind;
typedef struct ArcNode	//����
{
	int adjvex;			//�ڽ�㣬�û���ָ��Ķ����λ��
	struct ArcNode *nextarc;//ָ����һ������ָ��
	InfoType *info;		//�û������Ϣ��ָ��
}ArcNode;
typedef struct VNode	//������	
{
	VertexType data;	//������Ϣ
	ArcNode *firstarc;	//ָ���һ�������ڸö���Ļ���ָ��
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct{
	AdjList vertices;
	int vexnum,arcnum;//ͼ�ĵ�ǰ�������ͻ���
	int kind;//ͼ�������ʶ
}ALGraph;

//ȫ�ֱ���
bool visited[MAX_VERTEX_NUM];  

//��������
int menu_select(); 
Status CreateAL(ALGraph &G);
int LocateVex(ALGraph G,int v);
void Input(InfoType * &pi);
void DisplayAL(ALGraph G);

int FirstAdjVex( ALGraph G, int v );
int NextAdjVex( ALGraph G, int v, int w );
void DFS(ALGraph G,int v);
void DFSTraverse(ALGraph G);

void BFSTraverse(ALGraph G);
void FindInDegree(ALGraph G,int indegree[]);
Status TopologicalSort(ALGraph G);
void DestroyGraph(ALGraph &G);

//������
int  main()
{
	ALGraph G;
	Status  s;
	for(;;)
	{
		switch(menu_select())
		{
		case 1:s=CreateAL(G);
			if(s)
				printf("��������ͼ�ɹ�\n");
			else
				printf("��������ͼʧ��\n");
			break;
		case 2:DisplayAL(G);
			break;
		case 3:printf("�������������\n");
			DFSTraverse(G);
			break;
		case 4:printf("�������������\n");
			BFSTraverse(G);
			break;
		case 5:printf("�������У�\n");
			s=TopologicalSort(G);
			if(s)
				printf("������ͼ��������\n");
			else
				printf("������ͼ��������\n");
			break;
		case 0:DestroyGraph(G);
			printf("�������\n"); 
			exit(0);
		}		
	}
	return 0;
}
//�˵�����
int menu_select()
{
	int sn;
	printf("\n1.����һ������ͼ\n");
	printf("2.��ʾͼ���ڽӱ�洢\n");
	printf("3.�����������\n");
	printf("4.�����������\n");
	printf("5.��������\n");
	printf("0.�˳�\n");
	printf("Input 0-5:");
	for(; ;)
	{
		scanf("%d",&sn);
		if(sn<0||sn>5)
			printf("\n���������ѡ0����5��");
		else
			break;
	}
	return sn;
}

//����ͼ
Status CreateAL(ALGraph &G)
{
	int i,j,k,IncInfo;
	VertexType v1,v2;
	ArcNode *p;
	G.kind=DN;
	printf("�������������Ķ��������������Ƿ��б�˵���\n");
	scanf("%d%d%d",&G.vexnum,&G.arcnum,&IncInfo);	
	printf("������%d�������ֵ(������)��",G.vexnum);
	for(i=0;i<G.vexnum;i++)//�����ͷ����
	{
		scanf("%d",&G.vertices[i].data);//���붥��ֵ
		G.vertices[i].firstarc=NULL;//�������ͷָ�븳��ֵ
	}
	printf("������%d��������ʼ�㡢�ն˵㼰Ȩ��ֵ��\n",G.arcnum);
	for(k=0;k<G.arcnum;k++)//�����������������
	{
		printf("����a%2d������Ϣ��",k+1);
		scanf("%d%d",&v1,&v2);
		i=LocateVex(G,v1);//ȷ��v1,v2��G�е�λ��
		j=LocateVex(G,v2);
		if(i==-1||j==-1)
			return ERROR;        
		p=(ArcNode *)malloc(sizeof(ArcNode));
		if(!p) 	exit(OVERFLOW);
		p->adjvex=j;
		p->info=(InfoType*)malloc(sizeof(InfoType));
		if(IncInfo)
			Input(p->info);//������
		else
			*p->info=0;//����ͼ
		p->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p;	
	}
	return OK;
}
//ȷ��ֵv��G�е�λ���±�
int LocateVex(ALGraph G,int v)
{
	int i;
	for(i=0;i<G.vexnum;i++)
	{
		if(G.vertices[i].data==v)
			return i;
	}
	return -1;
}
//���뻡�����Ϣ������Ȩ��ֵ��������
void Input(InfoType * &pi)
{
	scanf("%d",pi);
}
//��ʾ�ڽӱ�
void DisplayAL(ALGraph G)
{
	int i;
	ArcNode * p;
	printf("�±� ����  ����\n");
	for(i=0;i<G.vexnum;i++)
	{		
		printf("  %d    V%d  ",i,G.vertices[i].data);
		for(p=G.vertices[i].firstarc;p;p=p->nextarc)
			printf("->%d(w=%d)",p->adjvex,*p->info);
		printf("\n");
	}
}

//��ͼ G ��Ѱ�Ҷ��� v �ĵ�һ���ڽӶ���
//������ v ��ͼ G �����ڽӶ��㣬���ص�һ���ڽӶ�����ͼ G �е�λ��
//���򣬷��� �C1
int FirstAdjVex( ALGraph G, int v )
{
	ArcNode *p;
	p = G.vertices[v].firstarc;
	if( p )
		return p->adjvex;
	else
		return -1;
}
//w �Ƕ��� v ��ĳ���ڽӵ���ͼ G �е�λ��
//Ѱ�Ҷ��� v ����� w ����һ���ڽӶ��㣬�����ڷ��ظö�����ͼ G �е�λ��
//���򣬷��� �C1

int NextAdjVex( ALGraph G, int v, int w )
{
	ArcNode *p;
	p = G.vertices[v].firstarc;
	while( p && p->adjvex != w )  //ָ��p��������ָ����㲻��w
		p = p->nextarc;
	if(!p ||!p->nextarc)      //û�ҵ�W��W�����һ���ڽӵ�
		return -1;
	else
		return p->nextarc->adjvex;//����V����W����һ���ڵ��λ��
}
//�����������ͼ
void DFSTraverse(ALGraph G)
{
	int v;
	for(v=0;v<G.vexnum;++v)
		visited[v]=FALSE;//���ʱ�ʶ��ʼ��
	for(v=0;v<G.vexnum;v++)
		if(!visited[v])
			DFS(G,v);
}
//�ӵ�v����������ݹ��������ȱ���ͼG
void DFS(ALGraph G,int v)
{	
	int w;
	visited[v]=TRUE;
	printf("V%d\t",G.vertices[v].data);//�����ǰ����	
	for(w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w))
		if(!visited[w])
			DFS(G,w);
}

//��������ȷǵݹ����ͼG��ʹ�ø�������Q�ͷ��ʱ�ʶ����visited��
void BFSTraverse(ALGraph G)
{
	int v,u;;
	LinkQueue Q;
	for(v=0;v<G.vexnum;++v)
		visited[v]=FALSE;	
	InitQueue(Q);				//ָ�յĸ�������Q
	for(v=0;v<G.vexnum;++v)
	{
		if(!visited[v])
		{
			visited[v]=TRUE;
			printf("V%d\t",G.vertices[v].data);
			EnQueue(Q,v);		//�����
			while(!QueueEmpty(Q))
			{
				
				DeQueue(Q,u);	//��ͷԪ�س��Ӳ���Ϊu
				int w;
				for(w=FirstAdjVex(G,u);w>=0;w=NextAdjVex(G,u,w))
				{
					if(!visited[w])
					{
						visited[w]=TRUE;
						printf("V%d\t",G.vertices[w].data);
						EnQueue(Q,w);
					}
				}
			}
		}
	}
}
//�������������
void FindInDegree(ALGraph G,int indegree[])
{
	int i;
    ArcNode *p;
	for(i=0;i<G.vexnum;i++)
		indegree[i]=0;
	for(i=0;i<G.vexnum;i++)
	{
		for(p=G.vertices[i].firstarc;p;p=p->nextarc)
			indegree[p->adjvex]++;
	}
}

//�������� 
//����ͼG�����ڽӱ�洢�ṹ��
//��G�޻�·�������G�Ķ����һ���������в�����OK,����ERROR
Status TopologicalSort(ALGraph G)
{	
	int indegree[MAX_VERTEX_NUM];
	SqStack S;
	int i,count;
	FindInDegree(G,indegree);	
	InitStack(S);	
	for(i=0;i<G.vexnum;++i)//������ȶ���ջS
	{
		if((!indegree[i]))
			Push(S,i);
	}
	count=0;		//������������
	printf("�±�\t����\n");
	while(!StackEmpty(S))
	{
		Pop(S,i);
		printf("%d\tV%d\n",i,G.vertices[i].data);
		++count;	//���i�Ŷ��㲢����
		ArcNode *p;
		for(p=G.vertices[i].firstarc;p;p=p->nextarc)
		{
			int k=p->adjvex;//��i�Ŷ����ÿ���ڽӵ����ȼ�1
			if(!(--indegree[k])) Push(S,k);//����ȼ�Ϊ0������ջ
		}
	}
	if(count<G.vexnum) 
		return ERROR;
	else 
		return OK;
}
//����ͼ
void DestroyGraph(ALGraph &G)
{
	int i;
	ArcNode *p,*q;
	for(i=0;i<G.vexnum;i++)
	{
		p=G.vertices[i].firstarc;
		while(p)
		{
			q=p->nextarc;
			free(p);
			p=q;
		}
	}
	G.vexnum=0;
	G.arcnum=0;
}