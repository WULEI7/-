#include <bits/stdc++.h>
#define pr printf
#define sc scanf
#define for0(i, n) for (i = 0; i < n; i++)
#define for1n(i, n) for (i = 1; i <= n; i++)
#define forab(i, a, b) for (i = a; i <= b; i++)
#define forba(i, a, b) for (i = b; i >= a; i--)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define int long long
#define pii pair<int, int> 
#define vi vector<int>
#define vii vector<vector<int>>
#define vt3 vector<tuple<int,int,int>>
#define mem(ara, n) memset(ara, n, sizeof(ara))
#define memb(ara) memset(ara, false, sizeof(ara))
#define all(x) (x).begin(), (x).end()
#define sq(x) ((x) * (x))
#define sz(x) x.size()
const int N = 2e5 + 100;
const int mod = 1e9 + 7;
using namespace std;
vector<int> a;

class Solution
{
public:
    int getNum(vector<int> nums, int target)
    {
        if(nums.empty())
            return 0;
        deque<int> qmin;    //保存窗口内的最小值，递增  front保存最小的元素位置
        deque<int> qmax;    //保存窗口内的最大值，递减  front保存最大的元素位置
        int i = 0, j = 0;   //nums[i..j]表示数组的范围
        int res = 0;        //表示满足条件的子数组数量
        //依次找到以nums[0],nums[1]...nums[N - 1]作为第一元素的子数组中满足条件的数量有多少个，累加
        while(i < nums.size())
        {
            while(j < nums.size())   // j向右拓展，直到不满足条件
            {
                while(!qmin.empty() && nums[qmin.back()] >= nums[j]) // 更新qmin中最小值的index
                    qmin.pop_back();
                qmin.push_back(j);
                while(!qmax.empty() && nums[qmax.back()] <= nums[j]) // 更新qmax中最大值的index
                    qmax.pop_back();
                qmax.push_back(j);
                if(nums[qmax.front()] - nums[qmin.front()] > target) //如果出现不满足条件的，那么包含以nums[i]起始的窗口的所有子数组都不满足条件
                    break;
                j++;
            }
 
            if(qmin.front() == i)  // 如果窗口为 0 ，直接弹出
                qmin.pop_front();
            if(qmax.front() == i)  // 如果窗口为 0 ，直接弹出
                qmax.pop_front();
 
            res += j - i;          //如果nums[i..j]满足条件，则其子数组都满足条件， 一共 (j - i)个子数组
            i++;                   //继续寻找以nums[i]为起始点的子数组
        }
        return res;
    }
 
};
int n, m; 
 
signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    long long ans = n*n+n;
    ans /= 2;
    int x;
    for(int i = 1; i <= n; i++)
    {
        cin >> x ;
        a.emplace_back(x);
    }
    while (m--)
    {
        int k;
        cin >> k;
        Solution ss;
        long long now = ss.getNum(a,k);
        cout << ans - now << endl;
    }
 
    return 0;
}
