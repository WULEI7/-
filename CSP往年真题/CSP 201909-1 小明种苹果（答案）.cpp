#include<iostream>
using namespace std;
int main()
{
	int apptrcnt,time;
	int num=0,remove,id,allapp=0;
	int maxx=-1;
	cin>>apptrcnt>>time;
	for(int i=0;i<apptrcnt;++i)
	{
		cin>>num;
		allapp+=num;
		remove=0;
		for(int j=0;j<time;++j)
		{
			cin>>num;
			allapp+=num;
			remove-=num;
		}
		if(remove>maxx)
		{
			maxx=remove;
			id=i;
		}
	}
	cout<<allapp<<" "<<id+1<<" "<<maxx;
	return 0;
}
