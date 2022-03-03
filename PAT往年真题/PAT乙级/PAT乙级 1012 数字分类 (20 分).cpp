#include<stdio.h>
int main(){
    int n;
    int a[1000];
    while(scanf("%d",&n)!=EOF){
        int a1=0;
        int a2=0;
        int a3=0;
        int a4=0;
        int a5=0;
        int b=0;
        int t=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++){
            if((a[i]%5==0)&&(a[i]%2==0)){
                a1+=a[i];
            }
            
            if(a[i]%5==1){
                ++b;
                if(b%2==1)
                    a2+=a[i];
                else
                    a2+=(-1)*a[i];
            }
            
            if(a[i]%5==2){
                a3++;
            }
            
            if(a[i]%5==3){
                t++;
                a4+=a[i];
            }
            
            if(a[i]%5==4){
                if(a[i]>a5)
                   a5=a[i];
            }
            
        }
        if(a1==0)
            printf("N ");
		else
			printf("%d ",a1) ;
		if(b==0)//陷阱，数的和可能为0 
            printf("N ");
		else
			printf("%d ",a2) ;
		if(a3==0)
            printf("N ");
		else
			printf("%d ",a3) ;
		if(a4==0)
            printf("N ");
		else
			printf("%.1f ",(double)a4/(double)t) ;
		if(a5==0)
            printf("N\n");
		else
			printf("%d\n",a5) ;
    }
    return 0;
}
