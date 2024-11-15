#[골드3] 1939.중량제한 https://www.acmicpc.net/problem/1939

import sys
from collections import deque

n,m = map(int, sys.stdin.readline().split())

graph = [[] for _ in range(n+1)]
maxWeight = 0
for i in range(m):
    v1,v2,weight = map(int, sys.stdin.readline().split())
    graph[v1].append([v2, weight])
    graph[v2].append([v1, weight])
    maxWeight = max(maxWeight, weight)

start, dest = map(int, sys.stdin.readline().split())

def bfs(graph, start, limitWeight, dest, n):
    
    visited = [False] * (n+1)
    queue = deque()
    queue.append(start)
    visited[start] = True
    
    while queue:
        first = queue.popleft()
        
        for [end, weight] in graph[first]:
            if not visited[end] and weight >= limitWeight:
                visited[end] = True
                queue.append(end)

    return visited[dest]


def solution(n,m,graph, start,dest):
    
    left = 0
    right = maxWeight
    availableWeight = 0
    mid = (left+right)//2

    while left <= right:
        mid = (left+right)//2
        
        if bfs(graph, start, mid, dest, n):
            availableWeight = mid
            left = mid + 1
        else:
            right = mid - 1
    
    return availableWeight


print(solution(n,m,graph,start,dest))