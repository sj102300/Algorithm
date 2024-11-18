#[골드2] 7453.합이0인네정수 https://www.acmicpc.net/problem/7453

import sys

n = int(sys.stdin.readline())

data = [[],[],[],[]]
for _ in range(n):
    input = list(map(int, sys.stdin.readline().split()))
    for i in range(4):
        data[i].append(input[i])

def solution(data, n):
    
    ab = []
    cd = []

    for i in range(n):
        for j in range(n):
            ab.append(data[0][i] + data[1][j])
            cd.append(data[2][i] + data[3][j])

    answer = 0

    ab.sort()
    cd.sort()

    left = 0 
    right = len(cd)-1

    while left < len(ab) and right >= 0:
        if ab[left] + cd[right] < 0:
            left += 1
        elif ab[left] + cd[right] > 0:
            right -= 1
        else:
            ab_target = ab[left]
            cd_target = cd[right]
            ab_num, cd_num = 0,0
            while left < len(ab) and ab_target == ab[left]:
                left += 1
                ab_num += 1
            while right >= 0 and cd_target == cd[right]:
                right -= 1
                cd_num += 1
            answer += ab_num * cd_num

    return answer

print(solution(data, n))