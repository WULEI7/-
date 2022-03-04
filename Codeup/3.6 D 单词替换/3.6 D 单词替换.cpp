#include <iostream>
#include <cstdio>
#include <string> 
using namespace std;
int main()
{
	//freopen("test0.in","r",stdin);
	//freopen("test1.out","w",stdout);
	//上面是重定向，用来测试从文件输入输出的 
	//有时候考试或者竞赛当中很有用，具体可以网上了解 
	string s,a,b;
	while(getline(cin,s))
	{
		getline(cin,a);
		getline(cin,b);
		//因为字符串中可能有空格，因此要用getline输出 
		int pos=s.find(a,0);
		while(pos<=s.length())
		{
			s.replace(pos,a.length(),b);
			//pos=s.find(a,pos+1);
			//上面这行，如果第二个参数写pos+1，会死循环！
			//样例当中有一组输入是
			/*
			man
			man
			woman
			*/ 
			//想想为什么会死循环 
			pos=s.find(a,pos+b.length());
			//这样就避免了这个问题 
			//函数的参数具体怎么写，比如要删除的长度之类，只能自己多敲代码实践观察 
		}
		cout<<s<<endl;
	}
	return 0;
}
