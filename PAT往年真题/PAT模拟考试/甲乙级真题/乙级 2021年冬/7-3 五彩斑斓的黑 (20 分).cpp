#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	string s;
	set<string> st;//�����ж��ظ��ļ��� 
	vector<string> ans;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		if(!st.count(s))
		{
			st.insert(s);
			ans.push_back(s);
		}
	}
	int size=ans.size();
	cout<<size<<endl;
	cout<<ans[0];
	for(int i=1;i<size;i++)
		cout<<" "<<ans[i];//ע���ϸ��ո�ʽ��� 
	return 0;
}
