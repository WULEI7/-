/* CCF201412-3 集合竞价 */
#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 5000;

struct trading {
    int orderno;
    char t;
    float price;
    long long quantity;
    bool operator < (const trading& n) const {
        if (t == 's')
            return price > n.price;
        else // t == 'b'
            return price < n.price;
    }
};

bool cancelflag[N + 1];

int main()
{
    trading t;
    priority_queue<trading> sell, buy;
    string strading;

    // 变量初始化
    memset(cancelflag, false, sizeof(cancelflag));

    // 输入数据
    int no = 0, tno;

    while (cin >> strading) {
        if (strading[0] == 'c') {
            // 设置交易号
            no++;

            // 输入取消的交易号
            cin >> tno;

            // 设置取消标志
            cancelflag[tno] = true;
        }
        else if (strading[0] == 'b' || strading[0] == 's') {
            // 设置交易号
            t.orderno = ++no;

            // 输入交易价格和数量
            cin >> t.price >> t.quantity;

            // 将交易分别放入买入和卖出的优先队列
            if (strading[0] == 'b') {
                t.t = strading[0];
                buy.push(t);
            }
            else {    // t.trading[0] == 's'
                t.t = strading[0];
                sell.push(t);
            }
        }
        else
            break;
    }

    // 集合竞价处理
    t.price = 0;
    t.quantity = 0;
    trading b, s;
    for (;;) {
        // 清除被取消的订单（同时将队头放在b和s中）
        while (!buy.empty()) {
            b = buy.top();
            if (cancelflag[b.orderno])
                buy.pop();
            else
                break;
        }
        while (!sell.empty()) {
            s = sell.top();
            if (cancelflag[s.orderno])
                sell.pop();
            else
                break;
        }

        // 买卖队列只要有一个为空，则处理结束
        if (buy.empty() || sell.empty())
            break;

        // 集合竞价处理
        if (b.price >= s.price) {
            t.quantity += min(b.quantity, s.quantity);
            t.price = b.price;

            if (b.quantity == s.quantity) {
                buy.pop();
                sell.pop();
            }
            else if (b.quantity > s.quantity) {
                b.quantity -= s.quantity;
                buy.pop();
                buy.push(b);
                sell.pop();
            }
            else {    // b.quantity < s.quantity
                buy.pop();
                s.quantity -= b.quantity;
                sell.pop();
                sell.push(s);
            }
        }
        else
            break;
    }

    // 输出结果
    printf("%.2f", t.price);
    cout << " " << t.quantity << endl;

    return 0;
}

/*
测试样例：
sell 8.88 100
sell 8.88 175
sell 9.00 400
buy 8.88 400
cancel 1
sell 100.00 50
8.88 175
buy 9.25 100
buy 8.88 175
buy 9.00 400
sell 8.88 400
cancel 1
buy 100.00 50
9.00 400
buy 9.25 100
buy 8.88 175
buy 9.00 400
sell 8.79 1501
cancel 1
cancel 2
9.00 400
buy 9.25 110
buy 8.88 300
buy 18.88 200
sell 8.88 201
sell 9.25 100
9.25 301
*/
