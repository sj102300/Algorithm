#[골드1] 18809.Gaaaaaaaaaarden https://www.acmicpc.net/problem/18809

import sys
from copy import deepcopy
from collections import deque

n, m, g, r = map(int, sys.stdin.readline().split())

#테두리 패딩 채워서 입력받기
garden = [[0] * (m + 2)]
for i in range(n):
    garden.append([0] + list(map(int, sys.stdin.readline().split())) + [0])
garden.append([0] * (m+2))

answer= 0

dx = [1,0,-1,0]
dy = [0,1,0,-1]
available_soil = []

def get_available_soil():

    for i in range(1, n+1):
        for j in range(1, m+1):
            if(garden[i][j] == 2):
                available_soil.append([i,j])

def diffuse_solution(cur_soil):
    global answer
    visited = [[0] * (m+2) for _ in range(n+2)]
    flower_num = 0

    queue = deque()

    for i in range(len(cur_soil)):
        if cur_soil[i] == 0 :
            continue
        x, y = available_soil[i]
        visited[x][y] = cur_soil[i]
        queue.append([x,y])
    
    while queue:
        first = queue.popleft()

        curTime = visited[first[0]][first[1]]
        if curTime == 25000:
            continue
        elif curTime < 0:
            curTime -= 1
        elif curTime > 0:
            curTime += 1

        for dir in range(4):
            newX = first[0] + dx[dir]
            newY = first[1] + dy[dir]
            if garden[newX][newY] == 0 or visited[newX][newY] == 25000:
                continue

            if visited[newX][newY] == -curTime:
                flower_num+=1
                visited[newX][newY] = 25000
            elif visited[newX][newY] == 0 and garden[newX][newY] != 0:
                visited[newX][newY] = curTime 
                queue.append([newX, newY])
                
    answer = max(flower_num, answer)
    return

def btrk(i, rcnt, gcnt, cur_soil):
    if(i == len(available_soil)):
        if(rcnt == r and gcnt == g):
            diffuse_solution(cur_soil)
        return
    
    btrk(i+1, rcnt+1, gcnt, cur_soil + [-1])
    btrk(i+1, rcnt, gcnt+1, cur_soil + [1])
    btrk(i+1, rcnt, gcnt, cur_soil + [0])

get_available_soil()
btrk(0, 0, 0, [])
print(answer)