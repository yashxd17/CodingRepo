#include <stdio.h>

int find(int d)
{
	if (d==0)
		return 0;
	else
		return (d%2 + 10*find(d/2));
}

int main()
{
	int n = 10;
	printf("%d", find(n));
	return 0;
}
