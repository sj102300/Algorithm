#[플레5] 14003.가장긴증가하는부분수열5 https://www.acmicpc.net/problem/14003

import sys
n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

def binarySearch(answer, target):
    left, right = 0, len(answer)-1
    while left <= right:
        mid = (left+right)//2
        if answer[mid] == target: 
            return mid
        elif answer[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return left

def solution(n, arr):
    
    answer = [arr[0]]
    stack = [(0, arr[0])]

    for i in range(1, n):
        if answer[-1] < arr[i]:
            answer.append(arr[i])
            stack.append((len(answer) - 1, arr[i]))
        elif answer[-1] > arr[i]:
            targetIdx = binarySearch(answer, arr[i])
            answer[targetIdx] = arr[i]
            stack.append((targetIdx, arr[i]))

    answer_idx = len(answer) - 1
    for i in range(len(stack) -1, -1, -1):
        idx, value = stack[i]
        if idx == answer_idx:
            answer[answer_idx] = value
            answer_idx-=1
    
    print(len(answer))
    print(" ".join(map(str, answer)))

solution(n, arr)