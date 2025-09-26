#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("Q_3_5_5.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> vec(n + 1);
    stack<pair<int, int>> stk;
    for (int i = 0; i < n; ++i)
        cin >> vec[i].first >> vec[i].second;
    vec[n] = {l, 0};
    sort(vec.begin(), vec.end());
    ll tot = 0;
    stk.push({0, 0});
    for (auto e : vec)
    {
        while (stk.top().second > e.second)
        {
            tot += e.first;
            stk.pop();
        }
        tot -= stk.top().first;
        stk.push(e);
    }
    cout << tot;
    return 0;
}
