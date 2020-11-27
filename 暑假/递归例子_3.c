/**
����һ��������N����������N�ʺ������ȫ���ڷ���
���������ÿһ�ж�����һ�ְڷ�������ĵ�i��������
����n���ʹ����i�еĻʺ�Ӧ�÷��ڵ�n�С�
�ʺ���С��б�Ŷ��Ǵ�1��ʼ�㡣
**/
#include <iostream>
#include <cmath>
using namespace std;
int N;
int queenPos[100];
void NQueen(int k);
int main()
{
    cin >> N;
    NQueen(0); //�ӵ�0�п�ʼ�ڻʺ�
    return 0;
}
void NQueen(int k) //��0~k-1�лʺ�ںõ�����£���k�м����Ժ��
{
    int i;
    if (k == N)
    { //N���ʺ��Ѿ��ں�
        for (i = 0; i < N; i++)
            cout << queenPos[i] + 1 << "";
        cout << endl;
        return;
    }
    for (i = 0; i < N; i++) //���Ե�K���ʺ������
    {
        int j;
        for (j = 0; j < k; j++)
        {
            //���Ѿ��ںõ�k���ʺ�λ�ý��бȽϿ��Ƿ��ͻ
            if (queenPos[j] == i || abs(queenPos[j] - i) == abs(k - j)) //�ж��Ƿ�ͬ�л���б
                break;
        }
        if (j == k)
        {
            //��ѡ��λ��i����ͻ
            queenPos[k] = i; //����k���ʺ�ڷ���λ��i
            NQueen(k + 1);
        }
    }
}