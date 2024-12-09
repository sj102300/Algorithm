#[골드4] 1477.휴게소세우기 https://www.acmicpc.net/problem/1477

import sys
from collections import deque

n, m, l = map(int, sys.stdin.readline().split())

if n == 0:
    data = [0, l]
else:
    data = list(map(int, sys.stdin.readline().split())) + [0, l]

gaps = []
data.sort()

for i in range(len(data)-1):
    a,b = data[i], data[i+1]
    gaps.append(b-a)

gaps.sort()
left, right = 1, gaps[-1]
answer = gaps[-1]
while left<=right:
    mid = (left+right)//2
    
    q = deque(gaps)
    needed = 0

    while q:
        first = q.popleft()

        if first > mid:
            q.append(mid)
            q.append(first - mid)
            needed += 1
    
    if needed > m:
        left = mid + 1
    elif needed <= m:
        right = mid - 1
        answer = min(answer, mid)

print(answer)