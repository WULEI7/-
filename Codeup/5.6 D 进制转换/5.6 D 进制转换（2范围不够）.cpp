#include<stdio.h>
#include<string>
#include<iostream>
#include<cmath> 
using namespace std;
int main(){
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		string num;
		cin>>num;
		if(num=="0"){
			printf("0\n");
			continue;
		}
		int len=num.length();
		long long t=0;
		int q=0;
		for(int i=len-1;i>=0;i--){
			if(num[i]>='0'&&num[i]<='9'){
				t+=(num[i]-'0')*pow(m,q);
				q++;
			}
			else if(num[i]>='A'&&num[i]<='Z'){
				t+=(num[i]-'A'+10)*pow(m,q);
				q++;
			}
		}
		string ans;
		while(t!=0){
			string s;
			if(t%n>=0&&t%n<=9){
				s=t%n+'0';
				ans+=s;
			}
			else{
				s=t%n-10+'a';
				ans+=s;
			}
			t/=n;	
		}
		string ans1(ans.rbegin(),ans.rend());
		cout<<ans1<<endl;	
	}
	return 0;
}
