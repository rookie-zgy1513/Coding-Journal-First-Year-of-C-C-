#include<stdio.h>
int Isprime(long long n)
{
	for (long long i = 2; i < n / 2; i++)
		if (n % i == 0) return 1;
	return 0;
}
void fun(long long n)
{
	long long i = 0, j;
	long long m = n;
	for (j = 2;j < m/2; j++)
			while(n % j == 0)
			{
				printf("%d", j);
				if (n / j > 2) printf("*");
				n /= j;
			}
}
int main()
{
	long long n;
	long long c;
	scanf("%d", &n);
	c = Isprime(n);
	if (c)  fun(n);
	else printf("it is a prime\n");
}
