#include <cstdio>
int main()
{
	printf("10\n");
	printf("501 502 503 504 505 506 507 508 509 510\n");
	return 0;
}
/* 
#include <iostream>
using namespace std;
#define ll long long
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll n, i, x[25], ans = 1, tmp;
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> x[i];
    for (i = 0; i < n; i++)
    {
        tmp = gcd(ans, x[i]);
        ans = ans / tmp * x[i];
    }
    cout << ans;
    return 0;
}
*/
