#include <stdio.h>
#define MAX 20
int n;
int mark[MAX+1];
int stack[MAX];
int top = -1;
int isprime (int x)
{
	int i;
	for (i = 2; i <= x/2; i++)
		if (x % i == 0 )
			return 0;
	return 1;
}
void print()
{	int i;
	for (i=0; i<n; i++)
		printf ("%d ", stack[i]);
	printf("\n");
}
circle()
{
	int i, j;
	int s[MAX];
	int k=-1;
	for (i=1; i<=n; i++)
		if ( !mark[i] && isprime(stack[top] + i) )
			s[++k] = i;
	for (i=0; i<=k; i++)
	{
		mark[s[i]] = 1;
		/* push stack*/
		stack[++top] = s[i];
		/* stack full */
		if (top == n-1) {
			if (isprime(stack[0] + stack[n-1]))
				print();
		}
		else 
			circle ();
		mark[s[i]] = 0; 
		/* pop stack*/
		top--;
	}
}
int main ()
{
	scanf ("%d", &n);
	mark[1] = 1;
	stack[++top] = 1;
	circle ();
	return 0;
}
