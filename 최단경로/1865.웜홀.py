#[골드3] 1865.웜홀 https://www.acmicpc.net/problem/1865

import sys

def bellman_ford(start, graph):
    distance = [Inf] * (n+1)
    distance[start] = 0
    
    for round in range(1, n+1):
        for cur in range(1, n+1):
            for neigh, time in graph[cur]:
                if distance[neigh] > distance[cur] + time:
                    distance[neigh] = distance[cur] + time
                    if round == n:
                        return "YES" #음의 사이클을 만들었음
                
    return "NO"

tc = int(sys.stdin.readline())

Inf = int(1e9)

for _ in range(tc):
    n, m, w = map(int, sys.stdin.readline().split())
    graph = [[] for _ in range(n+1)]
    for _ in range(m):
        s, e, t = map(int, sys.stdin.readline().split())
        graph[s].append([e,t])
        graph[e].append([s,t])
    for _ in range(w):
        s, e, t = map(int, sys.stdin.readline().split())
        graph[s].append([e, -t])
    
    print(bellman_ford(1, graph))