import sys
import copy
from itertools import combinations

n, m = map(int, sys.stdin.readline().split())
data = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

def checkSafeZone(target):
    cnt = 0
    for i in range(n):
        for j in range(m):
            if target[i][j] == 0:
                cnt+=1
    return cnt

# 벽을 세워보면서 checksafezone 확인
# 근데 벽을 어디에 세울까? -> 바이러스랑 가까운 곳부터 / 이걸 어케 검사함 그냥 하나씩 만들자
# 벽 3개를 세우는 모든 경우의수를 찾아서 리스트에 넣고 그거에 대해서 바이러스 퍼지게 하고 그다음 안전구역 검사
#바이러스가 퍼지는 방식은 DFS

dx = [1,0,-1,0]
dy = [0,1,0,-1]

def DFS(target, i, j):
    for a in range(4):
        x = i + dx[a]
        y = j + dy[a]
        if x < 0 or x > n-1 or y < 0 or y > m-1:
            continue
        if target[x][y] == 0:
            target[x][y] = 2
            DFS(target, x, y)
        

def diffuseViruse(changed):
    for i in range(n):
        for j in range(m):
            if changed[i][j] == 2:
                DFS(changed, i, j)

empty = []
for i in range(n):
    for j in range(m):
        if data[i][j] == 0:
            empty.append((i,j))

maxSafeZone = 0
#벽 3개를 세우는 모든 경우의수 / 중복 조합
for k in combinations(empty, 3):
    changed = copy.deepcopy(data)
    #벽 세개 세우기
    for l in k:
        x, y = l
        changed[x][y] = 1
    diffuseViruse(changed)
    safeZones = checkSafeZone(changed)
    if safeZones > maxSafeZone:
        maxSafeZone = safeZones

print(maxSafeZone)