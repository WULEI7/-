#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
vector<string> temp;
map<string,string> var;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m,n;
	string s,ss;
	cin>>m>>n;
	getline(cin,s);
	while(m--)
	{
		getline(cin,s);
		temp.push_back(s);
	}
	while(n--)
	{
		cin>>s;
		getline(cin,ss);
		string t=ss.substr(2,ss.length()-3);//ǰ������ʾ�Ӵ���ʼλ�ã��������ʾ�Ӵ����� 
		var[s]=t;
	}
	int size=temp.size();
	//ע�ⲻ�ܶ�����κ����ݣ��ύʱע�͵����е��Թ������ 
	for(int i=0;i<size;i++)
	{
		string t=temp[i];
		int len=t.length(),beg=0,end=0;
		while(1)
		{
			beg=t.find("{{ ",beg);
			if(beg==-1) break;
			end=beg+3;
			end=t.find(" }}",end);
			string key=t.substr(beg+3,end-beg-3);
			t.replace(beg,end-beg+3,var.count(key)?var[key]:"");//Ҫע��ϸ�� 
			beg+=var.count(key)?var[key].length():0;//�����滻���ݣ�������������ֵ���д����Ż�������ѭ�� 
		}
		cout<<t<<endl;
	}
	return 0;
}
