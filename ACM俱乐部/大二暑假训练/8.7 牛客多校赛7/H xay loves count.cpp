#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 1000010;

int a[maxn];
vector<int> yueshu[maxn];
unordered_map<int, int> mp;

int prime[50000];
bool isPrime[maxn];

void e_seive(int x) {
	for (int i = 1; i < x; i += 2)
		isPrime[i] = 1, isPrime[i - 1] = 0;
	prime[prime[0] = 1] = 2;
	for (int i = 3; ; i += 2) if (isPrime[i]) {
		int j = i * i, k = i + i;
		if (j >= x) break;
		while (j < x) {
			isPrime[j] = 0;  j += k;
		}
	}
	for (int i = 3; i < x; i += 2)
		if (isPrime[i]) prime[++prime[0]] = i;
}

int p[34380], cnt[34380];

void getPrimeDivisor(int x) {
	p[0] = cnt[0] = 0; int t;
	for (int i = 1; prime[i] * prime[i] <= x && i <= prime[0]; ++i) {
		t = 0;
		while (x % prime[i] == 0) {
			++t; x /= prime[i];
		}
		if (t) p[++p[0]] = prime[i], cnt[++cnt[0]] = t;
	}
	if (x > 1) p[++p[0]] = x, cnt[++cnt[0]] = 1;
};

int divisor[15000];

void getDiv(int x) {
    if(yueshu[x].size())return;
	getPrimeDivisor(x); // 对x进行素因子分解
	divisor[0] = 1; // 存取因子个数
	divisor[1] = 1;
	for (int i = 1; i <= p[0]; ++i) {
		int nowNum = divisor[0];
		int base = 1;
		for (int j = 1; j <= cnt[i]; ++j)
		{
			base *= p[i];
			for (int k = 1; k <= divisor[0]; ++k)
				divisor[++nowNum] = divisor[k] * base;
		}
		divisor[0] = nowNum;
	}
	for (int i = 1; i <= divisor[0]; ++i) {
		yueshu[x].push_back(divisor[i]);
	}
}

void init(int n) {
	for (int i = 1; i <= n; ++i) {
		getDiv(i);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	e_seive(1000005);
	//init(1000000);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
        getDiv(a[i]);
		mp[a[i]]++;
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < yueshu[a[i]].size(); ++j) {
			int num1 = yueshu[a[i]][j];
			int num2 = a[i] / yueshu[a[i]][j];
			int cnt1 = mp[num1];
			int cnt2 = mp[num2];
			ans += (long long)cnt1 * cnt2;
			//cout << num1 << " " << num2 << " " << a[i] << endl;
		}
	}
	cout << ans << endl;
	return 0;
}
