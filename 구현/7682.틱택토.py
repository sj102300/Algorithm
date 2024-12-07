#[골드5] 7682.틱택토 https://www.acmicpc.net/problem/7682

import sys

lines = [
    set([0,1,2]),
    set([3,4,5]),
    set([6,7,8]),
    set([0,3,6]),
    set([1,4,7]),
    set([2,5,8]),
    set([0,4,8]),
    set([2,4,6])
]

def hasLine(list):

    for line in lines:
        cnt = 0
        for elem in list:
            if elem in line:
                cnt+=1
        if cnt == 3:
            return True
    
    return False

def isValid(ticktakto):

    board = list(ticktakto)
    xlist = []
    olist = []
    for i in range(len(board)):
        if board[i] == 'X':
            xlist.append(i)
        elif board[i] == 'O':
            olist.append(i)
    
    if len(xlist) == len(olist) + 1:     #X 차례
        #X는 Line이 있어야하고, O는 없어야함, 근데 마지막에 9로 다 찬경우라면 둘다 없어도 가능
        isXline, isOline = hasLine(xlist), hasLine(olist)
        if not isOline and (isXline or (not isXline and len(xlist)+len(olist)==9)):
            return "valid"
    elif len(xlist) == len(olist) : #O차례인경우
        #O는 line이 있어야하고 X는 없어야함
        isXline, isOline = hasLine(xlist), hasLine(olist)
        if (isOline and not isXline):
            return "valid"
    
    return "invalid"

while True:
    tictakto = sys.stdin.readline().rstrip()
    if tictakto == 'end':
        break

    print(isValid(tictakto))