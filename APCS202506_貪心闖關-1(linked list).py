from heapq import *

n, t = map(int, input().split())
vec = [int(x) for x in input().split()] + [t + 1]
pq = [(v, i) for i, v in enumerate(vec)]
inxt = list(range(1, n + 1))
heapify(pq)
score = 0
while pq:
    v, i = heappop(pq)
    if v > t:
        continue
    if v != vec[i]:
        continue
    nxt = inxt[i]
    while vec[nxt] == 0:
        nxt = inxt[nxt]
    inxt[i] = nxt
    score += v
    vec[nxt] += v
    vec[i] = 0
    if nxt < n and vec[nxt] <= t:
        heappush(pq, (vec[nxt], nxt))
print(score)
