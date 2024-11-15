#[골드5] 2170.선긋기 https://www.acmicpc.net/problem/2170

import sys

n = int(sys.stdin.readline().rstrip())
data=[list(map(int, sys.stdin.readline().split())) for _ in range(n)]

data.sort(key=lambda x: x[0])

start = data[0][0]
end = data[0][1]

answer = 0
for [v1, v2] in data:
    if v1 <= end:
        end = max(v2, end)
    else:
        answer += end - start
        start = v1
        end = v2

answer += end - start

print(answer)
