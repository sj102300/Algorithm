#[골드1] 17472.다리만들기2 https://www.acmicpc.net/problem/17472

import sys
n, m = map(int, sys.stdin.readline().split())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

def markIsland(start, board, island_num, n, m):
    
    q = [start]
    front = 0
    board[start[0]][start[1]] = island_num

    while front < len(q):
        first = q[front]
        front+=1
        for dx, dy in ((1,0), (0,1), (0,-1), (-1, 0)):
            newX = first[0] + dx
            newY = first[1] + dy

            if newX < 0 or newY < 0  or newX >= n or newY >= m:
                continue
            if board[newX][newY] == 1:
                board[newX][newY] = island_num
                q.append((newX, newY))
    
    return q
        
def getIslands(board, n, m):

    islands = {}
    island_num = 10
    
    for i in range(n):
        for j in range(m):
            if board[i][j] == 1:
                islands[island_num] = markIsland((i, j), board, island_num, n, m)
                island_num+=1
            
    return islands

def getConnectInfo(first, second, board):

    minLen = 10000

    for (i, j) in first:
        for (a, b) in second:
            isConnected = True
            if i == a:
                if j > b:
                    for k in range(b+1, j):
                        if board[i][k] != 0:
                            isConnected = False
                            break
                else:
                    for k in range(j+1, b):
                        if board[i][k] != 0:
                            isConnected = False
                            break
                if isConnected and abs(j-b)-1 >= 2:
                    minLen = min(abs(j-b)-1, minLen)
                    
            if j == b:
                if i > a:
                    for k in range(a+1, i):
                        if board[k][j] != 0:
                            isConnected = False
                            break
                else:
                    for k in range(i+1, a):
                        if  board[k][j] != 0:
                            isConnected = False
                            break
                if isConnected and abs(a-i)-1 >= 2:
                    minLen = min(abs(a-i)-1, minLen)
    
    return minLen if minLen != 10000 else -1

def getEdges(board, n, m):

    islands = getIslands(board, n, m)
    edges = []

    for first, first_value in islands.items():
        for second, second_value in islands.items():
            if first >= second:
                continue
            bridge_len = getConnectInfo(first_value, second_value, board)
            if bridge_len != -1:
                edges.append((first-10, second-10, bridge_len))
            
    return (edges, len(islands))

def find(x, parent):
    if parent[x] == x:
        return x
    
    parent[x] = find(parent[x], parent)
    return parent[x]

def union(a, b, parent):
    pa = find(a, parent)
    pb = find(b, parent)

    if pa == pb:
        return False
    elif pa < pb:
        parent[pb] = pa
    else:
        parent[pa] = pb
    
    return True


def solution(board, n, m):

    edges, islands_cnt = getEdges(board, n, m)
    parent = [i for i in range(islands_cnt)]
    edges.sort(key=lambda x: x[2])

    answer = 0
    for a, b, cost in edges:
        if union(a, b, parent):
            answer += cost
    
    for i in range(1, islands_cnt):
        if find(i, parent) != 0:
            return -1
    
    return answer

print(solution(board, n, m))