#[골드3] 2623.음악프로그램 https://www.acmicpc.net/problem/2623

import sys

n, m = map(int, sys.stdin.readline().split())

indegree = [0] * (n+1)
graph = [[] for _ in range(n+1)]

for _ in range(m):
    tmp = list(map(int, sys.stdin.readline().split()))
    for i in range(2, len(tmp)):
        singer = tmp[i]
        indegree[singer]+=1
        prev_singer = tmp[i-1]
        graph[prev_singer].append(singer)

def solution(indegree, graph):

    cnt = 0
    answer = []
    singers = set()

    while cnt < n:

        is_deleted = False
        for i in range(1, n+1):

            if indegree[i] == 0 and not i in singers:
                answer.append(i)
                singers.add(i)
                is_deleted = True
                cnt += 1
                for end in graph[i]:
                    indegree[end]-=1

        if not is_deleted:
            print(0)
            return
        
    for i in range(len(answer)):
        print(answer[i])
    
solution(indegree, graph)