#include <iostream>  
#include <queue>  
using namespace std;  
int main() {  
    int n=0,k=0,i=0,num=1;  
    cin>>n>>k;  
    queue<int, deque<int> > q; //定义一个队列来保存报数  
    for(i=1;i<=n;i++) { //初始化队列  
        q.push(i);  
    }  
    while(q.size()>1) { //判断队列是否只剩下一个元素  
        int top = q.front(); //保存当前队首的元素  
        q.pop();    //将当前队首元素值从队列中删除  
        if(num%k!=0 && num%10!=k) { //判读当前的报数是否满足游戏规则  
            q.push(top);    //若满足，则将队首重新插入队尾，等待下一轮游戏  
        }  
        num++;  //报数+1  
    }  
    cout<<q.front();    //输出队列q中仅剩的一个元素  
    return 0;  
}

