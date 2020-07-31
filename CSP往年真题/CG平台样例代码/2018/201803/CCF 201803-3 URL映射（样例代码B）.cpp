#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <queue>
#include<set>
#include<string.h>
#include<istream>
#define ll long long
#define mkp make_pair
using namespace std;
const int MAXN = 300;

int n, m;
string r[MAXN], p[MAXN];
vector<string > v[MAXN];

bool check(string s) {
    int cnt = 0;
    for(int i = 0; i < s.size(); ++i) {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || (s[i] == '/') || (s[i] == '-') || (s[i] == '_') || (s[i] == '.')) {
            cnt++;
        }
        // else cout<<"s[i] : "<<s[i]<<endl;
    }
    // cout<<endl<<"check : "<<cnt<<" "<<s.size()<<endl<<endl;
    return cnt == s.size();
}

bool path[MAXN];

vector<string > brk(string s) {
    vector<string > vtmp;
    int len = s.size();
    int pos = 0;
    for(int j = 1; j < len; ++j) {
        if(s[j] == '/') {
            vtmp.push_back(s.substr(pos+1, j-pos-1));
            pos = j;
        }
    }
    if(pos != len-1) {
        vtmp.push_back(s.substr(pos+1, len-pos-1));
    }
    return vtmp;
}

void solve(string s) {
    if(!check(s)) {
            // cout<<"²»ºÏ·¨"<<endl;
        puts("404");
        return ;
    }
    vector<string > vstr = brk(s);
    vector<string > vtype;
    for(int i = 0; i < vstr.size(); ++i) {
        int cnt = 0;
        for(int j = 0; j < vstr[i].size(); ++j) {
            if(vstr[i][j] >= '0' && vstr[i][j] <= '9') cnt++;
        }
        if(cnt == vstr[i].size()) vtype.push_back("<int>");
        else vtype.push_back("<str>");
    }

    for(int i = 0; i < n; ++i) {
        vector<string > res;
        // res.clear();
        if(path[i] || v[i].size() == vstr.size()) {
            int j = 0;
            for(; j < v[i].size(); ++j) {
                if(v[i][j] == vstr[j]) {
                    // res.push_back(vstr[j]);
                    /*
                    cout<<"push : "<<vstr[j]<<" "<<i<<endl;;
                    cout<<"res.size(): "<<res.size()<<endl;

                    for(int k = 0; k < res.size(); ++k) {
                        cout<<res[k]<<" ";
                    }cout<<endl;
                    */
                    continue;
                }
                else if(v[i][j] == vtype[j]) {
                    if(vtype[j] != "<int>") {
                        res.push_back(vstr[j]);
                        continue;
                    }
                    else {
                        string str = vstr[j];
                        int l = 0, len = str.size();
                        while(l < len && str[l] == '0') l++;
                        if(l == len) res.push_back("0");
                        else res.push_back(str.substr(l, len-l));
                        continue;
                    }
                }
                else {
                    if(v[i][j] == "<path>") {
                        string strtmp;
                        int num = 0;
                        for(int k = 1; k < s.size(); ++k) {
                            if(s[k] == '/') num++;
                            if(num == j) {
                                strtmp += s.substr(k+1, s.size()-k-1);
                                break;
                            }
                        }
                        cout<<r[i]<<" ";
                        for(int k = 0; k < res.size(); ++k) {
                            cout<<res[k]<<" ";
                        } cout<<strtmp<<endl;
                        return ;
                    }
                    else {
                        break;
                    }
                }
            }
            if(j == v[i].size()) {
                if((s[s.size()-1] == '/' && p[i][p[i].size()-1] == '/') || (s[s.size()-1] != '/' && p[i][p[i].size()-1] != '/')) {
                    cout<<r[i]<<" ";
                    for(int k = 0; k < res.size(); ++k) {
                    //if(vtype[k] == "<int>" || vtype[k] == "<str>")
                        cout<<res[k]<<" ";
                    }cout<<endl;
                    return ;
                }
                    // cout<<"res.size(): "<<res.size()<<endl;

            }
        }
    }

    puts("404");
}

int main()
{
     //freopen("in.txt", "r", stdin);
    cin>>n>>m;

    for(int i = 0; i < n; ++i) {
        cin>>p[i]>>r[i];
        v[i] = brk(p[i]);
        for(int j = 0; j < v[i].size(); ++j) {
            if(v[i][j] == "<path>") {
                path[i] = 1;
                break;
            }
        }
    }
    /*
    cout<<"v : "<<endl;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < v[i].size(); ++j) {
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }
    */
    string q;
    for(int i = 0; i < m; ++i) {
        cin>>q;
        solve(q);
    }
    return 0;
}
