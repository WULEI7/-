#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
using namespace std;
struct Cron{
    int minute[60];
    int hour[24];
    int monthday[32];
    int month[13];
    int weekday[7];
}cron[25];
char task[25][105];
const string m[] = {"", "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
int get_month(char s[]){
	for(int i = 0; i < 3; ++i)
		s[i] = tolower(s[i]);
	for(int i = 1; i <= 12; ++i){
		int flag = 1;
		for(int j = 0; j < 3; ++j){
			if(s[j] != m[i][j]){
				flag = 0;
				break;
			}
		}
		if(flag)
			return i;
	}
}
const string w[] = {"sun", "mon", "tue", "wed", "thu", "fri", "sat"};
int get_week(char s[]){
	for(int i = 0; i < 3; ++i)
		s[i] = tolower(s[i]);
	for(int i = 0; i < 7; ++i){
		int flag = 1;
		for(int j = 0; j < 3; ++j){
			if(s[j] != w[i][j]){
				flag = 0;
				break;
			}
		}
		if(flag)
			return i;
	}
}
bool lunar(int x){
    return (x % 4 == 0 && x % 100 != 0) || x % 400 == 0;
}
int Monthday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int get_weekday(int year, int month, int monthday){
    int tot = 3 + monthday;
    for(int i = 1970; i < year; ++i){
        if(lunar(i))
        	tot += 366;
        else
       	    tot += 365;
    }
    for(int i = 1; i < month; ++i){
        if(lunar(year) && i == 2)
			tot += 29;
        else
            tot += Monthday[i];
    }
    return tot % 7;
}
struct ans{
    ll time;
    int tid;
    ans(ll t, int c){
        time = t;
        tid = c;
    }
    bool operator < (const ans &x) const{
        if (x.time == time)
            return x.tid < tid;
        return x.time < time;
    }
};
char temp[105];
void solve_minute(int i){
	cin >> temp;
	for(int j = 0, pre = -1, tmp = 0; ; ++j){
        if(temp[j] == '*'){
            for(int k = 0; k < 60; ++k)
                cron[i].minute[k] = 1;
            break;
        }
        else if(isdigit(temp[j])){
            tmp = tmp * 10 + temp[j] - '0';
        }
        else if(temp[j] == ','){
            if(pre == -1){
                cron[i].minute[tmp] = 1;
                tmp = 0;
            }
            else{
                for(int k = pre; k <= tmp; ++k)
                    cron[i].minute[k] = 1;
                pre = -1;
                tmp = 0;
            }
        }
        else if(temp[j] == '-'){
            pre = tmp;
            tmp = 0;
        }
        else{
            if(pre == -1){
                cron[i].minute[tmp] = 1;
            }
            else{
                for(int k = pre; k <= tmp; ++k)
                    cron[i].minute[k] = 1;
            }
            break;
    	}
	}
}
void solve_hour(int i){
	cin >> temp;
	for(int j = 0, pre = -1, tmp = 0; ; ++j){
        if(temp[j] == '*'){
            for(int k = 0; k <= 23; ++k)
                cron[i].hour[k] = 1;
            break;
        }
        else if(isdigit(temp[j])){
            tmp = tmp * 10 + temp[j] - '0';
        }
        else if(temp[j] == ','){
            if(pre == -1){
                cron[i].hour[tmp] = 1;
                tmp = 0;
            }
            else{
                for(int k = pre; k <= tmp; ++k)
                    cron[i].hour[k] = 1;
                pre = -1;
                tmp = 0;
            }
        }
        else if(temp[j] == '-'){
            pre = tmp;
            tmp = 0;
        }
        else{
        	if(pre == -1){
                cron[i].hour[tmp] = 1;
            }
            else{
                for(int k = pre; k <= tmp; ++k)
                    cron[i].hour[k] = 1;
            }
            break;
        }
    }
}
void solve_monthday(int i){
	cin >> temp;
	for(int j = 0, pre = -1, tmp = 0; ; ++j){
        if(temp[j] == '*'){
            for(int k = 1; k <= 31; ++k)
                cron[i].monthday[k] = 1;
            break;
        }
        else if(isdigit(temp[j])){
            tmp = tmp * 10 + temp[j] - '0';
        }
        else if(temp[j] == ','){
            if(pre == -1){
                cron[i].monthday[tmp] = 1;
                tmp = 0;
            }
            else{
                for(int k = pre; k <= tmp; ++k)
                    cron[i].monthday[k] = 1;
                pre = -1;
                tmp = 0;
            }
        }
        else if(temp[j] == '-'){
            pre = tmp;
            tmp = 0;
        }
        else{
            if(pre == -1){
                cron[i].monthday[tmp] = 1;
            }
            else{
                for(int k = pre; k <= tmp; ++k)
                    cron[i].monthday[k] = 1;
            }
            break;
        }
    }
}
void solve_month(int i){
	cin >> temp;
    for(int j = 0, pre = -1, tmp = 0; ; ++j){
        if(temp[j] == '*'){
            for(int k = 1; k <= 12; ++k)
                cron[i].month[k] = 1;
            break;
        }
        else if(isdigit(temp[j])){
            tmp = tmp * 10 + temp[j] - '0';
        }
        else if(isalpha(temp[j])){
            char Mon[5];
            Mon[0] = temp[j];
          	Mon[1] = temp[j+1];
            Mon[2] = temp[j+2];
            Mon[3] = '\0';
            tmp = get_month(Mon);
            j += 2;
        }
        else if(temp[j] == ','){
            if(pre == -1){
                cron[i].month[tmp] = 1;
                tmp = 0;
            }
            else{
                for(int k = pre; k <= tmp; ++k)
                    cron[i].month[k] = 1;
                pre = -1;
                tmp = 0;
            }
        }
        else if(temp[j] == '-'){
            pre = tmp;
            tmp = 0;
        }
        else{
            if(pre == -1){
                cron[i].month[tmp] = 1;
            }
            else{
                for(int k = pre; k <= tmp; ++k)
                    cron[i].month[k] = 1;
            }
            break;
        }
    }
}
void solve_weekday(int i){
	cin >> temp;
    for(int j = 0, pre = -1, tmp = 0; ; ++j){
        if(temp[j] == '*'){
            for(int k = 0; k <= 6; ++k)
                cron[i].weekday[k] = 1;
            break;
        }
        else if(isdigit(temp[j])){
            tmp = tmp * 10 + temp[j] - '0';
        }
        else if(isalpha(temp[j])){
            char Week[5];
            Week[0] = temp[j];
            Week[1] = temp[j+1];
            Week[2] = temp[j+2];
            Week[3] = '\0';
            tmp = get_week(Week);
            j += 2;
        }
        else if(temp[j] == ','){
            if(pre == -1){
                cron[i].weekday[tmp] = 1;
                tmp = 0;
            }
            else{
                for(int k = pre; k <= tmp; ++k)
                    cron[i].weekday[k] = 1;
                pre = -1;
                tmp = 0;
            }
        }
        else if(temp[j] == '-'){
            pre = tmp;
            tmp = 0;
        }
		else{
            if(pre == -1){
                cron[i].weekday[tmp] = 1;
            }
            else{
                for(int k = pre; k <= tmp; ++k)
                    cron[i].weekday[k] = 1;
            }
            break;
        }
    }
}
int main()
{
	fast;
    int n;
    ll s, t;
    cin >> n >> s >> t;
    for (int i = 1; i <= n; ++i)
    {
    	solve_minute(i);
    	solve_hour(i);
    	solve_monthday(i);
    	solve_month(i);
    	solve_weekday(i);
        cin >> task[i];
    }
    priority_queue<ans> q;
    int st = s / 100000000, ed = t / 100000000;
    for(int i = 1; i <= n; ++i){
        for(int year = st; year <= ed; ++year){
            for(int month = 1; month <= 12; ++month){
                if(cron[i].month[month]){
                    for(int monthday = 1; monthday <= ((lunar(year) && month == 2) ? 29 : Monthday[month]); ++monthday){
                        if(cron[i].monthday[monthday] && cron[i].weekday[get_weekday(year, month, monthday)]){
                            for(int hour = 0; hour < 24; ++hour){
                                if(cron[i].hour[hour]){
                                    for(int minute = 0; minute < 60; ++minute){
                                        if(cron[i].minute[minute]){
                                            ll time = 1ll * year * 100000000 + 1ll * month * 1000000 + 1ll * monthday * 10000 + 1ll * hour * 100 + 1ll * minute;
                                            if(time >= s && time < t){
                                                q.push(ans(time, i));
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    while(!q.empty()){
        ans a = q.top(); 
		q.pop();
		cout << a.time << " " << task[a.tid] <<"\n";
    }
    return 0;
}


