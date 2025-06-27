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
    vector<ll> vec(n + 2);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<int> inext(n + 2), iprev(n + 2);
    for (int i = 1; i <= n; ++i)
        inext[i] = i + 1;
    for (int i = 1; i <= n; ++i)
        iprev[i] = i - 1;
    for (int i = 1; i <= n; ++i)
    {
        cin >> vec[i];
        if (vec[i] <= t)
            pq.push({vec[i], i});
    }
    vec[n + 1] = 1;
    while (!pq.empty())
    {
        ll val = pq.top().first, idx = pq.top().second;
        pq.pop();
        if (val != vec[idx])
            continue;
        tot += val;
        vec[idx] = 0;
        inext[iprev[idx]] = inext[idx];
        iprev[inext[idx]] = iprev[idx];
        int i = inext[idx];
        if (i <= n)
        {
            vec[i] += val;
            if (vec[i] <= t)
                pq.push({vec[i], i});
        }
    }
    cout << tot;
    return 0;
}
