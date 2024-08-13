//[Lv3] 경주로건설 https://school.programmers.co.kr/learn/courses/30/lessons/67259

function bfs(board, start, dir, curCost, N) {

    if (start[0] < 0 || start[1] < 0 || start[0] >= N || start[1] >= N) {
        return;
    }
    if (board[start[0]][start[1]] === 1) {
        return;
    }
    
    const dx = [0, 1, -1, 0];
    const dy = [1, 0, 0, -1];

    let cost

    for (let i = 0; i < 4; i++) {
        if (dir === i) {
            cost = curCost + 100;
        }
        else {
            cost = curCost + 600;
        }
        let newX = start[0] + dx[i];
        let newY = start[1] + dy[i];
        if (newX <0 || newY <0 || newX >= N || newY >= N){
            continue;
        }
        if (cost <= board[newX][newY] || board[newX][newY] === 0){
            board[newX][newY] = cost;
            bfs(board, [newX, newY], i, cost, N)
        }
    }

}

function solution(board) {

    for(let i=0; i<4;i++){
        bfs(board, [0, 0], i, 0, board.length);
    }

    return board[board.length-1][board.length-1]

}