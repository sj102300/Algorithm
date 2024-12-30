#[골드5] 1790.수이어쓰기2 https://www.acmicpc.net/problem/1790

import sys

n, k = map(int, sys.stdin.readline().split())

depth = 1
while True:
    if k - (10 ** depth - 10 ** (depth -1)) * depth > 0:
        k -= (10 ** depth - 10 ** (depth -1)) * depth
        depth += 1
    else:
        break

# 10 ** depth 로부터 k번째수

a = k // depth
b = k % depth

target = 10 ** (depth-1) + a - 1

answer = -1
if b == 0 :
    if target <=n :
        answer = target % 10
else:
    target += 1
    if target <= n:
        answer = str(target)[b-1]

print(answer)

