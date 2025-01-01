#[골드2] 17780.새로운게임 https://www.acmicpc.net/problem/17780

import sys

n, k = map(int, sys.stdin.readline().split())

board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
dxdy = [(0,1),(0,-1), (-1,0), (1,0)]

position = {}
horse_direction = [0] * k
for i in range(k):
    x, y, d = map(int, sys.stdin.readline().split())
    position[(x-1,y-1)] = [i]
    horse_direction[i] = d-1

opposite_dir ={
    0:1,
    1:0,
    2:3,
    3:2
}

def get_move_sequence_by_position(position):

    sequence = []
    for k, i in position.items():
        sequence.append((k, i[0]))
    
    sequence.sort(key=lambda x: x[1])

    return sequence

def get_next_color(cur_location, dir, board):

    newX = cur_location[0] + dxdy[dir][0]
    newY = cur_location[1] + dxdy[dir][1]

    if newX < 0 or newY < 0 or newX >= n or newY >= n:
        return 2

    return board[newX][newY]

def go_next(cur_location, dir, position):
    
    newX = cur_location[0] + dxdy[dir][0]
    newY = cur_location[1] + dxdy[dir][1]

    next_location = (newX, newY)
    if next_location in position:
        position[next_location] += position[cur_location]
    else:
        position[next_location] = position[cur_location]
    
    del position[cur_location]

    return len(position[next_location])

def reverse_cur(cur_location, position):

    position[cur_location].reverse()

    return position

def move_horses(board, position, k):
    
    turn = 0

    while True:
        turn += 1

        if turn > 1000:
            return -1

        for target_horse in range(k):

            is_horse_set = False

            sequence = get_move_sequence_by_position(position)
            for cur_loc, horse_id in sequence:
                if horse_id == target_horse:
                    cur_location = cur_loc
                    horse_idx = horse_id
                    is_horse_set = True
                    break

            if not is_horse_set:
                continue
            
            next_color = get_next_color(cur_location, horse_direction[horse_idx], board)
            
            tmp = -1
            if next_color == 0:
                tmp = go_next(cur_location, horse_direction[horse_idx], position)
            elif next_color == 1:
                reverse_cur(cur_location, position)
                tmp = go_next(cur_location, horse_direction[horse_idx], position)
            elif next_color == 2:
                horse_direction[horse_idx] = opposite_dir[horse_direction[horse_idx]]
                opposite_color = get_next_color(cur_location, horse_direction[horse_idx], board)
                if opposite_color == 0:
                    tmp = go_next(cur_location, horse_direction[horse_idx], position)
                elif opposite_color == 1:
                    reverse_cur(cur_location, position)
                    tmp = go_next(cur_location, horse_direction[horse_idx], position)
            
            if tmp >= 4:
                return turn
        


print(move_horses(board, position, k))