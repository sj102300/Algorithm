import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
data = [list(map(int, sys.stdin.readline().rstrip())) for _ in range(n)]

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

queue = deque()

queue.append((0,0))

while queue:
    i, j = queue.popleft()
    for k in range(4):
        x = i + dx[k]
        y = j + dy[k]
        if x < 0 or y < 0 or x > n-1 or y > m-1:
            continue
        if data[x][y] == 0:
            continue
        if data[x][y] == 1:
            queue.append((x,y))
            data[x][y] = data[i][j] + 1

print(data[n-1][m-1])