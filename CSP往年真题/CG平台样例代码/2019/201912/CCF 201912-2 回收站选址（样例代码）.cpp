#include<cstdio>
#include<set>
using namespace std;

struct Point{
    int x;
    int y;
    Point(int _x, int _y): x(_x), y(_y){}
    bool operator < (const Point &rhs) const {
        if(x==rhs.x) return y<rhs.y;
        return x<rhs.x;
    }
};

int n;
int ans[5];
set<Point> pts;

bool find(int x, int y){
    if(pts.find(Point(x, y))!=pts.end()) return true;
    return false;
}

int main(){
    scanf("%d",&n);
    int x, y;
    for(int i=0;i<n;++i){
        scanf("%d%d", &x, &y);
        pts.insert(Point(x, y));
    }
    
    set<Point>::iterator it;
    for(it=pts.begin(); it!=pts.end(); it++){
        x=(*it).x; y=(*it).y;
        if(find(x, y+1) && find(x, y-1) && find(x+1, y) && find(x-1, y) ){
            int cnt=0;
            if(find(x-1, y+1)) cnt++;
            if(find(x+1, y+1)) cnt++;
            if(find(x-1, y-1)) cnt++;
            if(find(x+1, y-1)) cnt++;
            ans[cnt]++;
        }
    }
    
    for(int i=0; i<5; ++i){
        printf("%d\n", ans[i]);
    }
    
    return 0;
}

