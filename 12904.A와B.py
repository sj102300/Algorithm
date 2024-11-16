#[골드5] 12904.A와B https://www.acmicpc.net/problem/12904

import sys

s = list(sys.stdin.readline().rstrip())
t = list(sys.stdin.readline().rstrip())

def solution(s,t):
    cur = t
    while len(cur) != len(s):
        lastLetter = cur[-1]
        if lastLetter == 'A':
            cur.pop()
        elif lastLetter == 'B':
            cur.pop()
            cur.reverse()

    for i in range(len(cur)):
        if cur[i] != s[i]:
            return 0

    return 1

print(solution(s,t))
