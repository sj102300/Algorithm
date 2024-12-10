#[골드5] 14719.빗물 https://www.acmicpc.net/problem/14719

import sys

h, w = map(int, sys.stdin.readline().split())

board = [[0] * w for _ in range(h)]

data =  list(map(int, sys.stdin.readline().split()))

for j in range(len(data)):
    height = data[j]
    for i in range(height):
        board[i][j] = 1

answer = 0
    
for i in range(h):
    left = -1
    for j in range(w):
        if board[i][j] == 1:
            if left != -1:
                answer += j-left-1
            left = j

print(answer)