#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, map_index;					// 方程式的个数N，map的下标
string input;						// 每行输入的化学方程式
unordered_map<string, int> mp[2];	// 两个map

void deal_part(string part);
void deal_expr(string expr);
void deal_formula(int ceof, string formula);
void deal_term(int ceof, string element);

/* 以flag分割str，将分割后的字符串集合存放到vec中 */
void split(string& str, vector<string>& vec, char flag)
{
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, flag))
    {
        vec.push_back(temp);
    }
}

/* 以=分割化学方程式，分别处理 */
void deal_input(string input)
{
    vector<string> vec;
    split(input, vec, '=');

    // 处理左半部分
    map_index = 0;
    deal_part(vec[0]);
    // 处理右半部分
    map_index = 1;
    deal_part(vec[1]);
}

/* 处理expr+expr+expr */ 
void deal_part(string part)
{
    vector<string> vec;
    split(part, vec, '+');

    for(string& expr : vec)
    {
        deal_expr(expr);
    }
}

/* 处理<expr> ::= <ceof><formula> */ 
void deal_expr(string expr)
{
	// ceof不为空串的情况 
    if(isdigit(expr[0]))
    {
        int ceof = 1;
        string formula;

        stringstream ss(expr);
        ss >> ceof;
        ss >> formula;

        deal_formula(ceof, formula);	// ceof为系数ceof 
    }
	
	// ceof为空的情况 
    else deal_formula(1, expr);		// 系数为1 
}

/* 处理<formula> ::= <term><ceof> */ 
void deal_formula(int ceof, string formula)
{
    auto cur = formula.begin();

    while(cur != formula.end())
    {
        if(isupper(*cur))	// 大写字母，说明是 <term> ::= <element><ceof> 的情况  
        {
        	// 元素(如Ca) 在formula当中的起始位置和终止位置 
            string::iterator element_begin = cur, element_end;

            if(cur + 1 != formula.end() && islower(*(cur+1)))	// 若存在小写字母 
                element_end = cur + 2;
            else element_end = cur + 1;
			 
            string element(element_begin, element_end);
			
			// 不存在term的后缀ceof 
            if(element_end == formula.end() || !isdigit(*element_end))
            {
                deal_term(ceof, element);	// 元素的个数为：系数ceof 
                cur = element_end;
            }
            // 存在后缀ceof 
            else
            {
            	// ceof的位置迭代器 
                string::iterator ceof_begin = element_end, ceof_end;
                for(ceof_end = ceof_begin + 1; ceof_end != formula.end(); ++ceof_end)
                {
                    if(!isdigit(*ceof_end)) break;
                }
                string ceof_str(ceof_begin, ceof_end);
                int ceof_int = atoi(ceof_str.c_str());
                deal_term(ceof * ceof_int, element);	// 元素的个数为：系数ceof * 后缀ceof 
                cur = ceof_end;
            }
        }
        else if(*cur == '(')	// 是括号，说明是 <term> ::= (<formula>) 的情况 
        {
        	// 新的formula的起始位置和终止位置 
            string::iterator form_begin = cur + 1, form_end;
            int bracket_count = 1;
            for(form_end = cur + 1; form_end != formula.end(); ++form_end)
            {
                if(*form_end == '(') ++bracket_count;
                if(*form_end == ')') --bracket_count;
                if(bracket_count == 0) break;
            }
            string form(form_begin, form_end); 
			
			// 不存在后缀ceof 
            if(form_end + 1 == formula.end() || !isdigit(*(form_end+1)))
            {
                deal_formula(ceof, form);
                cur = form_end + 1;
            }
            // 存在后缀ceof 
            else
            {
                string::iterator ceof_begin = form_end + 1, ceof_end;
                for(ceof_end = ceof_begin + 1; ceof_end != formula.end(); ++ceof_end)
                {
                    if(!isdigit(*ceof_end)) break;
                }
                string ceof_str(ceof_begin, ceof_end);
                int ceof_int = atoi(ceof_str.c_str());
                deal_formula(ceof * ceof_int, form);
                cur = ceof_end;
            }
        }
    }
}

void deal_term(int ceof, string element)
{
//    cout << ceof << " " << element << "\n";
    mp[map_index][element] += ceof;
}

/* 判断两个哈希map是否相等 */ 
bool isEqual(unordered_map<string, int>& src, unordered_map<string, int>& dst)
{
	// 判断大小 
    if(src.size() != dst.size()) return false;
    
	// 注：pair为<key, value>的元组，key为pair.first，value为pair.second 
    for(auto pair : src)
    {
        auto it = dst.find(pair.first);		// 在dst中寻找这个key
        if(it == dst.end()) return false;	// 没有找到，则map不相等 
        if(it->second != pair.second) return false;		// 找到了，但是value不一样，map也不相等 
    }
    return true;
}

int main()
{
    cin >> n;
    cin.get();	// 注意吃掉第一行末尾的'\n'，为getline做准备 

    for(int i=0; i<n; ++i)
    {
        mp[0].clear();			// 清空map 
        mp[1].clear();
        getline(cin, input);	// 读取一个化学方程式 
        deal_input(input); 
        cout << (isEqual(mp[0], mp[1]) ? 'Y' : 'N') << "\n";
    }

    return 0;
}

