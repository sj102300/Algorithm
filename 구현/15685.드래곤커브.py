#[골드3] 15685.드래곤커브 https://www.acmicpc.net/problem/15685

import sys

n = int(sys.stdin.readline())

rotation = {
    (1,0): (0,1),
    (0,1): (-1,0),
    (-1,0): (0,-1),
    (0,-1): (1,0)
}

dir = [(1,0),(0,-1),(-1,0),(0,1)]

board = [[0] * 101 for _ in range(101)]

for _ in range(n):
    x,y,d,g = map(int, sys.stdin.readline().split())
    cur =[(x,y), (x+dir[d][0], y+dir[d][1])]
    last = cur[-1]
    for _ in range(g):
        tmp=[]
        for idx in range(len(cur)-1, 0, -1):
            a = cur[idx-1]
            b = cur[idx]
            gapX = a[0]-b[0]
            gapY = a[1]-b[1]
            dxdy = rotation[(gapX, gapY)]
            tmp.append((last[0] + dxdy[0], last[1] + dxdy[1]))
            last = tmp[-1]
        cur += tmp
    for a,b in cur:
        board[a][b] = 1

answer = 0

for i in range(100):
    for j in range(100):
        if board[i][j] == 1 and board[i][j+1] == 1 and board[i+1][j] == 1 and board[i+1][j+1] == 1:
            answer+=1
            
print(answer)

# dragoncurb[0] = [
#     [(0,0), (1,0)],
#     [(1,-1)],
#     [(0,-1),(0,-2)],
#     [(-1,-2),(-1,-1), (-2,-1),(-2,-2)],
#     [(-3,-2),(-3,-1),(-2,-1),(-2,0),(-3,0),(-3,1),(-4,1),(-4,0)],
#     [(-5,0),(-5,1),(-4,1),(-4,2),(-3,2),(-3,1),(-2,1),(-2,2),(-3,2),(-3,3),(-2,3),(-2,4),(-3,4),(-3,5),(-4,5),(-4,4)],
    
# ]