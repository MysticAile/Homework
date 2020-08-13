/**
 * 一个长度为L（L≥1）的升序序列S，处在第?L/2?个
位置的数称为S的中位数。
例如：若序列S1=(11,13,15,17,19)，则S1的中位数是15。 两个序列的中位数是含它们所有元素的升序序列的中位数。例如，
若S2=(2,4,6,8,20)，则S1和S2的中位数是11。
现有两个等长的升序序列A和B，试设计一个在时间和空间两方面
都尽可能高效的算法，找出两个序列A和B的中位数。要求：
（1）给出算法的基本设计思想。
（2）根据设计思想，采用C、C++或Java语言描述算法，关键之
处给出注释。
（3）说明你所设计算法的时间复杂度和空间复杂度。
**/
//思路:采用归并的方法只需要标记即可
int M_Search(int A[], int B[], int n)
{
    int i, j, k;
    i = j = k = 0;
    
    while (i < n && j < n)
    {
        k++;
        if (A[i] < B[j])
        {
            if (k == n)
                return A[i];
            i++;
        }
        else //A[i]>=B[j]
        {
            if (k == n)
                return B[j];
            j++;
        }
    }
} //算法的时间复杂度为O(n)，空间复杂度为O(1)。