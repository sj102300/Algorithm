#[골드3] 2482.색상환 https://www.acmicpc.net/problem/2482

import sys

n = int(sys.stdin.readline())
k = int(sys.stdin.readline())

#dp[i][j] = i개의 색중에서 인접하지 않게 j개의 색상을 뽑는 경우
#dp[i][j] = dp[i-1][j] + dp[i-2][j-1]
#  = i-1개 중 인접하지 않게 j개를 뽑은 경우 + (i번의 색을 뽑기 위해) i-2번까지 인접하지 않게 j-1개를 뽑은 경우

dp = [[0] * (k+1) for _ in range(n+1)]

for i in range(1, n+1):
    dp[i][0] = 1
    dp[i][1] = i

mod = 1000000003

for i in range(1, n+1):
    for j in range(2, k+1):
        if j > i:
            continue
        dp[i][j] = dp[i-1][j] + dp[i-2][j-1]

print((dp[n-1][k] + dp[n-3][k-1]) % mod)