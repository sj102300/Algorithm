import sys
import copy

n = int(sys.stdin.readline().rstrip())
data = [" ".join(sys.stdin.readline().rstrip()).split() for _ in range(n)]

# [실버2] 3085.사탕게임 https://www.acmicpc.net/problem/3085

def checkMaxCnt(target):
    maxCnt = 1

    for i in range(n):
        tmpCnt = 1
        for j in range(n - 1):
            if target[i][j] == target[i][j + 1]:
                tmpCnt += 1
            else:
                if tmpCnt > maxCnt:
                    maxCnt = tmpCnt
                tmpCnt = 1
        if tmpCnt > maxCnt:
            maxCnt = tmpCnt

    for j in range(n):
        tmpCnt = 1
        for i in range(n-1):
            if target[i][j] == target[i + 1][j]:
                tmpCnt += 1
            else:
                if tmpCnt > maxCnt:
                    maxCnt = tmpCnt
                tmpCnt = 1
        if tmpCnt > maxCnt:
            maxCnt = tmpCnt

    return maxCnt


maxCnt = 1
for i in range(n):
    for j in range(n - 1):
        if data[i][j] != data[i][j + 1]:
            tmp = copy.deepcopy(data)
            tmp[i][j], tmp[i][j + 1] = tmp[i][j + 1], tmp[i][j]
            tmpMaxCnt = checkMaxCnt(tmp)
            if tmpMaxCnt > maxCnt:
                maxCnt = tmpMaxCnt

for i in range(n - 1):
    for j in range(n):
        if data[i][j] != data[i + 1][j]:
            tmp = copy.deepcopy(data)
            tmp[i][j], tmp[i + 1][j] = tmp[i + 1][j], tmp[i][j]
            tmpMaxCnt = checkMaxCnt(tmp)
            if tmpMaxCnt > maxCnt:
                maxCnt = tmpMaxCnt

print(maxCnt)