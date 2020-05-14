#include <iostream>
#include <vector>
using namespace std;

int gcd(int x,int y)
{
	if(y==0) return x;
	else return gcd(y,x%y);
}//最大公约数函数 

template <typename T>
class Array
{
	public:
		Array(int n)
		{
			len=n;
		}
		void input(int n)
		{
			for(int i=0;i<n&&i<len;i++)
			{
				T temp;
				cin>>temp;
				num.push_back(temp);
			}
		}
		T &operator[](int n)
		{
			return num[n];
		}
	private:
		int len;
		vector<T> num;
};

class Fract
{
	public:
		Fract(int n=0,int m=1)
		{
			int sign;
			if(n*m>=0) sign=1;
			else sign=-1;
			if(n>=0) fz=n;
			else fz=-n;
			if(m>=0) fm=m;
			else fm=-m;
			if(fz!=0)
			{
				int x=fz,y=fm;
				fz/=gcd(x,y);
				fm/=gcd(x,y);//约分 
			}
			fz*=sign;
		}
		void show()
		{
			if(fz==0)
				cout<<0<<endl;
			else if(fm==1)
				cout<<fz<<endl;
			else
				cout<<fz<<"/"<<fm<<endl;
		}
		Fract &operator+=(Fract &f)
		{
			Fract temp(fz*f.fm+f.fz*fm,fm*f.fm);
			*this=temp;
			return *this;
		}
		friend istream &operator>>(istream &is,Fract &f)
		{
			int n,m;
			is>>n>>m;
			Fract temp(n,m);
			f.fz=temp.fz;
			f.fm=temp.fm;
			return is;
		}
	private:
		int fz,fm;//分子带符号，分母不带符号 
};

int main()
{
    unsigned int n;
    cin >> n;
    Array<double> db(n);
    db.input(n);
    double dbsum(0.0);
    for (unsigned int i = 0; i < n; i++)
        dbsum += db[i];
    cout << dbsum << endl;

    cin >> n;
    Array<Fract> fr(n);
    fr.input(n);
    Fract frsum(0, 1);
    for (unsigned int i = 0; i < n; i++)
        frsum += fr[i];
    frsum.show();
}
