m,n,k = map(int,input().split())
mat = [ input() for _ in range(m)]
tot = 0
while k > 0:
    d = [int(x)%n for x in input().split()]
    for i,idx in enumerate(d):
        mat[i] = mat[i][-idx:]+mat[i][:-idx]
    for i in range(n):
        cnt=[0]*26
        for j in range(m):
            cnt[ord(mat[j][i])-ord('a')] += 1
        tot += max(cnt)
    k -= 1
print(tot)
