/**
��Ŀ:����һ������Ϊ n ���������� nums�����������е����ֶ��� 0?n?1 �ķ�Χ�ڡ�
������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ�
���ҳ�����������һ���ظ������֡�
ע�⣺���ĳЩ���ֲ��� 0?n?1 �ķ�Χ�ڣ��������в������ظ����֣��򷵻� -1��
����
���� nums = [2, 3, 5, 4, 3, 2, 6, 7]��
���� 2 �� 3�� **/
//˼·:���ⰴ�����⼴��
int duplicateInArray(int *nums, int numsSize)
{
    int i, j;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] < 0 || nums[i] > numsSize)
            return -1;
    }
    for (i = 0; i < numsSize; i++)
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[i] == nums[j])
                return nums[i];
        }
    return -1;
}