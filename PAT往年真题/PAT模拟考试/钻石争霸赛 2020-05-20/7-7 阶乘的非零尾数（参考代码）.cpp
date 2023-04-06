#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const long long MAXN = 1e6 + 10;

int main()
{
    // freopen("in.txt", "r", stdin);

    long long N, K;
    cin >> N >> K;
    long long base = 1;
    for (long long i = 0; i < K; i++)
    {
        base *= 10;
    }
    long long cnt2 = 0, cnt5 = 0, num = 1;
    for (long long i = 1; i <= N; i++)
    {
        long long m = i;
        while (m % 5 == 0) { m /= 5; cnt5++; }
        while (m % 2 == 0) { m/=2; cnt2++; }
        num*=m;
        num%=base;
    }
    long long cnt=min(cnt2,cnt5);
    for (long long i=0;i<cnt2-cnt;i++) { num=2ll*num%base; }
    for (long long i=0;i<cnt5-cnt;i++) { num=5ll*num%base; }
    long long tmp=num,bits=0;
    while (tmp) {
        bits++;
        tmp/=10;
    }
    for (long long i=0;i<K-bits;i++) { cout<<"0"; }
    cout<<num<<" "<<cnt<<endl;
    return 0;
}
