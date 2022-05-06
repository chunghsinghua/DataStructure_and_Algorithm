#include <bits/stdc++.h>

using namespace std;

#define N 100005
typedef long long ll;

int dp[N], d[N];

int main()
{
    freopen("P_6_1_5.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> d[i];

    dp[0] = d[0];
    dp[1] = d[1];
    for (int i = 2; i < n; ++i)
        dp[i] = min(dp[i - 1], dp[i - 2]) + d[i];

    cout << dp[n - 1];
    return 0;
}
