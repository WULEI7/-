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
        deque<int> qmin;    //���洰���ڵ���Сֵ������  front������С��Ԫ��λ��
        deque<int> qmax;    //���洰���ڵ����ֵ���ݼ�  front��������Ԫ��λ��
        int i = 0, j = 0;   //nums[i..j]��ʾ����ķ�Χ
        int res = 0;        //��ʾ��������������������
        //�����ҵ���nums[0],nums[1]...nums[N - 1]��Ϊ��һԪ�ص������������������������ж��ٸ����ۼ�
        while(i < nums.size())
        {
            while(j < nums.size())   // j������չ��ֱ������������
            {
                while(!qmin.empty() && nums[qmin.back()] >= nums[j]) // ����qmin����Сֵ��index
                    qmin.pop_back();
                qmin.push_back(j);
                while(!qmax.empty() && nums[qmax.back()] <= nums[j]) // ����qmax�����ֵ��index
                    qmax.pop_back();
                qmax.push_back(j);
                if(nums[qmax.front()] - nums[qmin.front()] > target) //������ֲ����������ģ���ô������nums[i]��ʼ�Ĵ��ڵ����������鶼����������
                    break;
                j++;
            }
 
            if(qmin.front() == i)  // �������Ϊ 0 ��ֱ�ӵ���
                qmin.pop_front();
            if(qmax.front() == i)  // �������Ϊ 0 ��ֱ�ӵ���
                qmax.pop_front();
 
            res += j - i;          //���nums[i..j]�������������������鶼���������� һ�� (j - i)��������
            i++;                   //����Ѱ����nums[i]Ϊ��ʼ���������
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
