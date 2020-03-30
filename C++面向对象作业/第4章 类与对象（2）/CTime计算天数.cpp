#include <cstdio>
#include <iostream>
using namespace std;
int monthday[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int isleap(int x)
{
	if((x%100!=0&&x%4==0)||x%400==0)
		return 1;
	else return 0;
}//�ж����꺯�� 

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
};//����CTime�� 

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
	cout<<"���캯��������"<<endl;
}

CTime::CTime(CTime &p)
{
	year=p.year;
	month=p.month;
	day=p.day;
	hour=p.hour;
	minute=p.minute;
	second=p.second;
	cout<<"�������캯��������"<<endl;
}

CTime::~CTime()
{
	cout<<"��������������"<<endl;
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
}//������ж����ù��캯����ʼ������ʱ�Ѿ����������ﲻ���ظ� 

int CTime::dayDiff(CTime t)
{
	int y1=year,m1=month,d1=day,y2=t.year,m2=t.month,d2=t.day;
	int temp;
	if((y1>y2)||(y1==y2&&m1>m2)||(y1==y2&&m1==m2&&d1>d2))
	{
		temp=y1;y1=y2;y2=temp;
		temp=m1;m1=m2;m2=temp;
		temp=d1;d1=d2;d2=temp;
	}//��y1m1d1��¼����1����y2m2d2��¼����2��ʹ����2������1֮�� 
	int days=0;//days��¼����1������2�����ڲ� 
	while(1)
	{
		if(d1==d2&&m1==m2&&y1==y2)
			break;
		days++;
		d1++;
		if(d1>monthday[m1])
		{
			if(isleap(y1)&&m1==2&&d1==29)
				days++;//������������2��29�գ����ڲ�days��1�� 
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
	CTime t2(2000,1,1); //����Ĭ���βν�ʱ���ʼ��Ϊ00:00:00 
	if(t1.isvalid()) //������ں�ʱ��Ϸ������������ 
	{
		int days=0;
		days=t1.dayDiff(t2);
		cout<<"������֮�������"<<days<<"��"<<endl;
		days=t2.dayDiff(t1);
		cout<<"������֮�������"<<days<<"��"<<endl;
	}
}
