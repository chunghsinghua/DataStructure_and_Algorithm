#include <bits/stdc++.h>
using namespace std;

#define N 10000000
typedef long long ll;
const int n = 6;

typedef struct
{
    int weight, parent, lchild, rchild;
    char value;
} HNodeType;

typedef struct
{
    int bit[n];
    int start;
} HCodeType;

int main()
{
    // freopen("q_1_8_5.in", "r", stdin);
    vector<HNodeType> huffnode(n);
    for (int i = 0; i < n; ++i)
    {
        huffnode[i].value = char(i + 'a');
        huffnode[i].lchild = huffnode[i].rchild = huffnode[i].parent = -1;
    }
    huffnode[0].weight = 5;
    huffnode[1].weight = 32;
    huffnode[2].weight = 18;
    huffnode[3].weight = 7;
    huffnode[4].weight = 25;
    huffnode[5].weight = 13;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // weight,idx;
    for (auto e : huffnode)
        pq.push({e.weight, (int)(e.value - 'a')});

    while (pq.size() > 1)
    {
        int idx = huffnode.size();
        int w1 = pq.top().first, idx1 = pq.top().second;
        pq.pop();
        int w2 = pq.top().first, idx2 = pq.top().second;
        pq.pop();
        HNodeType tmp;
        tmp.value = idx;
        tmp.lchild = idx1;
        tmp.rchild = idx2;
        tmp.weight = w1 + w2;
        tmp.parent = -1;
        huffnode[idx1].parent = idx;
        huffnode[idx2].parent = idx;
        pq.push({tmp.weight, idx});
        huffnode.push_back(tmp);
    }
    // coding
    vector<HCodeType> huffcode(n);
    for (int i = 0; i < n; ++i)
    {
        HCodeType tmp;
        tmp.start = n - 1;
        int c = i;
        int p = huffnode[c].parent;
        while (p != -1)
        {
            if (huffnode[p].lchild == c)
                tmp.bit[tmp.start--] = 0;
            else
                tmp.bit[tmp.start--] = 1;

            c = p;
            p = huffnode[p].parent;
        }

        for (int j = tmp.start + 1; j < n; ++j)
            huffcode[i].bit[j] = tmp.bit[j];
        huffcode[i].start = tmp.start + 1;
    }

    // output
    cout << endl;

    for (int i = 0; i < n; ++i)
    {

        cout << huffnode[i].value << " : ";

        for (int j = huffcode[i].start; j < n; ++j)
            cout << huffcode[i].bit[j];
        cout << endl;
    }
    return 0;
}
