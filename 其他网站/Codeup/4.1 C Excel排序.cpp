#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct student{
    char num[10];
    char name[10];
    int score;
}students[100010];
bool cmp1(student a,student b){
	return strcmp(a.num,b.num)<0;
}
bool cmp2(student a,student b){
	if(strcmp(a.name,b.name)==0){
		return strcmp(a.num,b.num)<0;
	} 
	else{
		return strcmp(a.name,b.name)<0;
	}	
}
bool cmp3(student a,student b){
	if(a.score!=b.score){
		return a.score<b.score;
	}
	else{
		return strcmp(a.num,b.num)<0;
	}
}
int main(){
	int t=0;
    while(1){
        int n;
        scanf("%d",&n);
        int c;
        scanf("%d",&c);
        if(n==0){
            break;
        }
        for(int i=0;i<n;i++){
            scanf("%s %s %d",students[i].num,students[i].name,&students[i].score);
        }
        switch(c){
        	case 1:
        		sort(students,students+n,cmp1);
        		printf("Case %d:\n",++t);
        		for(int i=0;i<n;i++){
        			printf("%s %s %d\n",students[i].num,students[i].name,students[i].score);
				}
			break;
			case 2:
        		sort(students,students+n,cmp2);
        		printf("Case %d:\n",++t);
        		for(int i=0;i<n;i++){
        			printf("%s %s %d\n",students[i].num,students[i].name,students[i].score);
				}
			break;
			case 3:
        		sort(students,students+n,cmp3);
        		printf("Case %d:\n",++t);
        		for(int i=0;i<n;i++){
        			printf("%s %s %d\n",students[i].num,students[i].name,students[i].score);
				}
			break;
		}
    }
    return 0;
}
