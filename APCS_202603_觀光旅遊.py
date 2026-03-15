from heapq import *

n, m = map(int, input().split())
t = [int(x) for x in input().split()]
play = [tuple(map(int, input().split())) for _ in range(m)]
t.sort()
play.sort()
q = []
heapify(q)
j = 0
tot = 0
for x in t:
    while j < m and play[j][0] <= x:
        heappush(q, play[j][1])
        j += 1
    while len(q) > 0 and q[0] < x:
        heappop(q)
    tot += len(q)
print(tot)
