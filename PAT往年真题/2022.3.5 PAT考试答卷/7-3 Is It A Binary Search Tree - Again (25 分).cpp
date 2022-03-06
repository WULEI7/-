#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n,tree[1005],flag=1;
vector<int> v;
void inorder(int temp)
{
	if(temp>n) return;
	//if(2*temp<=n&&tree[2*temp]!=-1&&tree[2*temp]>tree[temp])
	//	flag=0;
	//if(2*temp+1<=n&&tree[2*temp+1]!=-1&&tree[2*temp+1]<tree[temp])
	//	flag=0;
	inorder(2*temp);
	if(tree[temp]!=-1)
		v.emplace_back(tree[temp]);
	inorder(2*temp+1);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>tree[i];
	inorder(1);
	for(int i=1;i<v.size();i++)
		if(v[i]<v[i-1])
			flag=0;
	if(flag==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	cout<<v[0];
	for(int i=1;i<v.size();i++)
		cout<<" "<<v[i];
	return 0;
}
