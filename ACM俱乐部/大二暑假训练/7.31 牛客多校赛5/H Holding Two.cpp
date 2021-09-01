#include <iostream>
#include <string>
using namespace std;

string a = "10";
string b = "01";

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(i % 4 <= 1){
                cout << a[(j - 1) % 2];
            }
            else{
                cout << b[(j - 1) % 2];
            }
        }
        cout <<"\n";
    }
    return 0;
}
