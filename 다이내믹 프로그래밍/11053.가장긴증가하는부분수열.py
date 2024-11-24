#[실버2] 11053.가장긴증가하는부분수열 https://www.acmicpc.net/problem/11053

import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

def solution(n, arr):
    dp = [1] * n
    
    for i in range(1, n):
        for j in range(i-1, -1, -1):
            if arr[j] < arr[i]:
                dp[i] = max(dp[j] + 1, dp[i])

    return max(dp)

print(solution(n, arr))