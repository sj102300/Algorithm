#[골드4] 9935.문자열폭발 https://www.acmicpc.net/problem/9935

import sys
from copy import deepcopy

st = list(sys.stdin.readline().rstrip())
explode = list(sys.stdin.readline().rstrip())

answer = [-1] * len(st)
pointer = -1

for i in range(len(st)):
    pointer += 1
    answer[pointer] = st[i]

    hasExplode = True
    for j in range(len(explode)):
        if answer[pointer - j] != explode[-1 - j]:
            hasExplode = False
            break
    if hasExplode:
        pointer -= len(explode)

if pointer < 0:
    print("FRULA")
else:
    print("".join(answer[:pointer+1]))