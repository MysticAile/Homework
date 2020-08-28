/**
������������?[1, ? , ?]��һ������?����ͬ�Ǹ����������顣�����? < ?������£� ��? ? > ?[?]��
��? ? ��?[?]���ͳ�ΪA�е�һ������ԡ����磬���飨3��1��4�� 5��2���ġ�����ԡ���<3,1>��<3,2>��<4,2>��<5,2>��4����
���룺ÿ�����������������У���һ�����������ĸ���n��? �� 10000���ڶ�������
?��������������֮���ÿո���������һ������-1����ʾ���������
�����ÿ��������ݵĽ�����ռһ�У����������������Եĸ�����
�������룺
53 1 4 5 2 -1
���������
4
**/
/*
1�� ���?1 ? > ?2 ? �����У�
?1 ? + 1 > ?2 ? ��
����
?1 (? + ?)/2 > ?2 ? ��
һ�αȽϿ����Ƶ�����������
2�����?1 ? �� ?2 ? �����У�
?1 ? �� ?2 ? + 1 ��
����
?1 ? �� ?2 ? ��
97 13 40 76 A2
һ�αȽϿ���ʡ�Զ�αȽ�
38 > 13 {49, 65, 97} > 13 ����4�������
38 < 40 38 < {76} 38��������A2��Ԫ�ز��������
49 > 40 {65, 97} > 40 ����3�������
49 < 76 49��������A2��Ԫ�ز��������
65 < 76 65��������A2��Ԫ�ز��������
97 > 76 ����1�������
*/
long MergeReverse(int Datas[], int Buffer[], int Low, int Mid, int High)
{
    int i = Low, j = Mid + 1, k = Mid;
    long c;
    while (i <= Mid && j <= High)
    {
        if (Datas[i] <= Datas[j])
            Buffer[k++] = Datas[i++];
        else
        {
            c += Mid - i + 1;
            Buffer[k++] = Datas[j++];
        }
    }
    if (i <= Mid)
        for (int ii = i; i <= Mid; ii++)
            Buffer[k++] = Datas[ii];
    else
        for (int jj = j; jj <= High; jj++)
            Buffer[k++] = Datas[jj];
    return c;
}

long ReveseOrder(int Datas[], int Buffer[], int Low, int High)
{
    if (Low = High)
        return 0;
    int Mid = (Low + High) / 2;
    long c1, c2, c3;
    c1 = ReveseOrder(Datas, Buffer, Low, Mid);
    c2 = ReveseOrder(Datas, Buffer, Mid + 1, High);
    c3 = MergeReverse(Datas, Buffer, Low, Mid, High);
    for (int i = Low; i <= High; i++)
        Datas[i] = Buffer[i];
    return c1 + c2 + c3;
}