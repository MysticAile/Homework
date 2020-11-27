//预编译命令
#include<stdio.h>
#include<stdlib.h>
#include<Queue.h>  //队列的实现
#include<Stack.h>  //栈的实现	
#define MAX_VERTEX_NUM 20
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
//数据结构
typedef int Status;
typedef int InfoType;	//求关键路径的时候用来存放弧的权值
typedef int VertexType;
typedef enum {DG,DN,UDG,UDN} GraphKind;
typedef struct ArcNode	//表结点
{
	int adjvex;			//邻结点，该弧所指向的顶点的位置
	struct ArcNode *nextarc;//指向下一条弧的指针
	InfoType *info;		//该弧相关信息的指针
}ArcNode;
typedef struct VNode	//顶点结点	
{
	VertexType data;	//顶点信息
	ArcNode *firstarc;	//指向第一条依附于该顶点的弧的指针
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct{
	AdjList vertices;
	int vexnum,arcnum;//图的当前顶点数和弧数
	int kind;//图的种类标识
}ALGraph;

//全局变量
bool visited[MAX_VERTEX_NUM];  

//函数声明
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

//主函数
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
				printf("创建有向图成功\n");
			else
				printf("创建有向图失败\n");
			break;
		case 2:DisplayAL(G);
			break;
		case 3:printf("深度优先搜索：\n");
			DFSTraverse(G);
			break;
		case 4:printf("广度优先搜索：\n");
			BFSTraverse(G);
			break;
		case 5:printf("拓扑序列：\n");
			s=TopologicalSort(G);
			if(s)
				printf("该有向图拓扑有序\n");
			else
				printf("该有向图无拓扑序\n");
			break;
		case 0:DestroyGraph(G);
			printf("程序结束\n"); 
			exit(0);
		}		
	}
	return 0;
}
//菜单函数
int menu_select()
{
	int sn;
	printf("\n1.创建一个有向图\n");
	printf("2.显示图的邻接表存储\n");
	printf("3.深度优先搜索\n");
	printf("4.广度优先搜索\n");
	printf("5.拓扑排序\n");
	printf("0.退出\n");
	printf("Input 0-5:");
	for(; ;)
	{
		scanf("%d",&sn);
		if(sn<0||sn>5)
			printf("\n输入错误，重选0——5：");
		else
			break;
	}
	return sn;
}

//创建图
Status CreateAL(ALGraph &G)
{
	int i,j,k,IncInfo;
	VertexType v1,v2;
	ArcNode *p;
	G.kind=DN;
	printf("请输入无向网的顶点数，边数与是否含有边说明项：\n");
	scanf("%d%d%d",&G.vexnum,&G.arcnum,&IncInfo);	
	printf("请输入%d个顶点的值(整型数)：",G.vexnum);
	for(i=0;i<G.vexnum;i++)//构造表头向量
	{
		scanf("%d",&G.vertices[i].data);//输入顶点值
		G.vertices[i].firstarc=NULL;//将表结点的头指针赋空值
	}
	printf("请输入%d条弧的起始点、终端点及权重值：\n",G.arcnum);
	for(k=0;k<G.arcnum;k++)//输入各弧并构造链表
	{
		printf("输入a%2d弧的信息：",k+1);
		scanf("%d%d",&v1,&v2);
		i=LocateVex(G,v1);//确定v1,v2在G中的位置
		j=LocateVex(G,v2);
		if(i==-1||j==-1)
			return ERROR;        
		p=(ArcNode *)malloc(sizeof(ArcNode));
		if(!p) 	exit(OVERFLOW);
		p->adjvex=j;
		p->info=(InfoType*)malloc(sizeof(InfoType));
		if(IncInfo)
			Input(p->info);//有向网
		else
			*p->info=0;//有向图
		p->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p;	
	}
	return OK;
}
//确定值v在G中的位置下标
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
//输入弧相关信息，输入权重值，整型数
void Input(InfoType * &pi)
{
	scanf("%d",pi);
}
//显示邻接表
void DisplayAL(ALGraph G)
{
	int i;
	ArcNode * p;
	printf("下标 顶点  表结点\n");
	for(i=0;i<G.vexnum;i++)
	{		
		printf("  %d    V%d  ",i,G.vertices[i].data);
		for(p=G.vertices[i].firstarc;p;p=p->nextarc)
			printf("->%d(w=%d)",p->adjvex,*p->info);
		printf("\n");
	}
}

//在图 G 中寻找顶点 v 的第一个邻接顶点
//若顶点 v 在图 G 中有邻接顶点，返回第一个邻接顶点在图 G 中的位置
//否则，返回 –1
int FirstAdjVex( ALGraph G, int v )
{
	ArcNode *p;
	p = G.vertices[v].firstarc;
	if( p )
		return p->adjvex;
	else
		return -1;
}
//w 是顶点 v 的某个邻接点在图 G 中的位置
//寻找顶点 v 相对于 w 的下一个邻接顶点，若存在返回该顶点在图 G 中的位置
//否则，返回 –1

int NextAdjVex( ALGraph G, int v, int w )
{
	ArcNode *p;
	p = G.vertices[v].firstarc;
	while( p && p->adjvex != w )  //指针p不空且所指针表结点不是w
		p = p->nextarc;
	if(!p ||!p->nextarc)      //没找到W或W是最后一个邻接点
		return -1;
	else
		return p->nextarc->adjvex;//返回V的在W地下一个节点的位置
}
//深度优先搜索图
void DFSTraverse(ALGraph G)
{
	int v;
	for(v=0;v<G.vexnum;++v)
		visited[v]=FALSE;//访问标识初始化
	for(v=0;v<G.vexnum;v++)
		if(!visited[v])
			DFS(G,v);
}
//从第v个顶点出发递归地深度优先遍历图G
void DFS(ALGraph G,int v)
{	
	int w;
	visited[v]=TRUE;
	printf("V%d\t",G.vertices[v].data);//输出当前顶点	
	for(w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w))
		if(!visited[w])
			DFS(G,w);
}

//按广度优先非递归遍历图G，使用辅助队列Q和访问标识数组visited。
void BFSTraverse(ALGraph G)
{
	int v,u;;
	LinkQueue Q;
	for(v=0;v<G.vexnum;++v)
		visited[v]=FALSE;	
	InitQueue(Q);				//指空的辅助队列Q
	for(v=0;v<G.vexnum;++v)
	{
		if(!visited[v])
		{
			visited[v]=TRUE;
			printf("V%d\t",G.vertices[v].data);
			EnQueue(Q,v);		//入队列
			while(!QueueEmpty(Q))
			{
				
				DeQueue(Q,u);	//对头元素出队并置为u
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
//求各个顶点的入度
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

//拓扑排序 
//有向图G采用邻接表存储结构。
//若G无回路，则输出G的顶点的一个拓扑序列并返回OK,否则ERROR
Status TopologicalSort(ALGraph G)
{	
	int indegree[MAX_VERTEX_NUM];
	SqStack S;
	int i,count;
	FindInDegree(G,indegree);	
	InitStack(S);	
	for(i=0;i<G.vexnum;++i)//建零入度顶点栈S
	{
		if((!indegree[i]))
			Push(S,i);
	}
	count=0;		//对输出顶点计数
	printf("下标\t顶点\n");
	while(!StackEmpty(S))
	{
		Pop(S,i);
		printf("%d\tV%d\n",i,G.vertices[i].data);
		++count;	//输出i号顶点并计数
		ArcNode *p;
		for(p=G.vertices[i].firstarc;p;p=p->nextarc)
		{
			int k=p->adjvex;//对i号顶点的每个邻接点的入度减1
			if(!(--indegree[k])) Push(S,k);//若入度减为0，则入栈
		}
	}
	if(count<G.vexnum) 
		return ERROR;
	else 
		return OK;
}
//销毁图
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