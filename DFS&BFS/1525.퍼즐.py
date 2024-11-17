#[골드2] 1525.퍼즐 https://www.acmicpc.net/problem/1525

import sys
from collections import deque

puzzle = ""

for _ in range(3):
    puzzle += "".join(sys.stdin.readline().split())

def bfs(puzzle):
    visited = {puzzle: 0}

    queue = deque([puzzle])

    dx = [1,0,-1,0]
    dy = [0,1,0,-1]

    while queue:
        first = queue.popleft()

        if first == "123456780":
            return visited[first]

        empty = first.index('0')
        for i in range(4):
            newX = empty // 3 + dx[i]
            newY = empty % 3 + dy[i]
            if newX < 0 or newX >= 3 or newY < 0 or newY >= 3:
                continue
            firstToList = list(first)
            firstToList[empty], firstToList[newX * 3 + newY] = firstToList[newX * 3 + newY], firstToList[empty]
            newPuzzle = "".join(firstToList)
            if not newPuzzle in visited or visited[newPuzzle] > visited[first] + 1:
                visited[newPuzzle] = visited[first] + 1
                queue.append(newPuzzle)
    
    return -1

print(bfs(puzzle))