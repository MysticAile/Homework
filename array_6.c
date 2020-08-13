/**
 题目
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
假设数组非空，并且一定存在满足条件的数字。
思考题：
假设要求只能使用 O(n) 的时间和额外 O(1) 的空间，该怎么做呢？
样例
输入：[1,2,1,1,3]
输出：1
**/
//桶排序
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