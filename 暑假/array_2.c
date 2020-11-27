/**��Ŀ:
����һ������Ϊ n+1 ������nums�����������е������� 1?n �ķ�Χ�ڣ����� n��1��
���ҳ�����������һ���ظ��������������޸���������顣
����
���� nums = [2, 3, 5, 4, 3, 2, 6, 7]��
���� 2 �� 3��
˼���⣺���ֻ��ʹ�� O(1) �Ķ���ռ䣬����ô���أ�**/
//˼·Ͱ����
int duplicateInArray(int *nums, int numsSize)
{
    int i, book[numsSize + 1];
     for (i = 1; i <= numsSize; i++)
    {
        book[i]=0;
    }
    for (i = 0; i < numsSize; i++)
    {
        book[nums[i]]++;
    }
    for (i = 1; i <=numsSize; i++)
    {
        if (book[i] > 1)
            return i;
    }
    return -1;
}