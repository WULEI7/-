#include <iostream>
#include<stdio.h>
#include <string>
#include<algorithm>
using namespace std;
struct testee{
	string num;
	double score;
	int localnum;
	int localrank;
	int r;
}testees[30010];
bool cmp(testee a,testee b){
	if(a.score!=b.score){
		return a.score>b.score;
	}
	else{
		return a.num<b.num;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int k;
	int w=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=w;j<k+w;j++){
			testees[j].localnum=i;
			cin>>testees[j].num>>testees[j].score;
		}
	   	sort(testees+w,testees+w+k,cmp);
		testees[w].localrank=1;
		for(int j=w+1;j<k+w;j++){
			if(testees[j].score==testees[j-1].score){
				testees[j].localrank=testees[j-1].localrank;
			}
			else{
				testees[j].localrank=j-w+1;
			}
		}
		w+=k;
	}
	printf("%d\n",w);
	sort(testees,testees+w,cmp);
	testees[0].r=1;
	for(int i=1;i<w;i++){
		if(testees[i].score==testees[i-1].score){
			testees[i].r=testees[i-1].r;
		}
		else{
			testees[i].r=i+1;
		}
	}
	for(int i=0;i<w;i++){
	    printf("%s %d %d %d\n",testees[i].num.c_str(),testees[i].r,testees[i].localnum,testees[i].localrank);
	}
	return 0;
} 
