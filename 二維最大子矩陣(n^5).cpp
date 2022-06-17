#include <bits/stdc++.h>

using namespace std;

#define N 210
typedef long long ll;

int d[N][N];

int main()
{
    freopen("Q_6_5_5.in", "r", stdin);
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> d[i][j];

    int mx = INT_MIN, t;
    for (int i1 = 1; i1 <= m; ++i1)
    {
        for (int j1 = 1; j1 <= n; ++j1)
        {
            for (int an = j1; an <= n; ++an)
            {
                t = 0;
                for (int i2 = i1; i2 <= m; ++i2)
                {
                    for (int j2 = j1; j2 <= an; ++j2)
                    {
                        t += d[i2][j2];
                    }
                    mx = max(mx, t);
                }
            }
        }
    }
    cout << mx;
    return 0;
}
