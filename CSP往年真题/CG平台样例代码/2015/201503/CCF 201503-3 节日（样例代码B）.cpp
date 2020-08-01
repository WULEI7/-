#include <iostream>
#include <fstream> 
#include <cstring>

using namespace std;

//返回指定日期是星期几的函数
int weekday(int y,int m,int d)
{
	int tm=m>=3?(m-2):(m+10);
	int ty=m>=3?y:(y-1);
	return (ty+ty/4-ty/100+ty/400+(int)(2.6*tm-0.2)+d)%7;
} 

//判断是否是闰年的函数 
bool judgeyear(int y)
{
	return (y%400==0)||(y%100!=0&&y%4==0);
}

int year[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int mapping[8]={0};  //存储已经过几个星期几的数组 

int main()
{
	//freopen("input/festival.txt","r",stdin);
	int a,b,c,y1,y2;
	cin>>a>>b>>c>>y1>>y2;
	for(int i=y1;i<=y2;i++)
	{
		memset(mapping,0,sizeof(mapping));
		int bd=weekday(i,a,1);  //1号是星期几 
		bool flag=false;
		if(bd==0) bd=7;  //将星期天转为数字7 
		if(judgeyear(i))
			year[2]=29;
		else year[2]=28;
		for(int j=1;j<=year[a];j++)
		{
			mapping[bd]++;
			int cnt=mapping[bd];
			if(cnt==b&&bd==c){ //匹配则输出 
				flag=true;
				cout<<i<<"/";
				if(a>9)
					cout<<a<<"/";
				else cout<<"0"<<a<<"/";
				if(j>9)
					cout<<j<<endl;
				else cout<<"0"<<j<<endl;
				break;
			}
			else {
				bd++;
				if(bd>7){
					bd=1;
				}
			}
		}
		if(!flag)
			cout<<"none"<<endl;		
	}
	return 0;
} 


