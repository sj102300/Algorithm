#[골드5] 9251.LCS https://www.acmicpc.net/problem/9251

import sys

a = sys.stdin.readline().rstrip()
b = sys.stdin.readline().rstrip()

lcs = [[0] * (len(b) + 1) for _ in range(len(a) + 1)]

for i in range(1, len(a) + 1):
    targetLetter = a[i - 1]
    for j in range(1, len(b) + 1):
        if targetLetter == b[j - 1]:
            lcs[i][j] = lcs[i-1][j-1] + 1
        else:
            lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1])

print(max(lcs.pop()))
