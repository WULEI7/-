#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double pi = acos(-1);

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        double w, d;
        cin >> w >> d;
        double len = min(w, d);
        double len2 = sqrt(w*w +d*d);
        long long line = (long long)(pi / len);
        long long line2 = (long long)(pi / len2);
        long long ans1 = line*2 + 4;
        long long ans2 = line2*3 + 4;
        ans2 += (long long)((pi - len2*line2) / len) * 2;
        long long ans3 = 0;
        if(line2 >= 1){
            line2--;
            ans3 = 4+line2*3+(long long)((pi - line2*len2) / len) * 2;
        }
        long long ans4 = 0;
        if(line >= 1){
            line--;
            if(pi-line*len > len2)
                ans4 = 4+line*2+3;
        }
       // cout << ans1 <<" "<<ans2<<" "<<ans3<<" "<<ans4<<endl;
        cout << max(max(max(ans1, ans2), ans3), ans4) <<"\n";
    }
    return 0;
}
