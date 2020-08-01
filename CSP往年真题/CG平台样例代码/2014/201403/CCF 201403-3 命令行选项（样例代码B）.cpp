#include <bits/stdc++.h>
using namespace std;
#define IOFast() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
string s;
stringstream ss;
int T, cas;
map<char, int> mp1;
map<char, string> mp2;
char ch;
int main()
{
    IOFast();
    cin >> s;
    for (register unsigned int i = 0; i < s.size(); i++)
    {
        if (s[i] == ':')
            mp1[ch] = 2;
        else
            mp1[s[i]] = 1;
        ch = s[i];
    }
    cin >> T;
    cin.get();
    while (T--)
    {
        getline(cin, s);
        mp2.clear();
        ss.clear();
        ss.str("");
        ss << s;
        ss >> s;
        while (ss >> s)
        {
            if (s.size() != 2 || s[0] != '-' || mp1[s[1]] == 0)
                break;
            if (mp1[s[1]] == 1)
            {
                mp2[s[1]] = "";
                continue;
            }
            ch = s[1];
            if (ss >> s)
                mp2[ch] = s;
        }
        cout << "Case " << ++cas << ":";
        for (map<char, string>::iterator it = mp2.begin(); it != mp2.end(); it++)
            if (mp1[it->first] == 1)
                cout << " -" << it->first;
            else
                cout << " -" << it->first << " " << it->second;
        cout << "\n";
    }
    return 0;
}
