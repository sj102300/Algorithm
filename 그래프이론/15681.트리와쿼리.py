#[골드5] 15681.트리와쿼리 https://www.acmicpc.net/problem/15681

import sys
sys.setrecursionlimit(10**6)
n,r,q = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(n+1)]
for _ in range(n-1):
    u,v = map(int, sys.stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)

visited = [False] * (n+1)
size = [1] * (n+1)

def make_tree(cur, graph, visited, size):
    
    visited[cur] = True

    for child in graph[cur]:
        if not visited[child]:
            make_tree(child, graph, visited, size)
            size[cur] += size[child]

make_tree(r, graph, visited, size)

for _ in range(q):
    target = int(sys.stdin.readline())
    print(size[target])