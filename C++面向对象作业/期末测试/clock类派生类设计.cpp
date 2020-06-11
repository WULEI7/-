#include <iostream>
using namespace std;
class watch
{
public:
    watch()
    {
        m_hour = 0;
        m_min = 0;
        m_sec = 0;
        cout << "watch default constructor called" << endl;        
    }
    watch(int h, int m, int s)
    {
        m_hour = h;
        m_min = m;
        m_sec = s;
        cout << "watch constructor called" << endl;
    }
    watch(watch &w)
    {
    	m_hour=w.m_hour;
    	m_min=w.m_min;
    	m_sec=w.m_sec;
	}
	~watch(){}
    //注意保护成员在以公有继承方式被继承时，在派生类中依然是保护成员，即可以在派生类内访问，但是不能在类外访问。
protected:
    int m_hour; //小时
    int m_min;  //分钟
    int m_sec;  //秒钟
};

//派生类watchDerived的设计
class watchDerived : public watch
{
    //请补充派生类watchDerived的设计
    public:
	    watchDerived():watch()
	    {
			cout<<"watchDerived default constructor called"<<endl;
		}
		watchDerived(int h,int m,int s):watch(h,m,s)
		{
			cout<<"watchDerived constructor called"<<endl;
		}
		watchDerived(watchDerived &w):watch(w){}
		~watchDerived(){}
		void setzero()
		{
			m_hour=0;
			m_min=0;
			m_sec=0;
		}
		int getHour() const
		{
			return m_hour;
		}
		int getMin() const
		{
			return m_min;
		}
		int getSec() const
		{
			return m_sec;
		}
		watchDerived & operator ++ ()
			{
				m_sec++;
				if(m_sec==60)
				{
					m_min++;
					m_sec=0;
				}
				if(m_min==60)
				{
					m_hour++;
					m_min=0;
				}
				if(m_hour==12)
					m_hour=0;
				return *this;
			}
			watchDerived operator ++ (int)
			{
				watchDerived old=*this;
				++(*this);
				return old;
			}
    friend ostream &operator<<(ostream &, const watchDerived &);
    friend istream &operator>>(istream &,  watchDerived &);
};

//请完善派生类watchDerived中<<运算符的重载函数
ostream &operator<<(ostream &out, const watchDerived &s)
{
	cout<<s.getHour()<<":"<<s.getMin()<<":"<<s.getSec();
	return out;
}
istream &operator>>(istream & in,  watchDerived &s)
{
    in>> s.m_hour >> s.m_min >> s.m_sec;
    return in;
}

int main()
{
    watchDerived s1, s2(11, 59, 59);

    s1 = s2++;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    s1.setzero();
    s2.setzero();

    s1 = ++s2;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    cin>>s1;
    cout << "s1: " << ++s1 << endl;

    return 0;
}
