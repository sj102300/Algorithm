#[골드5] 15686.치킨배달 https://www.acmicpc.net/problem/15686

import sys
from itertools import combinations

n, m = map(int, sys.stdin.readline().split())

city = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
chickens = []
houses= []

for i in range(n):
    for j in range(n):
        if city[i][j] == 1:
            houses.append((i,j))
        elif city[i][j] == 2:
            chickens.append((i,j))

answer = 10000
for comb in combinations(chickens, m):
    distance = [10000] * len(houses)
    for i, j in comb:
        for k in range(len(houses)):
            a,b = houses[k]
            distance[k] = min(abs(i-a) + abs(j-b), distance[k])
    answer = min(answer, sum(distance))

print(answer)