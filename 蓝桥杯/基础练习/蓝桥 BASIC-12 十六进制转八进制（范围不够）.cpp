#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string s;
		cin>>s;
		int len=s.length();
		long long n=0;
		for(int i=0;i<len;i++)
		{
			long long t;
			if(s[len-1-i]>='0'&&s[len-1-i]<='9')
				t=s[len-1-i]-'0';
			else
				t=s[len-1-i]-'A'+10;
			n+=t*pow(16,i);
		}
		//printf("%d\n",n);//��16����ת10���ƣ���10����ת8���� 
		stack<int> st;
		while(n!=0)
		{
			st.push(n%8);
			n/=8;
		}
		if(st.empty())
			printf("0\n");//ע�⿼������Ϊ0������� 
		while(!st.empty())
		{
			printf("%d",st.top());
			st.pop();
		}
		printf("\n");
	}
	return 0;
}
