/**
���㷨��BF�㷨�нϴ�Ľ�����Ҫ������������ָ��Ļ�
�ݣ��Ӷ�ʹ�㷨Ч������ĳ�̶ֳȵ���ߡ�
next[j]��ָt[j]�ַ�ǰ�ж��ٸ��ַ���t��ͷ���ַ���ͬ��
ģʽ��t��ĳ��k(0<k<j),ʹ�����³���
���磬t= ��a b a b c�� ����t[4]='c'
         0 1 2 3 4
��t0t1�� t2t3 = "ab"  k=2
����next[4]=k=2
**/
void GetNext(SqString t, int next[])
{
    int j, k;
    j = 0;
    k = -1;
    next[0] = -1;
    while (j < t.length - 1)
    {
        if (k == -1 || t.data[j] == t.data[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
            k = next[k];
    }
}
int KMPIndex(SqString s, SqString t)
{
    int next[MaxSize], i = 0, j = 0;
    GetNext(t, next);
    while (i < s.length && j < t.length)
    {
        if (j == -1 || s.data[i] == s.data[j])
        {
            i++;
            j++;
        }
        else
            j = next[j]; //i���䣬j����
    }
    if (j >= t.length)
        return i - t.length;
    else
        return -1;
}