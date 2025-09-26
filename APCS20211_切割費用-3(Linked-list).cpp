#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("Q_3_5_5.in", "r", stdin);
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> vec(n + 2);
    vector<int> le(n + 1), ri(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> vec[i].first >> vec[i].second;
    vec[0] = {0, 0}, vec[n + 1] = {l, 0};
    sort(vec.begin(), vec.end());
    vector<int> seq(n);
    ll tot = 0;
    for (int i = 1; i <= n; ++i)
    {
        seq[vec[i].second - 1] = i;
        le[i] = i - 1;
        ri[i] = i + 1;
    }
    int idx, lp, rp;
    for (int i = n - 1; i >= 0; --i)
    {
        idx = seq[i];
        lp = le[idx], rp = ri[idx];
        tot += vec[rp].first - vec[lp].first;
        ri[lp] = ri[idx];
        le[rp] = le[idx];
    }
    cout << tot;
    return 0;
}
