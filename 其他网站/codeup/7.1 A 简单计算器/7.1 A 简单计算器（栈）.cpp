#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdio>
#include <string>
#include <stack>
#include <sstream>
using namespace std;
const double eps=1e-8; 
int main()
{
	//freopen("test0.in","r",stdin);
	//freopen("test1.out","w",stdout);
	stringstream ss;
	string str;
	while(getline(cin,str))
	{
		if(str=="0") break;
		ss.clear();
		ss<<str;
		stack<double> s;
		double temp,ans=0;
		int n;
		char t;
		ss>>n;
		//cout<<ss.rdbuf()->in_avail()<<endl;
		s.push(n);
		while(ss>>t)
		{
			ss>>n;
			if(t=='*')
			{
				temp=s.top();
				s.pop();
				s.push(temp*n);
			}
			else if(t=='/')
			{
				temp=s.top();
				s.pop();
				s.push(temp/n);
			}
			else if(t=='+')
				s.push(n);
			else if(t=='-')
				s.push(-n);
		}
		while(s.size()>0)
		{
			//cout<<s.top()<<endl;
			ans+=s.top();
			s.pop();
		}
		printf("%.2f\n",ans>0?ans:ans+eps);//对于负数，加上一个极小数eps，成功解决问题 
		//cout<<fixed<<setprecision(2)<<ans<<endl;
	}
	return 0;
}
