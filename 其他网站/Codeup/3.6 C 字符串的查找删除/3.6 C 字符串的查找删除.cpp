#include <iostream>
#include <cstdio>
#include <string> 
using namespace std;
int main()
{
	string a,b,c;
	getline(cin,a);//输入要删除的字符串a 
	for(int i=0;i<a.length();i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
			a[i]+=32;//ASCII码 
	}//统一大小写，因为题目要求删除的时候不区分大小写 
	while(getline(cin,b))//输入每一行b 
	{
		c=b;//需要保存原字符串b，因为最终输出的字符串大小写要按照原来的来（仔细看题目要求） 
		for(int i=0;i<b.length();i++)
		{
			if(b[i]>='A'&&b[i]<='Z')
				b[i]+=32;
		}//将b统一为小写，方便和a进行匹配 
		int pos=b.find(a,0);
		//cout<<pos<<endl;//输出的是-1，但其实pos的值不是-1，pos和length返回的都是unsigned int（无符号整数）类型 
		while(pos<=b.length())//int和unsigned int比较的时候会默认转换，所以这里是可以这样比较的（多敲代码实践观察输出） 
		{
			//b.replace(pos,a.length(),"");
			b.erase(pos,a.length());
			//上面两行功能是相同的 
			c.erase(pos,a.length());
			//同步处理b和c 
			pos=b.find(a,pos);//继续往后查找，函数的第二个参数值按照题目需要来，有时候需要修改数值避免重复替换死循环，具体问题具体分析 
		}
		//删除字符串中所有的空格（方法不唯一，也可以用上面的find和erase或者replace的方法） 
		for(unsigned int i=0;i<c.length();i++)
		{
			if(c[i]==' ')
			{
				c.erase(i,1);
				i--;//注意i要减1，因为删除了空格这个字符 
			}
		}
		cout<<c<<endl;//输出变换后的一行 
	}
	return 0;
}
