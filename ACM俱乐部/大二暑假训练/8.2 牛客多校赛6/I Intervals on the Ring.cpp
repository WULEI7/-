#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct node {
	int l, r;
	node() {}
	node(int l, int r) :l(l), r(r) {}
}a[1010];

vector<node> b;
vector<node> ans;

bool cmp(node& a, node& b) {
	if (a.l != b.l) {
		return a.l < b.l;
	}
	return a.r < b.r;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, t;
	cin >> t;
	while (t--) {
		b.clear();
		ans.clear();
		cin >> n >> m;
		int curl, curr;
		for (int i = 0; i < m; ++i) {
			cin >> a[i].l >> a[i].r;
			if (a[i].l <= a[i].r) {
				b.push_back(a[i]);
			}
			else {
				b.push_back(node(a[i].l, n));
				b.push_back(node(1, a[i].r));
			}
		}
		sort(b.begin(), b.end(), cmp);

		bool flag = true;

		curl = b[0].l, curr = b[0].r;

		for (int i = 1; i < b.size(); ++i) {
			if (b[i].l <= curr + 1) {
				curr = max(curr, b[i].r);
			}
			else {
				ans.push_back(node(curl, curr));
				curl = b[i].l;
				curr = b[i].r;
			}
		}
		ans.push_back(node(curl, curr));
		int x = ans.size();
		cout << x << "\n";
		for (int i = 0; i < x; ++i) {
			cout << ans[i].l << " " << ans[(i + x - 1) % x].r << "\n";
		}
	}
	return 0;
}
