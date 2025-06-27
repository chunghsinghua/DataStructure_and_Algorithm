#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_7_2_4.in", "r", stdin);
    int n, t;
    cin >> n >> t;
    ll tot = 0;
    vector<ll> vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    stack<ll> stk;
    for (ll v : vec)
    {
        while (!stk.empty() && stk.top() <= v)
        {
            tot += stk.top();
            v += stk.top();
            stk.pop();
        }
        if (v <= t)
            stk.push(v);
    }
    while (!stk.empty())
    {
        tot += stk.top();
        stk.pop();
    }
    cout << tot;
    return 0;
}
