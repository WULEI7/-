#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

/*
ʾ��������123
 1 % 2 = 1;		//������������һλ
 1 / 2 = 0;      //��λ����Ϊ0 
 k = 1;
 
 12 % 2 = 0;
 12 / 2 = 6;
 k = 0;			//û����������һλ��������

 3 % 2 = 1;
 3 / 2 = 1;
 k = 1��       //ʣ��61         һ�ֽ�������k���浽b
 
 61 % 2 = 1;
 61 / 2 = 30;
 k = 1;

 11 % 2 = 1;
 11 / 2 = 5;
 k = 1;       //ʣ��30          ���ֽ�������k���浽b

 3 % 2 = 1;
 3 / 2 = 1;
 k = 1;
 
 10 % 2 = 0;
 10 / 2 = 5;
 k = 0 ;       //ʣ��15			���ֽ�������k���浽b

 1 % 2 = 1;
 1 / 2 = 0;
 k = 1;
 
 15 % 2 = 1;
 15 / 2 = 7;
 k = 1;        //ʣ��7			���ֽ�������k���浽b

 7 % 2 = 1;
 7 / 2 = 3;
 k = 1;         //ʣ��3			���ֽ�������k���浽b

 3 % 2 = 1;
 3 / 2 = 1;
 k = 1;         //ʣ��1			���ֽ�������k���浽b

1 % 2 = 1;
1 / 2 = 0;
k = 1;         //0				���ֽ�������k���浽b

����b����Ϊ   1101111
���������鷴���� 1111011 
*/ 
string conversion(int m, string a, int n){
    int l = a.length(), k;
    string b = "";
    for(int i = 0; i < l; ){                         //��������
        k = 0;
        //��������
        for(int j = i; j < l; j++){
            int t = (k * m + a[j] - '0') % n;
            a[j] = (k * m + a[j] - '0') / n + '0';
            k = t;
        }
        b += char(k + '0');
        while(a[i] == '0') i++;
    } 
    reverse(b.begin(), b.end());		//������
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

