#[플레5] 2887.행성터널 https://www.acmicpc.net/problem/2887

import sys

def find(a, parent):
    if a == parent[a]:
        return a

    pa = find(parent[a], parent)
    return pa

def union(a,b, parent):
    pa = find(a,parent)
    pb = find(b, parent)

    if pa == pb:
        return False
    elif pa < pb:
        parent[pb] = pa
    else:
        parent[pa] = pb
    
    return True

n = int(sys.stdin.readline())

x = []
y = []
z = []

for i in range(n):
    xt, yt, zt = map(int, sys.stdin.readline().split())
    x.append((i, xt))
    y.append((i, yt))
    z.append((i, zt))

edges = []

x.sort(key=lambda a: a[1])
y.sort(key=lambda a: a[1])
z.sort(key=lambda a: a[1])

for i in range(n-1):
    a,b = x[i], x[i+1]
    edges.append(((b[1] - a[1]), a[0], b[0]))
    a,b = y[i], y[i+1]
    edges.append(((b[1] - a[1]), a[0], b[0]))
    a,b = z[i], z[i+1]
    edges.append(((b[1] - a[1]), a[0], b[0]))

edges.sort(key=lambda a: a[0])

parent = [i for i in range(n)]
answer = 0
for distance, a, b in edges:
    if union(a,b, parent):
        answer+=distance

print(answer)