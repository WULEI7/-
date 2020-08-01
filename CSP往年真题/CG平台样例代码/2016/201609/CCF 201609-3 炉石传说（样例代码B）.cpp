#include <bits/stdc++.h>
using namespace std;
#define IOFast() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
struct Entourage
{
    int H, A;
};
struct Player
{
    int HP, entourages_cnt;
    Entourage entourages[8];
    void init()
    {
        HP = 30;
        entourages_cnt = 0;
    }
    void summon(int p, int a, int h)
    {
        p--;
        for (register int i = entourages_cnt - 1; i >= p; i--)
        {
            entourages[i + 1].A = entourages[i].A;
            entourages[i + 1].H = entourages[i].H;
        }
        entourages[p].A = a;
        entourages[p].H = h;
        entourages_cnt++;
    }
    int getDamage(int who)
    {
        if (who == 0)
            return 0;
        return entourages[who - 1].A;
    }
    void takeHP(int who, int damage)
    {
        if (who == 0)
        {
            HP -= damage;
            return;
        }
        entourages[who - 1].H -= damage;
        if (entourages[who - 1].H < 1)
        {
            for (register int i = who; i < entourages_cnt; i++)
            {
                entourages[i - 1].A = entourages[i].A;
                entourages[i - 1].H = entourages[i].H;
            }
            entourages[entourages_cnt].A = 0;
            entourages[entourages_cnt].H = 0;
            entourages_cnt--;
        }
    }
    void showInfo()
    {
        cout << HP << "\n";
        cout << entourages_cnt;
        for (register int i = 0; i < entourages_cnt; i++)
            cout << " " << entourages[i].H;
        cout << "\n";
    }
} players[2];
int n, position, attack, health, attacker, defender, player, tmp1, tmp2;
string op;
int main()
{
    IOFast();
    players[0].init();
    players[1].init();
    cin >> n;
    cin.get();
    while (n--)
    {
        cin >> op;
        if (op == "summon")
        {
            cin >> position >> attack >> health;
            players[player].summon(position, attack, health);
            continue;
        }
        if (op == "attack")
        {
            cin >> attacker >> defender;
            tmp1 = players[player].getDamage(attacker);
            tmp2 = players[(player + 1) & 1].getDamage(defender);
            players[player].takeHP(attacker, tmp2);
            players[(player + 1) & 1].takeHP(defender, tmp1);
            continue;
        }
        player = (player + 1) & 1;
    }
    if (players[0].HP < 1)
        cout << "-1\n";
    else if (players[1].HP < 1)
        cout << "1\n";
    else
        cout << "0\n";
    players[0].showInfo();
    players[1].showInfo();
    return 0;
}

