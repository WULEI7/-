#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string s[21]={"zero","one","two","three","four","five","six","seven","eight","nine","ten",
"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int h,m;
	cin>>h>>m;
	if(h<=20)
		cout<<s[h]<<" ";
	else
		cout<<"twenty "<<s[h%10]<<" ";
	if(m==0)
		cout<<"o'clock"<<endl;
	else if(m>=1&&m<=20)
		cout<<s[m]<<endl;
	else if(m>20&&m<30)
		cout<<"twenty "<<s[m%10]<<endl;
	else if(m==30)
		cout<<"thirty"<<endl;
	else if(m>30&&m<40)
		cout<<"thirty "<<s[m%10]<<endl;
	else if(m==40)
		cout<<"forty"<<endl;
	else if(m>40&&m<50)
		cout<<"forty "<<s[m%10]<<endl;
	else if(m==50)
		cout<<"fifty"<<endl;
	else
		cout<<"fifty "<<s[m%10]<<endl;
	return 0;
}
