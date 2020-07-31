#include<iostream>
using namespace std;
int main(){
    int a[15][10];
    int b[4][4];
    int i,j,s,t;
    int c[4]={14,14,14,14},d[4]={-20,-20,-20,-20}; 
    for(i=0;i<15;i++)
    for(j=0;j<10;j++)
    cin>>a[i][j];
    for(i=0;i<4;i++)
    for(j=0;j<4;j++)
    cin>>b[i][j];
    cin>>s;
    s=s-1;
    for(i=s;i<s+4;i++)
    for(j=0;j<15;j++){
        if(a[j][i]==1){
            c[i-s]=j-1;
            break; 
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(b[j][i]==1)
            d[i]=j; 
        }
    }
    int minl=15;
    for(i=0;i<4;i++)
    if(c[i]-d[i]<minl){
        minl=c[i]-d[i]; 
        t=i;
    }
    int h=c[t],h1=d[t];
    for(i=0;i<4;i++)
    for(j=0;j<4;j++){
        if(b[i][j]==1)
        a[h-h1+i][s+j]=b[i][j];
    }
    for(i=0;i<15;i++){
        for(j=0;j<10;j++){
            if(j!=9)
            cout<<a[i][j]<<' ';
            else
            cout<<a[i][j]<<endl;
        }
    }
}
