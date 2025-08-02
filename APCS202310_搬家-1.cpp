#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

bool east(char v)
{
    return (v == 'X' || v == 'H' || v == 'L' || v == 'F');
}
bool west(char v)
{
    return (v == 'X' || v == 'H' || v == '7' || v == 'J');
}
bool north(char v)
{
    return (v == 'X' || v == 'I' || v == 'L' || v == 'J');
}
bool south(char v)
{
    return (v == 'X' || v == 'I' || v == '7' || v == 'F');
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<string> mat(m);
    for (int i = 0; i < m; ++i)
        cin >> mat[i];
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    int mx = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (vis[i][j] || mat[i][j] == '0')
                continue;
            vector<pair<int, int>> que;
            que.push_back({i, j});
            vis[i][j] = true;
            int head = 0;
            while (head < que.size())
            {
                int r = que[head].first, c = que[head].second;
                head++;
                if (c + 1 < n && !vis[r][c + 1] && east(mat[r][c]) && west(mat[r][c + 1]))
                {
                    vis[r][c + 1] = true;
                    que.push_back({r, c + 1});
                }
                if (c - 1 >= 0 && !vis[r][c - 1] && west(mat[r][c]) && east(mat[r][c - 1]))
                {
                    vis[r][c - 1] = true;
                    que.push_back({r, c - 1});
                }
                if (r + 1 < m && !vis[r + 1][c] && south(mat[r][c]) && north(mat[r + 1][c]))
                {
                    vis[r + 1][c] = true;
                    que.push_back({r + 1, c});
                }
                if (r - 1 >= 0 && !vis[r - 1][c] && north(mat[r][c]) && south(mat[r - 1][c]))
                {
                    vis[r - 1][c] = true;
                    que.push_back({r - 1, c});
                }
            }
            mx = max(mx, (int)que.size());
        }
    }
    cout << mx;
    return 0;
}
