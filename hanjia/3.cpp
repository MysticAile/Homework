#include <iostream>
#include <string.h>
#include<cstring>
#define MAX 10000
using namespace std;
typedef struct
{
    char letter, *code;
    int weight;//权值
    int parent, lchild, rchild;//创建父节点，子节点
} Node, *Huffman;

int n;
char Num[100];

int Min(Huffman &HT, int i)
{
    int j;
    unsigned int k = MAX; //设各结点的权值不会超过MAX
    int log;
    for (j = 0; j <= i; ++j)
    {
        if (HT[j].weight < k && HT[j].parent == 0) //用父结点是否为0来判断此结点是否已经被选过
        {
            k = HT[j].weight;
            log = j;
        }
    }
    HT[log].parent = 1; //作个标记，说明已经被选择了
    return log;
}
void Select(Huffman &HT, int i, int &s1, int &s2)//选择函数
{
    s1 = Min(HT, i);
    s2 = Min(HT, i);
}

void CreateHuffmanTree(Huffman &HT, char t[], int w[])//创建哈夫曼树
{
    int m;
    int i, s1, s2;
    if (n <= 1) //如果只有一个就不用创建
        return;
    m = 2 * n - 1;          //总共需要2n－1个节点
    HT = new Node[m + 1]; //开辟空间
    for (i = 0; i < n; i++)
    {
        HT[i].code = '\0';
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        HT[i].letter = t[i];
        HT[i].weight = w[i];
    }
    for (i = n; i <= m; i++)
    {
        HT[i].code = '\0';
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        HT[i].letter = ' ';
        HT[i].weight = 0;
    }
    cout << "++++++++++++++" << endl;
    for (i = n; i < m; i++)
    {
        Select(HT, i - 1, s1, s2); //在n个数中找出权值最小的两个

        HT[s1].parent = i;
        HT[s2].parent = i; //将他们两个的父节点设置为i;

        HT[i].lchild = s1;
        HT[i].rchild = s2;                            //把这两个分别当作左右节点
        HT[i].weight = HT[s1].weight + HT[s2].weight; //他们两个的双亲为他们两个的和；
    }
}
void CreatHuffmanCode(Huffman HT)//创建哈夫曼编码
{
    int j, c, f;
    int i;
    char *cd = new char[n];

    cd[n - 1] = '\0';
    cout << "字符编码为：" << endl;
    for (i = 0; i < n; i++)
    {

        j = n - 1;
        c = i;
        f = HT[i].parent;

        while (f != 0)
        {
            --j;
            if (HT[f].lchild == c)
            {

                cd[j] = '0';
            }
            else
            {

                cd[j] = '1';
            }
            c = f;
            f = HT[f].parent;
        }

        HT[i].code = new char[n - j];
        strcpy(HT[i].code, &cd[j]);
        cout << HT[i].letter << ":" << HT[i].code << endl;
    }

    delete cd;
}


void YiMa(Huffman HT, char cod[], int b) //译码
{
    char A[100];
    char Data[50];
    char voidstr[] = " "; //空白字符串
    int t = 0;
    int s = 0;
    int xx = 0;
    for (int i = 0; i < b; i++)
    {
        Data[t++] = cod[i]; //读取字符
        Data[t] = '\0';     //有效字符串
        for (int j = 0; j < n; j++)
        { //依次与所有字符编码开始匹配

            if (!strcmp(HT[j].code, Data))
            { 

                A[s] = HT[j].letter;
                s++;
                xx += t;
                strcpy(Data, voidstr); 
                t = 0;                 //t置空
                break;
            }
        }
    }
    if (t == 0)
    {

        A[s] = '\0';
        cout << "译码为:" << endl;

        cout << A << endl;
    }
    else
    {
        cout << "二进制源码有错！从第" << xx + 1 << "位开始" << endl;
    }
}

int main(void)//主函数
{
    Huffman HT;
    char a[100], B[1024], p; //a为存放字符 B为输入的字符串 p为输入译码时的字符
    int b[100];                 //存放权值信息
    int i, j;
    int Sum = 1, x, k; //译码时做判断用的变量
    cout << "请输入字符:";
    cin.getline(B, 1024);

    int len = strlen(B);
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[j] == B[i])
            {
                b[j] = b[j] + 1;
                break;
            }
        }
        if (j >= n)
        {
            a[n] = B[i];
            b[n] = 1;
            n++;
        }
    }
    cout << "字符和权值信息如下" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "字符：" << a[i] << "  权值：" << b[i] << endl;
    }

    CreateHuffmanTree(HT, a, b);
    CreatHuffmanCode(HT);

    //

    cout << "译码：" << endl;

    while (1)
    {
        cout << "请输入要译码的二进制字符串,输入'/'结束：";
        x = 1;      //判断是否有非法字符只能是0 1
        k = 0; 
        Sum = 1; //判断是否输入结束
        while (Sum)
        {
            cin >> p;
            if (p != '1' && p != '0' && p != '/')
            { //若存在其它字符，x设为0，表示输入的不是二进制
                x = 0;
            }
            Num[k] = p;
            if (p == '/')
                Sum = 0; //“/”号作为结束标志

            k++;
        }
        if (x == 1)
        {
            YiMa(HT, Num, k - 1); //进行译码
        }
        else
        {
            cout << "有非法字符！" << endl;
        }
        cout << "是否继续?(Y/N):";
        cin >> p;
        if (p == 'y' || p == 'Y')
            continue;
        else
            break;
    }
    system("pause");
    return 0;
}