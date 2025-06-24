#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

int main()
{
    // freopen("P_7_12_3.in", "r", stdin);
    int m, n, k, dir;
    cin >> m >> n >> k;
    vector<string> mat(m);
    for (int i = 0; i < m; ++i)
        cin >> mat[i];
    int tot = 0;
    while (k--)
    {
        for (int idx = 0; idx < m; ++idx)
        {
            cin >> dir;
            dir %= n;
            if (dir > 0)
                mat[idx] = mat[idx].substr(n - dir, dir) + mat[idx].substr(0, n - dir);
            else if (dir < 0)
            {
                dir = -dir;
                mat[idx] = mat[idx].substr(dir, n - dir) + mat[idx].substr(0, dir);
            }
        }
        for (int i = 0; i < n; ++i)
        {
            vector<int> cnt(26, 0);
            for (int j = 0; j < m; ++j)
                cnt[mat[j][i] - 'a']++;
            tot += *max_element(cnt.begin(), cnt.end());
        }
    }
    cout << tot;
    return 0;
}
