#include<stdio.h>//折半插入排序  ,从小到大
#define LEN 100
int main(void)
{
    int i,j,low,high,mid,n;
    int a[LEN];
    printf("Enter n:");//输入数据
    scanf("%d",&n);
    printf("输入n个数:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=2;i<=n;i++)
    {//记录的是待插入的元素的下标，也就是说i-1之前的元素都是有序的
        a[0] = a[i];//保存待插入的值
        low = 1;
        high = i-1;
        while(low <= high)//折半查找
        {
            mid = (low +high)/2;
            if(a[mid]>a[0])
                high = mid -1;
            else 
                low = mid + 1;                
        }//找到了待插入的位置，接下来从后往前依次后移元素腾出位置
        for(j=i-1;j>=high +1;--j)
            a[j+1] = a[j];
            a[high+1] = a[0];//因为此时high指向的是待插入位置的前一位
    }
    for(i=1;i<=n;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}