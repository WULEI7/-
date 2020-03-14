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
		if(i>2) cout<<"您输入的金额不合法"<<endl;
		else money+=initMoney;
	}
	void printmoney()
	{
		cout<<name<<"的存款为"<<fixed<<setprecision(2)<<money<<endl;
	}
	void deposit(double m)
	{
		int i=0;
		double n=m;
		while((int)n<n)
		{n*=10;i++;}
		if(i>2) cout<<"您输入的金额不合法"<<endl;
		else money+=m;
	}
	void withdraw(double m)
	{
		int i=0;
		double n=m;
		while((int)n<n)
		{n*=10;i++;}
		if(i>2) cout<<"您输入的金额不合法"<<endl;
		else if(m>money) cout<<"您的存款金额不足"<<endl;
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
	tom.init("32020320011001876X","Tom Black","男",19,2000.89);
	tom.printmoney();//输出：Tom Black的存款为2000.89 
	tom.deposit(89.471);//输出：您输入的金额不合法 
	tom.printmoney();//输出：Tom Black的存款为2000.89 
	tom.deposit(10000);
	tom.printmoney();//输出：Tom Black的存款为12000.89 
	tom.withdraw(10001);
	tom.printmoney();//输出：Tom Black的存款为1999.89 
	tom.withdraw(10000.123);//输出：您输入的金额不合法 
	tom.printmoney();//输出：Tom Black的存款为1999.89 
	tom.withdraw(10000.9);//输出：您的存款金额不足 
	tom.printmoney();//输出：Tom Black的存款为1999.89 
	Account jerry;
	jerry.init("320203200910116569","Jerry Black","女",11,100.956);//输出：您输入的金额不合法 
	jerry.printmoney();//输出：Jerry Black的存款为0.00 
}
