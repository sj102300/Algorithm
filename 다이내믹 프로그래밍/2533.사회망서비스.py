#[골드3] 2533.사회망서비스(SNS) https://www.acmicpc.net/problem/2533

import sys
sys.setrecursionlimit(10 ** 9)
n = int(sys.stdin.readline())

graph = [[] for _ in range(n+1)]

for _ in range(n-1):
    a,b = map(int, sys.stdin.readline().split())
    graph[a].append(b)
    graph[b].append(a)

def DFS(start, graph, visited):
    
    visited[start] = 1
    for child in graph[start]:
        if visited[child] == 0:
            DFS(child, graph, visited)
            dp[start][0] += dp[child][1]
            dp[start][1] += min(dp[child][0], dp[child][1])

dp = [[0,1] for _ in range(n+1)]
visited =[0] * (n+1)

DFS(1, graph, visited)
print(min(dp[1][0], dp[1][1]))