//����n��������ƺͶ��ۣ�����Ҫ���д���򣬲��Ҳ�������ж�����ߺ���͵�������ƺͶ��ۡ�
#include <stdio.h>
struct book{
	char name[31];
	double price;
};
int main()
{
	int n,i;
	int max = 0;
	int min = 0;
	scanf("%d",&n);
	struct book books[n];
	char c = getchar(); 
	for(i = 0; i < n ; i++)
	{
		gets(books[i].name);
		scanf("%lf",&books[i].price);
		c = getchar();
		if(books[i].price >books[max].price)
			max = i;
		if(books[i].price < books[min].price)
			min = i;
	}
	printf("%.2f, %s\n",books[max].price,books[max].name);
	printf("%.2f, %s\n",books[min].price,books[min].name);
	return 0;
}