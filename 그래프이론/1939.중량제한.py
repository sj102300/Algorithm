#[골드3] 1939.중량제한 https://www.acmicpc.net/problem/1939

import sys

n, m = map(int, sys.stdin.readline().split())
edges = [list(map(int, sys.stdin.readline().split())) for _ in range(m)]
start, dest = map(int, sys.stdin.readline().split())

edges.sort(key=lambda x: x[2], reverse=True)

parent = [i for i in range(n+1)]
visited = [False] * (n+1)

def find(a, parent):
    if a == parent[a]:
        return a
    parent[a] = find(parent[a], parent)
    return parent[a]

def union(a,b,parent):
    pa = find(a,parent)
    pb = find(b,parent)
    if(pa<pb):
        parent[pb] = pa
    else:
        parent[pa] = pb

for [v1, v2, weight] in edges:
    if find(v1, parent) != find(v2, parent):
        union(v1, v2, parent)
    if find(start, parent) == find(dest, parent):
        print(weight)
        break
