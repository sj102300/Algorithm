#[] 성적이낮은순서로학생출력하기 이것이코딩테스트다180p

n = int(input())
data=[]
for _ in range(n):
    value = input().split()
    data.append((value[0], int(value[1])))

tmp = [[] for _ in range(101)]

for i in data:
    print(i[1])
    tmp[i[1]].append(i[0])

for i in range(len(tmp) - 1):
    for j in tmp[i]:
        print(j, end=" ")


