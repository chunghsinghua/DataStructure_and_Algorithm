#include <bits/stdc++.h>

using namespace std;

#define N 50010
typedef long long ll;

void fun(int v, vector<vector<int>> &pre, vector<int> &data, vector<int> &gate, vector<int> &delay)
{
    if (data[v] >= 0)
        return;
    fun(pre[v][0], pre, data, gate, delay);
    if (gate[v] == 4)
    {
        data[v] = 1 - data[pre[v][0]];
        delay[v] = delay[pre[v][0]] + 1;
        return;
    }
    fun(pre[v][1], pre, data, gate, delay);
    if (gate[v] == 1)
    {
        data[v] = data[pre[v][0]] & data[pre[v][1]];
        delay[v] = max(delay[pre[v][0]], delay[pre[v][1]]) + 1;
    }
    else if (gate[v] == 2)
    {
        data[v] = data[pre[v][0]] | data[pre[v][1]];
        delay[v] = max(delay[pre[v][0]], delay[pre[v][1]]) + 1;
    }
    else if (gate[v] == 3)
    {
        data[v] = data[pre[v][0]] ^ data[pre[v][1]];
        delay[v] = max(delay[pre[v][0]], delay[pre[v][1]]) + 1;
    }
    return;
}
int main()
{
    // freopen("Q_1_2_1.in", "r", stdin);
    string s;
    getline(cin, s);
    string pattern = " ";
    int start = 0, end = s.find(pattern);
    vector<string> ret;
    while (end != string::npos)
    {
        ret.push_back(s.substr(start, end - start));
        start = end + pattern.size();
        end = s.find(pattern, start);
    }
    if (start != s.size())
        ret.push_back(s.substr(start));
    stack<int> stk;
    reverse(ret.begin(), ret.end());
    for (string e : ret)
    {
        if (e == "f")
        {
            int x = stk.top();
            stk.pop();
            stk.push(2 * x - 3);
        }
        else if (e == "g")
        {
            int x = stk.top();
            stk.pop();
            int y = stk.top();
            stk.pop();
            stk.push(2 * x + y - 7);
        }
        else if (e == "h")
        {
            int x = stk.top();
            stk.pop();
            int y = stk.top();
            stk.pop();
            int z = stk.top();
            stk.pop();
            stk.push(3 * x - 2 * y + z);
        }
        else
            stk.push(stoi(e));
    }
    cout << stk.top();
    return 0;
}
