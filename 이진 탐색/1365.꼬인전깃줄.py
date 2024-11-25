#[골드2] 1365.꼬인전깃줄 https://www.acmicpc.net/problem/1365

import sys
n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

def binarySearch(answer, target):
    left, right = 0, len(answer)-1

    while left <= right :
        mid = (left+right)//2
        if answer[mid] == target:
            return mid
        elif answer[mid] < target:
            left = mid + 1
        else:
            right = mid -1

    return left

def solution(n, arr):
    
    answer = [arr[0]]

    for i in range(1, len(arr)):
        if answer[-1] < arr[i]:
            answer.append(arr[i])
        elif answer[-1] > arr[i]:
            targetIdx = binarySearch(answer, arr[i])
            answer[targetIdx] = arr[i]
    
    return n - len(answer)

print(solution(n,arr))

#이게 왜 돼 ?
#만약에 모두다 감소하고 있으면 어떡할거임
# 1 2
# 2 3
# 3 4
# 4 1
# 5 8
# 6 5
# 7 6
# 8 7
# => 이러면 감소하는부분수열과 증가하는 부분수열을 구분해야하고
# => 꼭 증가하는 전깃줄이 정답이라는 조건이 있음?
# 근데 오른쪽만을 보면 결국, 1과 8이 증가하는 부분수열이 아닌게 됨. 결국 답이 2가 되는거지
