#[실버4] 28215.대피소 https://www.acmicpc.net/problem/28215

import sys
from itertools import combinations

n, k = map(int, sys.stdin.readline().split())

houses = []

for _ in range(n):
    x,y = map(int, sys.stdin.readline().split())
    houses.append((x,y))

Inf = int(1e9)
answer = Inf

visited = [False] * n

#백트랙킹 사용
def btrk(cur):
    if len(cur) == k:
        global answer
        distance = [Inf] * n
        for idx in cur:
            tmp = houses[idx]
            for i in range(n):
                house = houses[i]
                distance[i] = min(distance[i], abs(tmp[0]- house[0]) + abs(tmp[1]-house[1]))
        
        answer = min(answer, max(distance))
        return

    for i in range(n):
        if not visited[i]:
            visited[i] = True
            btrk(cur + [i])
            visited[i] = False

btrk([])
print(answer)

# combination 함수 활용
# for comb in combinations(houses, k):

#     distance = [Inf] * n
#     for tmp in comb:
#         for i in range(n):
#             house = houses[i]
#             distance[i] = min(distance[i], abs(tmp[0]- house[0]) + abs(tmp[1]-house[1]))
    
#     answer = min(answer, max(distance))

# print(answer)