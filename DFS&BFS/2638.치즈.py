#[골드3] 2638.치즈 https://www.acmicpc.net/problem/2638

import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
map = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

def fillOutline(map, n, m, flag):

    queue = deque([[0,0]])

    dx = [1,0,-1,0]
    dy = [0,1,0,-1]

    newFlag = flag + 1

    map[0][0] = newFlag

    while queue:
        first = queue.popleft()

        for i in range(4):
            newX = first[0] + dx[i]
            newY = first[1] + dy[i]
            if newX < 0 or newY < 0 or newX >= n or newY >= m:
                continue
            if map[newX][newY] == 0 or map[newX][newY] == flag :
                map[newX][newY] = newFlag
                queue.append([newX, newY])

def solution(map, n, m):

    outLineNum = 2

    dx = [1,0,-1,0]
    dy = [0,1,0,-1]

    time = 0

    while True:
        fillOutline(map, n,m, outLineNum)
        outLineNum += 1
        meltedCheese = []
        for i in range(1, n-1):  #테두리는 볼필요없음
            for j in range(1, m-1):
                if (map[i][j] == 1):
                    outlineNeighborNum = 0
                    for dir in range(4):
                        newX = i + dx[dir]
                        newY = j + dy[dir]
                        if map[newX][newY] == outLineNum:
                            outlineNeighborNum += 1
                    if outlineNeighborNum >= 2:
                        meltedCheese.append([i,j])

        if len(meltedCheese) == 0:
            break

        time += 1 
        for [x,y] in meltedCheese:
            map[x][y] = outLineNum

    return time

print(solution(map, n, m))