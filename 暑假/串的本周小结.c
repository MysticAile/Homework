/**
���Ĵ洢�ṹ
1.����һ����������Ա�, �����Ա��һ���Ӽ�
˳�� ����
2.����ֻ�ܲ��õ������� 
��һ������Ҫ������Ҫ�����������
�����Ҫ��ĳ���ڵ����ǰ����ң����Բ���˫���� 
�����Ҫ���ٲ���β�ڵ㣬���Բ���ѭ��˫����
2.�����㷨���
BF�㷨
KMP�㷨
eg:
���贮����˳��ṹ�洢��
���һ���㷨��s�г��ֵĵ�һ����ظ��Ӵ����±�ͳ��ȡ�
**/
void MaxSubstr(SqString s, SqString *t)
{
    int maxi = 0, maxlen = 0, len, i, j, k;
    i = 0;
    while (i < s.length) //���±�i���ַ���ʼ
    {
        j = i + 1; //��i����һ��λ�ÿ�ʼ�ҿ�ʼ�ظ��Ӵ�
        while (j < s.length)
        {
            if (s.data[i] == s.data[j]) //��һ���Ӵ�������ʼ�±�Ϊi������Ϊlen
            {
                len = 1;
                for (k = 1; s.data[i + k] == s.data[j + k]; k++)
                    len++;
                if (len > maxlen) //���ϴ󳤶��߸���maxi��maxlen
                {
                    maxi = i;
                    maxlen = len;
                }
                j += len;
            }
            else
                j++;
        }
        i++; //����ɨ���i�ַ�֮����ַ�
    }
    t.length = maxlen; //����ظ����Ӵ�����t
    for (i = 0; i < maxlen; i++)
        t.data[i] = s.data[maxi + i];
}