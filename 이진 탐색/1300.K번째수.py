#[골드1] 1300.K번째수 https://www.acmicpc.net/problem/1300

import sys

n = int(sys.stdin.readline())
k = int(sys.stdin.readline())

def solution(n,k):
    
    left, right = 1, k

    answer = -1

    while left <= right:
        mid = (left + right) // 2
        
        cnt = 0 #mid보다 작은것의 개수
        for i in range(1, n+1):
            cnt += min(mid//i, n)
        
        if cnt >= k:  #mid보다 작은것의 개수가 k개 이상. 
            answer = mid
            right = mid -1
        else:
            left = mid + 1
    
    return answer

                

print(solution(n,k))