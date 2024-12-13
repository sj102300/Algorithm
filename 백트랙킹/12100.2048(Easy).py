#[골드1] 12100.2048(Easy) https://www.acmicpc.net/problem/12100

import sys
from copy import deepcopy

n = int(sys.stdin.readline())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

def move_by_line(tmp):

    result = []
    idx = 0
    while idx < len(tmp):
        if idx+1 < len(tmp) and tmp[idx] == tmp[idx+1]:
            result.append(tmp[idx] * 2)
            idx += 2
        else:
            result.append(tmp[idx])
            idx += 1
    return result

def move_board(cur):
    new_board = deepcopy(board)

    for dir in cur:
        if dir == 0:
            for i in range(n):
                tmp = []
                for j in range(n-1, -1, -1):
                    if new_board[i][j] != 0:
                        tmp.append(new_board[i][j])
                new_line = move_by_line(tmp)
                j = n-1
                front = 0
                while j >= 0:
                    new_board[i][j] = new_line[front] if front < len(new_line) else 0
                    j -= 1
                    front+=1

        elif dir == 1:
            for j in range(n):
                tmp = []
                for i in range(n-1, -1, -1):
                    if new_board[i][j] != 0:
                        tmp.append(new_board[i][j])
                new_line = move_by_line(tmp)
                i = n-1
                front = 0
                while i >= 0:
                    new_board[i][j] = new_line[front] if front <len(new_line) else 0
                    i -= 1
                    front+=1
        
        elif dir == 2:
            for i in range(n):
                tmp = []
                for j in range(n):
                    if new_board[i][j] != 0:
                        tmp.append(new_board[i][j])
                new_line = move_by_line(tmp)
                j = 0
                front = 0
                while j < n:
                    new_board[i][j] = new_line[front] if front<len(new_line) else 0
                    j += 1
                    front += 1
        elif dir == 3:
            for j in range(n):
                tmp = []
                for i in range(n):
                    if new_board[i][j] != 0:
                        tmp.append(new_board[i][j])
                new_line = move_by_line(tmp)
                i=0
                front=0
                while i<n:
                    new_board[i][j] = new_line[front] if front<len(new_line) else 0
                    i+=1
                    front+=1
    
    return max(max(row) for row in new_board)
                

answer = 0
def btrk(cur):
    if len(cur) == 5:
        global answer
        answer = max(move_board(cur), answer)
        return

    btrk(cur + [0])
    btrk(cur + [1])
    btrk(cur + [2])
    btrk(cur + [3])

btrk([])
print(answer)