#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("Q_3_5_5.in", "r", stdin);
    int n, l, ord, pos;
    cin >> n >> l;
    set<int> ss({0, l});
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> pos >> ord;
        vec[ord] = pos;
    }
    ll tot = 0;
    for (int i = 1; i <= n; ++i)
    {
        ss.insert(vec[i]);
        auto it = ss.find(vec[i]);
        tot += *next(it) - *prev(it);
    }
    cout << tot;

    return 0;
}
