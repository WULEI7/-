#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N << 2], tr[N << 3], cnt[N];
set<int> s;
map<int, int> m;

void bulid(int i, int l, int r)
{
    if (l == r)
    {
        tr[i] = 0x3f3f3f3f;
        return;
    }
    int mid = l + r >> 1;
    bulid(i << 1, l, mid);
    bulid(i << 1 | 1, mid + 1, r);
    tr[i] = min(tr[i << 1], tr[i << 1 | 1]);
}

void update(int i, int l, int r, int x, int y)
{
    if (l > x || x > r)
        return;
    if (l == r && l == x)
    {
        tr[i] = y;
        return;
    }
    int mid = l + r >> 1;
    update(i << 1, l, mid, x, y);
    update(i << 1 | 1, mid + 1, r, x, y);
    tr[i] = min(tr[i << 1], tr[i << 1 | 1]);
}

int query(int i, int l, int r, int x, int y)
{
    if (y < l || x > r)
        return 0x3f3f3f3f;
    if (l >= x && r <= y)
        return tr[i];
    int mid = l + r >> 1;
    return min(query(i << 1, l, mid, x, y), query(i << 1 | 1, mid + 1, r, x, y));
}

int f(int l, int r, int x, int k)
{
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    if (query(1, 1, 2 * k, l, mid) < x)
        f(l, mid, x, k);
    else
        f(mid + 1, r, x, k);
}

int main()
{
    int k, n;
    cin >> k >> n;
    bulid(1, 1, 2 * k);
    s.insert(0);
    m[0] = k;
    for (int i = 0; i < n; ++i)
    {
        int l, time;
        cin >> l >> time;
        if (*s.begin() >= l)
            continue;
        if (a[i % k] < l)
        {
            cnt[i % k]++;
            m[a[i % k]]--;
            if (m[a[i % k]] == 0)
                s.erase(a[i % k]);
            a[i % k] = l + time - 1;
            if (s.find(a[i % k]) == s.end())
                s.insert(a[i % k]);
            m[a[i % k]]++;
            update(1, 1, 2 * k, (i % k) + 1, l + time - 1);
            update(1, 1, 2 * k, (i % k) + k + 1, l + time - 1);
        }
        else
        {
            int id = f(i % k + 1, i % k + k, l, k);
            id--;
            id %= k;
            cnt[id]++;
            m[a[id]]--;
            if (m[a[id]] == 0)
                s.erase(a[id]);
            a[id] = l + time - 1;
            if (s.find(a[id]) == s.end())
                s.insert(a[id]);
            m[a[id]]++;
            update(1, 1, 2 * k, id + 1, l + time - 1);
            update(1, 1, 2 * k, id + k + 1, l + time - 1);
        }
    }
    int minx = 0, ans = 0;
    for (int i = 0; i < k; i++)
        minx = max(minx, cnt[i]);
    for (int i = 0; i < k; i++)
    {

        if (cnt[i] == minx)
        {
            if (ans)
                printf(" ");
            printf("%d", i);
            ans++;
        }
    }
    return 0;
}
