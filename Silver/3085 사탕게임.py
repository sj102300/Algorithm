import sys
import copy

n = int(sys.stdin.readline().rstrip())
data = [" ".join(sys.stdin.readline().rstrip()).split() for _ in range(n)]


# 현재 상황에서 먹을 수 있는 최대개수 알기
# 안바꿨을때가 최대 인 경우
# FFF
# CCC
# FCF
# 바꾼 방향의 수직 줄의 사탕을 먹음, 가로로 바꾸면 세로줄을 먹어d
# ㄴㄴ 아님 세로방향 바꾸고 세로줄 먹을수도 이거 체크하는걸 그냥 함수로 만드는게 나을듯ddsdf
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
