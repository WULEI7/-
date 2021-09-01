#include <iostream>
using namespace std;

const int maxn = (1 << 22) + 5;

char str[maxn] {'0','1','1','0','1','0','0','1'};

int main(){
    int n;
    cin >> n;
    int m = (1 << n);
    str[m] = '\0';
    if(n == 1){
        cout << "01" <<"\n";
    }
    else if(n == 2){
        cout <<"0111\n";
    }
    else if(n == 3){
        cout << str << "\n";
    }
    else{
        int base = 8;
        int i = 8;
        while(i < m){
            int tmp = i + base;
            for(; i < tmp; ++i){
                str[i] = str[i - base] == '1' ? '0' : '1';
            }
            base *= 2;
        }
            cout << str;
    }

    return 0;
}
