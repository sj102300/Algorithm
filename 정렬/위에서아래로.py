#[] 위에서아래로 이것이코딩테스트다178p

n = int(input())
data = [int(input()) for _ in range(n)]

data.sort(reverse=True)

for i in data:
    print(i, end=" ")