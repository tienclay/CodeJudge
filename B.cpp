#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int base = 31;
const ll MOD = 1000000003;
const ll maxn = 1000111;
ll g(string s)
{
    ll hashP = 0;
    s = " " + s;
    for (int i = 1; i < s.length(); i++)
        hashP = (hashP * base + s[i] - 'a' + 1) % MOD;
    return hashP;
}
void solve()
{
    int n;
    string s;
    cin >> n >> s;

    int a[10001];
    for (int i = 0; i < 10001; i++)
        a[i] = 0;
    ll pre = -1;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (pre != g(s.substr(i, 2)))
        {
            a[g(s.substr(i, 2))]++;
            pre = g(s.substr(i, 2));
        }
        else
        {
            pre = -1;
        }
    }
    for (int i = 0; i < 10001; i++)
    {
        if (a[i] >= 2)
        {

            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}