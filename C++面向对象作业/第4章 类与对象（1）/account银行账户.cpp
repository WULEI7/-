#include <iostream>
#include <iomanip>
using namespace std;

class Account{
public:
	void init(string initID,string initName,string initSex,int initAge,double initMoney)
	{
		ID=initID;
		name=initName;
		sex=initSex;
		age=initAge;
		int i=0;
		double n=initMoney;
		while((int)n<n)
		{n*=10;i++;}
		if(i>2) cout<<"������Ľ��Ϸ�"<<endl;
		else money+=initMoney;
	}
	void printmoney()
	{
		cout<<name<<"�Ĵ��Ϊ"<<fixed<<setprecision(2)<<money<<endl;
	}
	void deposit(double m)
	{
		int i=0;
		double n=m;
		while((int)n<n)
		{n*=10;i++;}
		if(i>2) cout<<"������Ľ��Ϸ�"<<endl;
		else money+=m;
	}
	void withdraw(double m)
	{
		int i=0;
		double n=m;
		while((int)n<n)
		{n*=10;i++;}
		if(i>2) cout<<"������Ľ��Ϸ�"<<endl;
		else if(m>money) cout<<"���Ĵ�����"<<endl;
		else money-=m;
	}
private:
	string ID;
	string name;
	string sex;
	int age;
	double money=0;
};

int main()
{
	Account tom;
	tom.init("32020320011001876X","Tom Black","��",19,2000.89);
	tom.printmoney();//�����Tom Black�Ĵ��Ϊ2000.89 
	tom.deposit(89.471);//�����������Ľ��Ϸ� 
	tom.printmoney();//�����Tom Black�Ĵ��Ϊ2000.89 
	tom.deposit(10000);
	tom.printmoney();//�����Tom Black�Ĵ��Ϊ12000.89 
	tom.withdraw(10001);
	tom.printmoney();//�����Tom Black�Ĵ��Ϊ1999.89 
	tom.withdraw(10000.123);//�����������Ľ��Ϸ� 
	tom.printmoney();//�����Tom Black�Ĵ��Ϊ1999.89 
	tom.withdraw(10000.9);//��������Ĵ����� 
	tom.printmoney();//�����Tom Black�Ĵ��Ϊ1999.89 
	Account jerry;
	jerry.init("320203200910116569","Jerry Black","Ů",11,100.956);//�����������Ľ��Ϸ� 
	jerry.printmoney();//�����Jerry Black�Ĵ��Ϊ0.00 
}
