#include <iostream>  
  
using namespace std;  
  
int main()  
{  
    int n, k, count=0, val, sub=0;  
  
    cin >> n >> k;  
    for(int i=1; i<=n; i++) {  
        cin >> val;  
  
        if((sub += val) >= k) {  
            count++;  
            sub = 0;  
        }  
    }  
    if(sub > 0)  
        count++;  
  
    cout << count << endl;  
  
    return 0;  
}  

