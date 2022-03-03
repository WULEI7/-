#include<stdio.h>
bool isleap(int y){
	return((y%4==0&&y%100!=0)||y%400==0);//闰年返回1，平年返回0 
}
int main(){
	int month[13][2];
	for(int i=1;i<=12;i++){
		for(int j=0;j<2;j++){
			if(i==1||i==3||i==5||i==7||i==8||i==10||i==12){
				month[i][j]=31;
			}
			else if(i==2&&j==0){
				month[i][j]=28;//平年二月28天 
			}
			else if(i==2&&j==1){
				month[i][j]=29;
			} 
			else{
				month[i][j]=30;
			}
		}
	}
	int time1,y1,m1,d1;
	int time2,y2,m2,d2;
	while(scanf("%d%d",&time1,&time2)!=	EOF){
		int temp;
		if(time1<time2){
			temp=time2;
			time2=time1;
			time1=temp;
		} 
		y1=time1/10000;
		m1=time1%10000/100;
		d1=time1%100;
		y2=time2/10000;
		m2=time2%10000/100;
		d2=time2%100;
		int ans=1;
		while(y2<y1||m2<m1||d2<d1){
			d2++;
			if(d2==month[m2][isleap(y2)]+1){
				m2++;
				d2=1;
			}
			if(m2==13)
			{
				y2++;
				m2=1;
			}
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}