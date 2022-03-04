#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main(){
	string str;
	cin>>str;
	string s;
	getchar();
	while(getline(cin,s)){
		int len=str.length();
		int l=s.length();
		int p=0;
		int x[1000];
		for(int i=0;i<len;i++){
		    if(str[i]>='a'&&str[i]<='z'){
				x[i]=str[i]-'a';
			}
			else if(str[i]>='A'&&str[i]<='Z'){
				x[i]=str[i]-'A';
			}
	 	}
		if(l<len){
			printf("%s\n",s.c_str());
		}	
		else if(l==len){
			for(int i=0;i<len;i++){
				if(s[i]=='a'+x[i]||s[i]=='A'+x[i]){
					p++;
				}
			}
			if(p!=len)
				printf("%s\n",s.c_str());
		}
		else{
		    int t[1000];
		    for(int i=0;i<=l-len;i++){
			    int c=0;
			    int y=0;
				for(int j=i;j<i+len;j++){
					if(s[j]=='a'+x[j-i]||s[j]=='A'+x[j-i]){
						y=j;
						c++;
					}
				}
				if(c==len){
					s.erase(s.begin()+y-len+1,s.begin()+y+1);
					i=i-len;
				}
			}
			int ll=s.length();
			for(int i=0;i<ll;i++){
				if(s[i]==' '){
					s.erase(i,1);
					i--;
				}
			}
			printf("%s\n",s.c_str());
		}	
	}
} 
