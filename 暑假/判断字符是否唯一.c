/**ʵ��һ���㷨��ȷ��һ���ַ��� s �������ַ��Ƿ�ȫ����ͬ��

ʾ�� 1��

? ����: s = "leetcode"? ���: false

ʾ�� 2��

? ����: s = "abc"? ���: true**/
bool isUnique(char* astr)
{
    bool array[26] = {};
    for(char *ch = astr; *ch != NULL; ch++ )
    {
        int temp = *ch - 'a';
        if(array[temp])
        {
            return false;
        }
        array[temp] = true;
    }
    return true;
}