#[골드4] 11657.타임머신 https://www.acmicpc.net/problem/11657

import sys

n, m = map(int, sys.stdin.readline().split())
edges = [tuple(map(int, sys.stdin.readline().split())) for _ in range(m)]

Inf = int(1e9)
distance = [Inf] * (n + 1)

def bellmanFord(start):
    global distance
    distance[start] = 0

    for i in range(n):
        for j in range(m):
            s, e, cost = edges[j]
            if distance[s] != Inf and distance[s] + cost < distance[e]:
                if i == n-1:
                    return False
                distance[e] = distance[s] + cost

    return True

def solution(n, m, edges):

    if bellmanFord(1):
        for i in range(2, n + 1):
            if distance[i] != Inf:
                print(distance[i])
            else:
                print(-1)
    else:
        print(-1)

solution(n,m,edges)