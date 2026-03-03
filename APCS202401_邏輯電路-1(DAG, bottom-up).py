p, q, r, m = map(int, input().split())
n = p + q + r
data = [0] + [int(x) for x in input().split()] + [0] * (q + r)
gate = [0] * (p + 1) + [int(x) for x in input().split()] + [0] * r
delay = [0] * (n + 1)
pred = [[] for _ in range(n + 1)]
succ = [[] for _ in range(n + 1)]
for _ in range(m):
    s, t = map(int, input().split())
    succ[s].append(t)
    pred[t].append(s)
indeg = [len(pred[x]) for x in range(n + 1)]
dag = list(range(1, p + 1))
head = 0
while head < len(dag):
    v = dag[head]
    head += 1
    for t in succ[v]:
        indeg[t] -= 1
        if indeg[t] == 0:
            dag.append(t)
for v in dag[p:]:
    if gate[v] == 1:
        data[v] = data[pred[v][0]] & data[pred[v][1]]
        delay[v] = max(delay[c] for c in pred[v]) + 1
    elif gate[v] == 2:
        data[v] = data[pred[v][0]] | data[pred[v][1]]
        delay[v] = max(delay[c] for c in pred[v]) + 1
    elif gate[v] == 3:
        data[v] = data[pred[v][0]] ^ data[pred[v][1]]
        delay[v] = max(delay[c] for c in pred[v]) + 1
    elif gate[v] == 4:
        data[v] = 1 - data[pred[v][0]]
        delay[v] = delay[pred[v][0]] + 1
    else:
        data[v] = data[pred[v][0]]
        delay[v] = delay[pred[v][0]]
print(max(delay))
print(*data[p + q + 1 :])
