#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	long long n,g,b,hq,ans;
	cin>>t;
	while(t--)
	{
		cin>>n>>g>>b;
		hq=(n-1)/2+1;//hqΪ��Ҫ���������������� 
		if(hq%g==0)
			ans=(g+b)*(hq/g)-b;
		else
			ans=(g+b)*(hq/g)+hq%g;
		cout<<max(ans,n)<<endl;//��������������ɣ��ܹ���������û����Ҳ��Ҫ����ܹ������� 
	}
	return 0;
}
