#[실버1] 9465.스티커 https://www.acmicpc.net/problem/9465

import sys
from copy import deepcopy

t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())
    sticker = [list(map(int, sys.stdin.readline().split())) for _ in range(2)]
    
    dp = [0,0,0]

    dp[0] = sticker[0][0]
    dp[1] = sticker[1][0]

    for i in range(1, n):
        dp = [
            max(dp[1], dp[2]) + sticker[0][i],
            max(dp[0], dp[2]) + sticker[1][i],
            max(dp)
        ]
    
    print(max(dp))

