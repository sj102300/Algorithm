#[실버2] 18352.특정도시의거리찾기 https://www.acmicpc.net/problem/18352

#  도시의 개수 N, 도로의 개수 M, 거리 정보 K, 출발 도시의 번호 X

import sys
from collections import deque

n, m, k, x = map(int, sys.stdin.readline().split())

graph = []
for _ in range(n+1):
    graph.append([])
visited = [0] * (n + 1)

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    graph[a].append(b)

queue = deque()
queue.append(x)

while queue:
    v = queue.popleft()
    for i in graph[v]:
        if i == x:
            continue
        if visited[i] == 0:
            queue.append(i)
            visited[i] = visited[v] + 1

flag = 0
for i in range(1, n+1):
    if visited[i] == k:
        print(i)
        flag = 1

if flag == 0:
    print(-1)