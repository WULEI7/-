#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, map_index;					// ����ʽ�ĸ���N��map���±�
string input;						// ÿ������Ļ�ѧ����ʽ
unordered_map<string, int> mp[2];	// ����map

void deal_part(string part);
void deal_expr(string expr);
void deal_formula(int ceof, string formula);
void deal_term(int ceof, string element);

/* ��flag�ָ�str�����ָ����ַ������ϴ�ŵ�vec�� */
void split(string& str, vector<string>& vec, char flag)
{
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, flag))
    {
        vec.push_back(temp);
    }
}

/* ��=�ָѧ����ʽ���ֱ��� */
void deal_input(string input)
{
    vector<string> vec;
    split(input, vec, '=');

    // ������벿��
    map_index = 0;
    deal_part(vec[0]);
    // �����Ұ벿��
    map_index = 1;
    deal_part(vec[1]);
}

/* ����expr+expr+expr */ 
void deal_part(string part)
{
    vector<string> vec;
    split(part, vec, '+');

    for(string& expr : vec)
    {
        deal_expr(expr);
    }
}

/* ����<expr> ::= <ceof><formula> */ 
void deal_expr(string expr)
{
	// ceof��Ϊ�մ������ 
    if(isdigit(expr[0]))
    {
        int ceof = 1;
        string formula;

        stringstream ss(expr);
        ss >> ceof;
        ss >> formula;

        deal_formula(ceof, formula);	// ceofΪϵ��ceof 
    }
	
	// ceofΪ�յ���� 
    else deal_formula(1, expr);		// ϵ��Ϊ1 
}

/* ����<formula> ::= <term><ceof> */ 
void deal_formula(int ceof, string formula)
{
    auto cur = formula.begin();

    while(cur != formula.end())
    {
        if(isupper(*cur))	// ��д��ĸ��˵���� <term> ::= <element><ceof> �����  
        {
        	// Ԫ��(��Ca) ��formula���е���ʼλ�ú���ֹλ�� 
            string::iterator element_begin = cur, element_end;

            if(cur + 1 != formula.end() && islower(*(cur+1)))	// ������Сд��ĸ 
                element_end = cur + 2;
            else element_end = cur + 1;
			 
            string element(element_begin, element_end);
			
			// ������term�ĺ�׺ceof 
            if(element_end == formula.end() || !isdigit(*element_end))
            {
                deal_term(ceof, element);	// Ԫ�صĸ���Ϊ��ϵ��ceof 
                cur = element_end;
            }
            // ���ں�׺ceof 
            else
            {
            	// ceof��λ�õ����� 
                string::iterator ceof_begin = element_end, ceof_end;
                for(ceof_end = ceof_begin + 1; ceof_end != formula.end(); ++ceof_end)
                {
                    if(!isdigit(*ceof_end)) break;
                }
                string ceof_str(ceof_begin, ceof_end);
                int ceof_int = atoi(ceof_str.c_str());
                deal_term(ceof * ceof_int, element);	// Ԫ�صĸ���Ϊ��ϵ��ceof * ��׺ceof 
                cur = ceof_end;
            }
        }
        else if(*cur == '(')	// �����ţ�˵���� <term> ::= (<formula>) ����� 
        {
        	// �µ�formula����ʼλ�ú���ֹλ�� 
            string::iterator form_begin = cur + 1, form_end;
            int bracket_count = 1;
            for(form_end = cur + 1; form_end != formula.end(); ++form_end)
            {
                if(*form_end == '(') ++bracket_count;
                if(*form_end == ')') --bracket_count;
                if(bracket_count == 0) break;
            }
            string form(form_begin, form_end); 
			
			// �����ں�׺ceof 
            if(form_end + 1 == formula.end() || !isdigit(*(form_end+1)))
            {
                deal_formula(ceof, form);
                cur = form_end + 1;
            }
            // ���ں�׺ceof 
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

/* �ж�������ϣmap�Ƿ���� */ 
bool isEqual(unordered_map<string, int>& src, unordered_map<string, int>& dst)
{
	// �жϴ�С 
    if(src.size() != dst.size()) return false;
    
	// ע��pairΪ<key, value>��Ԫ�飬keyΪpair.first��valueΪpair.second 
    for(auto pair : src)
    {
        auto it = dst.find(pair.first);		// ��dst��Ѱ�����key
        if(it == dst.end()) return false;	// û���ҵ�����map����� 
        if(it->second != pair.second) return false;		// �ҵ��ˣ�����value��һ����mapҲ����� 
    }
    return true;
}

int main()
{
    cin >> n;
    cin.get();	// ע��Ե���һ��ĩβ��'\n'��Ϊgetline��׼�� 

    for(int i=0; i<n; ++i)
    {
        mp[0].clear();			// ���map 
        mp[1].clear();
        getline(cin, input);	// ��ȡһ����ѧ����ʽ 
        deal_input(input); 
        cout << (isEqual(mp[0], mp[1]) ? 'Y' : 'N') << "\n";
    }

    return 0;
}

