#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;
int n,N,q,o,a;
//int write=0,cache=-1;
//int write[65536],cache[65536];
int main()
{
	cin>>n>>N>>q;
	if(n==1&&N==1)
	{
		int write=0,cache=-1;
		while(q--)
		{
			cin>>o>>a;
			if(o==0)
			{
				//if(cache==a)
				//	continue;
				if(cache!=a)
				{
					if(write)
					{
						cout<<1<<" "<<cache<<endl;
						write=0;
					}
					cache=a;
					cout<<0<<" "<<a<<endl;
				}
			}
			else//o==1
			{
				if(cache==a)
				{
					write=1;
					//continue;
				}
				else
				{
					if(write)
					{
						cout<<1<<" "<<cache<<endl;
						write=0;
					}
					cache=a;
					write=1;
					cout<<0<<" "<<a<<endl;
				}
			}
			//cout<<"cache "<<cache<<endl;
			//cout<<"write "<<write<<endl;
		}
	}
	else if(n==1)
	{
		int write[65536],cache[65536];
		for(int i=0;i<N;i++)
		{
			write[i]=0;
			cache[i]=-1;
		}
		while(q--)
		{
			cin>>o>>a;
			int index=a%N;
			if(o==0)
			{
				//if(cache==a)
				//	continue;
				if(cache[index]!=a)
				{
					if(write[index])
					{
						cout<<1<<" "<<cache[index]<<endl;
						write[index]=0;
					}
					cache[index]=a;
					cout<<0<<" "<<a<<endl;
				}
			}
			else//o==1
			{
				if(cache[index]==a)
				{
					write[index]=1;
					//continue;
				}
				else
				{
					if(write[index])
					{
						cout<<1<<" "<<cache[index]<<endl;
						write[index]=0;
					}
					cache[index]=a;
					write[index]=1;
					cout<<0<<" "<<a<<endl;
				}
			}
		}
	}
	else if(N==1)
	{
		queue<int> lruQueue;// 使用队列来实现LRU策略
		map<int, int> cache;// 使用map来快速检查内存块是否在缓存中，以及更新其在队列中的位置
		while (q--) {
            cin >> o >> a;
            if (cache.find(a) == cache.end()) { // 未命中
                if (lruQueue.size() == n) { // 缓存已满，需要替换
                    int evict = lruQueue.back();
                    lruQueue.pop();
                    if (cache[evict] == 1) { // 如果被替换的缓存行被写入过，需要写回内存
                        cout << 1 << " " << evict << endl;
                    }
                    cache.erase(evict);
                }
                lruQueue.push(a);
                cache[a] = 0;
                cout << 0 << " " << a << endl; // 从内存读取数据
            } else { // 命中
                if (o == 1) { // 写操作
                    cache[a] = 1;
                }
                lruQueue.push(a); // 将访问的缓存行移动到队列前端
                lruQueue.pop(); // 移除队列末尾的元素
            }
        }
	}
	return 0;
}
