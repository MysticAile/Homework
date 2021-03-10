#include <iostream>
#include <string.h>
#include<cstring>
#define MAX 10000
using namespace std;
typedef struct
{
    char letter, *code;
    int weight;//Ȩֵ
    int parent, lchild, rchild;//�������ڵ㣬�ӽڵ�
} Node, *Huffman;

int n;
char Num[100];

int Min(Huffman &HT, int i)
{
    int j;
    unsigned int k = MAX; //�������Ȩֵ���ᳬ��MAX
    int log;
    for (j = 0; j <= i; ++j)
    {
        if (HT[j].weight < k && HT[j].parent == 0) //�ø�����Ƿ�Ϊ0���жϴ˽���Ƿ��Ѿ���ѡ��
        {
            k = HT[j].weight;
            log = j;
        }
    }
    HT[log].parent = 1; //������ǣ�˵���Ѿ���ѡ����
    return log;
}
void Select(Huffman &HT, int i, int &s1, int &s2)//ѡ����
{
    s1 = Min(HT, i);
    s2 = Min(HT, i);
}

void CreateHuffmanTree(Huffman &HT, char t[], int w[])//������������
{
    int m;
    int i, s1, s2;
    if (n <= 1) //���ֻ��һ���Ͳ��ô���
        return;
    m = 2 * n - 1;          //�ܹ���Ҫ2n��1���ڵ�
    HT = new Node[m + 1]; //���ٿռ�
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
        Select(HT, i - 1, s1, s2); //��n�������ҳ�Ȩֵ��С������

        HT[s1].parent = i;
        HT[s2].parent = i; //�����������ĸ��ڵ�����Ϊi;

        HT[i].lchild = s1;
        HT[i].rchild = s2;                            //���������ֱ������ҽڵ�
        HT[i].weight = HT[s1].weight + HT[s2].weight; //����������˫��Ϊ���������ĺͣ�
    }
}
void CreatHuffmanCode(Huffman HT)//��������������
{
    int j, c, f;
    int i;
    char *cd = new char[n];

    cd[n - 1] = '\0';
    cout << "�ַ�����Ϊ��" << endl;
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


void YiMa(Huffman HT, char cod[], int b) //����
{
    char A[100];
    char Data[50];
    char voidstr[] = " "; //�հ��ַ���
    int t = 0;
    int s = 0;
    int xx = 0;
    for (int i = 0; i < b; i++)
    {
        Data[t++] = cod[i]; //��ȡ�ַ�
        Data[t] = '\0';     //��Ч�ַ���
        for (int j = 0; j < n; j++)
        { //�����������ַ����뿪ʼƥ��

            if (!strcmp(HT[j].code, Data))
            { 

                A[s] = HT[j].letter;
                s++;
                xx += t;
                strcpy(Data, voidstr); 
                t = 0;                 //t�ÿ�
                break;
            }
        }
    }
    if (t == 0)
    {

        A[s] = '\0';
        cout << "����Ϊ:" << endl;

        cout << A << endl;
    }
    else
    {
        cout << "������Դ���д��ӵ�" << xx + 1 << "λ��ʼ" << endl;
    }
}

int main(void)//������
{
    Huffman HT;
    char a[100], B[1024], p; //aΪ����ַ� BΪ������ַ��� pΪ��������ʱ���ַ�
    int b[100];                 //���Ȩֵ��Ϣ
    int i, j;
    int Sum = 1, x, k; //����ʱ���ж��õı���
    cout << "�������ַ�:";
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
    cout << "�ַ���Ȩֵ��Ϣ����" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "�ַ���" << a[i] << "  Ȩֵ��" << b[i] << endl;
    }

    CreateHuffmanTree(HT, a, b);
    CreatHuffmanCode(HT);

    //

    cout << "���룺" << endl;

    while (1)
    {
        cout << "������Ҫ����Ķ������ַ���,����'/'������";
        x = 1;      //�ж��Ƿ��зǷ��ַ�ֻ����0 1
        k = 0; 
        Sum = 1; //�ж��Ƿ��������
        while (Sum)
        {
            cin >> p;
            if (p != '1' && p != '0' && p != '/')
            { //�����������ַ���x��Ϊ0����ʾ����Ĳ��Ƕ�����
                x = 0;
            }
            Num[k] = p;
            if (p == '/')
                Sum = 0; //��/������Ϊ������־

            k++;
        }
        if (x == 1)
        {
            YiMa(HT, Num, k - 1); //��������
        }
        else
        {
            cout << "�зǷ��ַ���" << endl;
        }
        cout << "�Ƿ����?(Y/N):";
        cin >> p;
        if (p == 'y' || p == 'Y')
            continue;
        else
            break;
    }
    system("pause");
    return 0;
}