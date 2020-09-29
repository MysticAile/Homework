#include <stdio.h>
void f(int n, char A, char B, char C)
{
	if(n == 1)   printf("Move sheet %d from %c to %c\n", n, A, C);
	else
	{
	    f(n-1, A, C, B);
	    printf("Move sheet %d from %c to %c\n", n, A, C);
	    f(n-1, B, A, C);
	}
}
int main() 
{
	int n;
	scanf("%d", &n);
	f(n, 'A', 'B', 'C');
	return 0;
}