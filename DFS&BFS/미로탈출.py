import sys

n, m = map(int, sys.stdin.readline().split())
data = [list(map(int, sys.stdin.readline().rstrip())) for _ in range(n)]

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def DFS(data, x, y):
    if data[x][y] == 1:
        return False
    data[x][y] = 1
    for i in range(4):
        if x+dx[i] < 0 or x+dx[i] > n-1 or y+dy[i]<0 or y+dy[i]>m-1:
            continue
        if data[x+dx[i]][y+dy[i]] == 0:
            DFS(data, x+dx[i], y+dy[i])
    return True

cnt = 0
for i in range(n):
    for j in range(m):
        if DFS(data, i, j):
            cnt += 1

print(cnt)