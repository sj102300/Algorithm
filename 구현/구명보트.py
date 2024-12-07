#[Lv2] 구명보트 https://school.programmers.co.kr/learn/courses/30/lessons/42885?language=python3

def solution(people, limit):
    people.sort()
    
    left, right = 0, len(people)-1
    
    while left < right:
        if people[left] + people[right] <= limit:
            left+=1
        right-=1
    
    return len(people) - left