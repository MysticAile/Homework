/**
�ַ�����ȫ����
����һ�黥����ͬ���ַ����������ַ���ȫ����
������ַ�����ȫ���У����е��Ⱥ�˳��Ӱ����
���룺ABC
�����ABC ACB BAC BCA CAB CBA
˼·:������Ϊ���ַ����ȳ� ��1ʱ��ֻ����ַ�����ѡһ���ַ���Ϊ�����
�������ַ�����������ַ����еݹ鴦��ȫ���У�����
**/
void Permutations(string str, int i, int n)
{
    if (i == n - 1)
    {
        cout << str << endl;
        return;
    }
    //�ݹ鴦���ȴ���1���ַ���
    for (int j = i; j < n; j++)
    {                         //������ǰ��һ���ַ�������λ���ַ�
        swap(str[i], str[j]); //STL����
        //�ݹ鴦���Ӵ�str[i+1,n-1]
        Permutations(str, i + 1, n);
        swap(str[i], str[j]);
    }
}