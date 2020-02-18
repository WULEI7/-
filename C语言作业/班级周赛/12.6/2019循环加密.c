#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<math.h>
int N,p[21],b[21]; 
bool isprime(int a);
void search(int step);
int main() { 
	int i=1; 
	scanf("%d",&N);
    i++; 
    assert(!(N&1)&&N>=1&&N<=20); 
    b[1]=1;
   	p[0]=1; 
    search(1);

return 0; 
}
bool isprime(int a){
	
	int i;
	if(a==1||a==0)return false;
	for(i=2;i<=(int)sqrt((double)a);i++){
		if(!(a%i))return false;
	}
	return true;
}

void search(int x) { 
      int i; 
      if(x==N) 
      { 
            if(isprime(p[0]+p[N-1])) 
            { 
                  for(i=0;i<N-1;i++) 
                  printf("%d ",p[i]); 
                  printf("%d",p[N-1]); 
                  printf("\n"); 
            } 
      } 
      for(i=1;i<=N;i++) 
      { 
      if(!b[i] && (isprime(i+p[x-1]))){ 
            b[i]=1; 
            p[x]=i; 
            search(x+1); 
            b[i]=0; 
            } 
      } 
} 
