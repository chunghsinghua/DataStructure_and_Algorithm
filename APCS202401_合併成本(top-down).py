def cost(le, ri):
    if dp[le][ri]>=0:
        return dp[le][ri]
    tot = sum(vec[le:ri+1])
    imin = 1001*100
    lsum = 0
    for i in range(le, ri):
        lsum += vec[i]
        tmp = cost(le,i) + cost(i+1,ri)+abs(tot-lsum-lsum)
        imin = min(tmp,imin)
    dp[le][ri] = imin
    return dp[le][ri]


n =int(input())
vec = [int(x) for x in input().split()]
dp = [[-1]*n for _ in range(n)]
for i in range(n):
    dp[i][i]=0
print(cost(0,n-1))
