#[골드3] 2252.줄세우기 https://www.acmicpc.net/problem/2252

import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(n+1)]
in_degree =[0]*(n+1)
for _ in range(m):
    a, b =map(int, sys.stdin.readline().split())
    graph[a].append(b)
    in_degree[b] += 1

q = deque()
for i in range(1, n+1):
    if in_degree[i] == 0:
        q.append(i)

answer = []
while q:
    first = q.popleft()
    answer.append(first)

    for neigh in graph[first]:
        in_degree[neigh]-=1
        if in_degree[neigh] == 0:
            q.append(neigh)

print(*answer)