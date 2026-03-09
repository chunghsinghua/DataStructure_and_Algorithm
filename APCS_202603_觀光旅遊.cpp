#include <bits/stdc++.h>

using namespace std;

#define N 110
typedef long long ll;

int main()
{
    // freopen("P_6_21_3.in", "r", stdin);
    int m, n;
    cin >> n >> m;
    vector<int> t(n);
    for (int &e : t)
        cin >> e;
    vector<pair<int, int>> play(m);
    for (auto &[x, y] : play)
        cin >> x >> y;
    sort(t.begin(), t.end());
    sort(play.begin(), play.end());
    ll j = 0, tot = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int x : t)
    {
        while (j < m && play[j].first <= x)
        {
            q.push(play[j].second);
            j++;
        }
        while (!q.empty() && q.top() < x)
            q.pop();
        tot += q.size();
    }
    cout << tot;
    return 0;
}
