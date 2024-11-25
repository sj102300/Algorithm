#[골드4] 2631.줄세우기 https://www.acmicpc.net/problem/2631

import sys

n = int(sys.stdin.readline())
arr =[]
for _ in range(n):
    arr.append(int(sys.stdin.readline()))

def binary_search(answer, target):
    left, right = 0, len(answer)-1

    while left<=right:
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
    for i in range(1, len(arr)):
        if answer[-1] < arr[i]:
            answer.append(arr[i])
        else:
            targetIdx = binary_search(answer, arr[i])
            answer[targetIdx] = arr[i]
    
    return n - len(answer)

print(solution(n, arr))