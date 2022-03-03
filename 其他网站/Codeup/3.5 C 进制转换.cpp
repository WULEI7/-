#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

/*
示例：输入123
 1 % 2 = 1;		//将余数传给下一位
 1 / 2 = 0;      //百位数变为0 
 k = 1;
 
 12 % 2 = 0;
 12 / 2 = 6;
 k = 0;			//没有余数给下一位，被整除

 3 % 2 = 1;
 3 / 2 = 1;
 k = 1；       //剩余61         一轮结束，将k保存到b
 
 61 % 2 = 1;
 61 / 2 = 30;
 k = 1;

 11 % 2 = 1;
 11 / 2 = 5;
 k = 1;       //剩余30          两轮结束，将k保存到b

 3 % 2 = 1;
 3 / 2 = 1;
 k = 1;
 
 10 % 2 = 0;
 10 / 2 = 5;
 k = 0 ;       //剩余15			三轮结束，将k保存到b

 1 % 2 = 1;
 1 / 2 = 0;
 k = 1;
 
 15 % 2 = 1;
 15 / 2 = 7;
 k = 1;        //剩余7			四轮结束，将k保存到b

 7 % 2 = 1;
 7 / 2 = 3;
 k = 1;         //剩余3			五轮结束，将k保存到b

 3 % 2 = 1;
 3 / 2 = 1;
 k = 1;         //剩余1			六轮结束，将k保存到b

1 % 2 = 1;
1 / 2 = 0;
k = 1;         //0				七轮结束，将k保存到b

所得b数列为   1101111
将所得数组反过来 1111011 
*/ 
string conversion(int m, string a, int n){
    int l = a.length(), k;
    string b = "";
    for(int i = 0; i < l; ){                         //塞入数字
        k = 0;
        //求商求余
        for(int j = i; j < l; j++){
            int t = (k * m + a[j] - '0') % n;
            a[j] = (k * m + a[j] - '0') / n + '0';
            k = t;
        }
        b += char(k + '0');
        while(a[i] == '0') i++;
    } 
    reverse(b.begin(), b.end());		//反过来
    return b;
}
int main(){
    string a, b;
    while(cin >> a){
        b = conversion(10, a, 2);
        cout << b << endl;   
    }
    return 0;
}

