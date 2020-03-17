#include <cstdio>
#include <iostream>
using namespace std;
int monthday[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int isleap(int x)
{
	if((x%100!=0&&x%4==0)||x%400==0)
		return 1;
	else return 0;
}//判断闰年函数 

class CTime
{
	public:
		CTime(int inityear,int initmonth,int initday,int inithour=0,int initminute=0,int initsecond=0);
		CTime(CTime &p);
		~CTime();
		int dayDiff(CTime t);
		void showTime();
		bool isvalid();
	private:
		int year,month,day,hour,minute,second;
};//定义CTime类 

CTime::CTime(int inityear,int initmonth,int initday,int inithour,int initminute,int initsecond)
{
	int flagdate=0,flagtime=0;
	if(initmonth>12) flagdate=1;
	if(initday>monthday[initmonth])
		flagdate=1;
	if(isleap(inityear)&&initmonth==2&&initday==29)
		flagdate=0;
	if(inithour>23||initminute>59||initsecond>59)
		flagtime=1;
	if(flagdate==0&&flagtime==0)
	{
		year=inityear;
		month=initmonth;
		day=initday;
		hour=inithour;
		minute=initminute;
		second=initsecond;
	}
	else
	{
		year=month=day=hour=minute=second=0;
		if(flagdate==1&&flagtime==0)
			cout<<"date error!"<<endl;
		if(flagdate==0&&flagtime==1)
			cout<<"time error!"<<endl;
		if(flagdate==1&&flagtime==1)
			cout<<"date and time error!"<<endl;
	}
	cout<<"构造函数被调用"<<endl;
}

CTime::CTime(CTime &p)
{
	year=p.year;
	month=p.month;
	day=p.day;
	hour=p.hour;
	minute=p.minute;
	second=p.second;
	cout<<"拷贝构造函数被调用"<<endl;
}

CTime::~CTime()
{
	cout<<"析构函数被调用"<<endl;
}

void CTime::showTime()
{
	cout<<year<<"/"<<month<<"/"<<day<<" "<<hour<<":"<<minute<<":"<<second<<endl;
}

bool CTime::isvalid()
{
	if(year==0&&month==0&&day==0)
		return false;
	else return true;
}//具体的判断在用构造函数初始化对象时已经做过，这里不再重复 

int CTime::dayDiff(CTime t)
{
	int y1=year,m1=month,d1=day,y2=t.year,m2=t.month,d2=t.day;
	int temp;
	if((y1>y2)||(y1==y2&&m1>m2)||(y1==y2&&m1==m2&&d1>d2))
	{
		temp=y1;y1=y2;y2=temp;
		temp=m1;m1=m2;m2=temp;
		temp=d1;d1=d2;d2=temp;
	}//用y1m1d1记录日期1，用y2m2d2记录日期2，使日期2在日期1之后 
	int days=0;//days记录日期1和日期2的日期差 
	while(1)
	{
		if(d1==d2&&m1==m2&&y1==y2)
			break;
		days++;
		d1++;
		if(d1>monthday[m1])
		{
			if(isleap(y1)&&m1==2&&d1==29)
				days++;//如果经过闰年的2月29日，日期差days加1天 
			m1++;
			d1=1;
		}
		if(m1>12)
		{
			y1++;
			m1=1;
		}
	}
	return days;
}

int main()
{
	int year,month,day,hour,minute,second;
	cin>>year>>month>>day>>hour>>minute>>second;
	CTime t1(year,month,day,hour,minute,second);
	t1.showTime();
	CTime t2(2000,1,1); //利用默认形参将时间初始化为00:00:00 
	if(t1.isvalid()) //如果日期和时间合法，则计算天数 
	{
		int days=0;
		days=t1.dayDiff(t2);
		cout<<"这两天之间相隔了"<<days<<"天"<<endl;
		days=t2.dayDiff(t1);
		cout<<"这两天之间相隔了"<<days<<"天"<<endl;
	}
}
