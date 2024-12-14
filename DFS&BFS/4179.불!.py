#[골드3] 4179.불! https://www.acmicpc.net/problem/4179

import sys
from collections import deque

r, c = map(int, sys.stdin.readline().split())

board = [list(sys.stdin.readline().rstrip()) for _ in range(r)]


def solution(board, r, c):

    jq = []
    fq = []

    for i in range(r):
        for j in range(c):
            if board[i][j] == 'J':
                jq.append((i,j))
            elif board[i][j] == 'F':
                fq.append((i,j))

    time = 0
    
    next_fire = []
    next_jihoon = []

    while True:
        time += 1

        while fq:
            first_fire = fq.pop()

            for dx, dy in ((0,1), (1,0), (0,-1), (-1,0)):
                newX = first_fire[0] + dx
                newY = first_fire[1] + dy
                if newX < 0 or newY < 0 or newX >= r or newY >= c:
                    continue
                if board[newX][newY] == '.' or board[newX][newY] == 'J':
                    board[newX][newY] = 'F'
                    next_fire.append((newX, newY))
        
        fq, next_fire = next_fire, fq

        while jq:

            first_jihoon = jq.pop()

            for dx, dy in ((0,1), (1,0), (0,-1), (-1,0)):
                newX = first_jihoon[0] + dx
                newY = first_jihoon[1] + dy
                if newX < 0 or newY < 0 or newX >= r or newY >= c:
                    return time
                if board[newX][newY] == '.':
                    board[newX][newY] = 'J'
                    next_jihoon.append((newX, newY))
        
        if len(next_jihoon) == 0:
            return "IMPOSSIBLE"

        jq, next_jihoon = next_jihoon, jq

print(solution(board, r, c))