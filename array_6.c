/**
 ��Ŀ
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������ǿգ�����һ�������������������֡�
˼���⣺
����Ҫ��ֻ��ʹ�� O(n) ��ʱ��Ͷ��� O(1) �Ŀռ䣬����ô���أ�
����
���룺[1,2,1,1,3]
�����1
**/
//Ͱ����
int moreThanHalfNum_Solution(int *nums, int numsSize)
{
    int book[10000] = {0}, i;
    for (i = 0; i < numsSize; i++)
    {
        book[nums[i]]++;
        if (book[nums[i]] > (numsSize / 2.0))
            return nums[i];
    }
}