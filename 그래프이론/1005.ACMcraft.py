#[골드3] 1005.ACMcraft https://www.acmicpc.net/problem/1005

import sys 
from copy import deepcopy
from collections import deque

t = int(sys.stdin.readline())

for _ in range(t):
    n, k = map(int, sys.stdin.readline().split())
    time = [0] + list(map(int, sys.stdin.readline().split()))
    answer = []
    in_degree = [0] * (n+1)
    dp = [0] * (n+1)
    graph = [[] for _ in range(n+1)]
    for _ in range(k):
        x,y = map(int, sys.stdin.readline().split())
        graph[x].append(y)
        in_degree[y] += 1

    w = int(sys.stdin.readline())
    
    q = deque()
    for i in range(1, n+1):
        if in_degree[i] == 0:
            q.append(i)
            dp[i] = time[i]

    while q:
        first = q.popleft()

        for neigh in graph[first]:
            in_degree[neigh] -= 1
            dp[neigh] = max(dp[neigh], dp[first] + time[neigh])
            if in_degree[neigh] == 0:
                q.append(neigh)
    # print("answer: " + str(dp[w]))
    print(dp[w])
    