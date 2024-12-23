#[실버1] 1309.동물원 https://www.acmicpc.net/problem/1309

import sys

n = int(sys.stdin.readline())

dp = [1,1,1]

for i in range(1, n):
    next_dp = [0,0,0]
    next_dp[0] = dp[1] + dp[2]
    next_dp[1] = dp[0] + dp[2] 
    next_dp[2] = dp[0] + dp[1] + dp[2]
    dp = next_dp

mod = 9901
print(sum(dp) % mod)