//[Lv3] 미로탈출명령어 https://school.programmers.co.kr/learn/courses/30/lessons/150365

let answer = ''

function dfs(history, k, start, end, N, M){
    if(answer !== ''){
        return;
    }
    if(history.length === k){
        if(start[0] === end[0] && start[1] === end[1])
            answer = history;
        return;
    }
    if(history.length === k && start[0] === end[0] && start[1] === end[1]){
        answer = history;
        return;
    }
    let distance = Math.abs(start[0] - end[0]) + Math.abs(start[1] - end[1]);
    if(distance > k - history.length){
        return;
    }
    
    //d,l,r,u
    const dir = [
        ['d', 1, 0],['l', 0, -1],['r', 0, 1],['u', -1, 0]
    ]
    
    for(let i = 0; i<4; i++){
        let d = dir[i][0];
        let newX = start[0] + dir[i][1];
        let newY = start[1] + dir[i][2];
        if(newX < 1 || newY < 1 || newX > N || newY > M)
           continue;
        dfs(history+d, k, [newX, newY], end, N, M);
    }
    return;
}

function solution(n, m, x, y, r, c, k) {
    
    let shouldMoveX = r - x;
    let shouldMoveY = c - y;
    
    let distance = Math.abs(shouldMoveX) + Math.abs(shouldMoveY);
    
    if(distance > k || (k-distance) % 2 !== 0)
        return "impossible";
    
    dfs('', k, [x,y], [r,c], n, m);
    
    return answer;
}