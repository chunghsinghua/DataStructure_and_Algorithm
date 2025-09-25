#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    freopen("Q_3_5_5.in", "r", stdin);
    clock_t st, en;
    st = clock();
    int n;
    cin >> n;
    vector<int> p(n + 1), h(n + 1);
    h[0] = 2e9;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    ll tot = 0, idx;
    vector<pair<int, int>> r;
    r.push_back({2e9, 0});
    for (int i = 1; i <= n; ++i)
    {
        idx = distance(r.begin(), lower_bound(r.begin(), r.end(), make_pair(h[i] + p[i], i), greater())) - 1;
        tot += i - r[idx].second - 1;
        while (r.back().first <= h[i])
            r.pop_back();
        r.push_back({h[i], i});
    }
    cout << tot;
    en = clock();
    cout << endl
         << (float)(en - st) / CLOCKS_PER_SEC;
    return 0;
}
