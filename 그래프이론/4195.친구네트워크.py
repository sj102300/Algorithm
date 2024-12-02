#[골드2] 4195.친구네트워크 https://www.acmicpc.net/problem/4195

import sys

t = int(sys.stdin.readline())

def union(a, b, parent, network):
    pa = find(a, parent)
    pb = find(b, parent)

    if pa == pb :
        return len(network[pa])
    elif pa<pb:
        parent[pb] = pa
        network[pa] = network[pa] | network[pb]
        if pb in network.keys():
            del network[pb]
        return len(network[pa])
    else:
        parent[pa] = pb
        network[pb] = network[pb] | network[pa]
        if pa in network.keys():
            del network[pa]
        return len(network[pb])
    

def find(x, parent):
    if x == parent[x]:
        return x
    px = find(parent[x], parent)
    return px

for _ in range(t):
    n = int(sys.stdin.readline())

    parent = []
    network = {}
    name_to_id = dict()
    idCounter = 0

    for _ in range(n):
        a,b = sys.stdin.readline().rstrip().split()

        if a not in name_to_id.keys():
            name_to_id[a] = idCounter
            parent.append(idCounter)
            network[idCounter] = set([idCounter])
            idCounter+=1
        aId = name_to_id[a]
        if b not in name_to_id.keys():
            name_to_id[b] = idCounter
            parent.append(idCounter)
            network[idCounter] = set([idCounter])
            idCounter+=1
        bId = name_to_id[b]

        print(union(aId, bId, parent, network))
        # print(network)