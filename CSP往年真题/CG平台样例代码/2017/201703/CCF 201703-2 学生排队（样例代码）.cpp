#include <iostream>  
#include <vector>  
  
using namespace std;  
  
vector<int> v;  
  
int find(int x)  
{  
    int ret = - 1;  
    for(int i = 0; i < (int)v.size(); i++)  
        if(v[i] == x)  
            return i;  
    return ret;  
}  
  
int main()  
{  
    int n, m, p, q;  
  
    // 输入数据  
    cin >> n >> m;  
  
    // 初始化  
    for(int i=1; i<=n; i++)  
        v.push_back(i);  
  
  
    // 模拟移动过程  
    for(int i=1; i<=m; i++) {  
        cin >> p >> q;  
  
        int pos = find(p);  
        v.insert(v.begin() + pos + (q > 0 ? q + 1 : q), p);  
        v.erase(v.begin() + pos + (q < 0 ? 1 : 0));  
    }  
  
    // 输出结果  
    cout << v[0];  
    for(int i = 1; i < (int)v.size(); i++)  
        cout << " " << v[i];  
    cout << endl;  
  
    return 0;  
}  

