#[골드2] 17822.원판돌리기 https://www.acmicpc.net/problem/17822 

import sys
from collections import deque

n, m, t = map(int, sys.stdin.readline().split())

board = [[]] + [list(map(int, sys.stdin.readline().split())) for _ in range(n)] 

def rotate_board(i, d, board, k):

    if d == 0:
        m = len(board[i])
        board[i] = board[i][m-k:] + board[i][:m-k]
    elif d == 1:
        board[i] = board[i][k:] + board[i][:k]

def BFS(start, board, visited):

    q = []
    front = 0
    q.append(start)
    visited[start[0]][start[1]] = True

    while front < len(q):
        first = q[front]
        front += 1

        for dx, dy in ((0,1), (1,0), (0,-1), (-1,0)):
            newX = first[0] + dx
            newY = (first[1] + dy) % len(board[1])
            if newX < 1 or newX >= n+1:
                continue
            if board[newX][newY] == board[start[0]][start[1]] and not visited[newX][newY]:
                visited[newX][newY] = True
                q.append((newX,newY))
        
    return q

def get_average(board, n, m):

    result = 0
    cnt = 0
    for i in range(1, n+1):
        for j in range(m):
            if board[i][j] != 0:
                result += board[i][j]
                cnt+=1

    return result / cnt if cnt != 0 else -1


def solution(n, m, board):
    for _ in range(t):
        x, d, k = map(int, sys.stdin.readline().split())

        for xi in range(x, n+1, x):
            rotate_board(xi, d, board, k)
            
        visited = [[]] + [[False] * m for _ in range(n)]

        deleted_cnt = 0
        is_deleted = False
        for i in range(1, n+1):
            for j in range(m):
                if not visited[i][j]:
                    adjacent = BFS((i,j), board, visited)
                    if len(adjacent) != 1 and board[i][j] != 0:
                        for a, b in adjacent:
                            board[a][b] = 0
                        is_deleted = True
                        deleted_cnt += len(adjacent)
        
        if not is_deleted:
            avg = get_average(board, n, m)
            if avg == -1:
                return 0
            for i in range(1, n+1):
                for j in range(m):
                    if board[i][j] != 0:
                        if board[i][j] < avg:
                            board[i][j] += 1
                        elif board[i][j] > avg:
                            board[i][j] -= 1

    return sum([sum(board[i]) for i in range(1, n+1)])

print(solution(n,m,board))