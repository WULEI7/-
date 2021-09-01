#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int x){
    if(x <= 2) return 0;
    int m = (int)(sqrt(x) + 0.5);
    for(int i = 2; i <= m; ++i){
        if(x % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool flag = true;
        if(n % 400 == 0){
            
        }
        else if(n % 100 == 0){
            flag = false;
        }
        else if(n % 4 == 0){
            
        }
        else{
            flag = false;
        }
        if(flag && isprime(n)){
            cout <<"yes\n";
        }
        else{
            cout<<"no\n";
        }
    }
    return 0;
}
