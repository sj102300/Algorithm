//[골드3] 1520.내리막길 https://www.acmicpc.net/problem/1520
import { createRequire } from 'module';
const require = createRequire(import.meta.url);


const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [n, m] = input[0].split(' ').map((e) => +e);
let data = input.slice(1).map((row) => row.split(' ').map((e) => +e));

function dfs(data, start, N, M, prev, dp) {

    if (start[0] < 0 || start[1] < 0 || start[0] >= N || start[1] >= M) {
        return -1;
    }
    if (start[0] === N - 1 && start[1] === M - 1) {
        dp[start[0]][start[1]] = 1
        return 1;
    }

    const dx = [0, 1, 0, -1];
    const dy = [1, 0, -1, 0];

    let cnt = 0;

    for (let i = 0; i < 4; i++) {
        let newX = start[0] + dx[i];
        let newY = start[1] + dy[i];
        if (newX < 0 || newY < 0 || newX >= N || newY >= M) {
            continue;
        }
        if(data[newX][newY] >= data[start[0]][start[1]]){
            continue;
        }
        if (dp[newX][newY] === -1) {
            let tmp = dfs(data, [newX, newY], N, M, data[start[0]][start[1]], dp);
            if (tmp > 0) {
                cnt += tmp;
            }
        }
        else {
            cnt += dp[newX][newY];
        }
    }

    dp[start[0]][start[1]] = cnt;

    return cnt;

}

function solution(n, m, data) {

    let dp = Array.from({ length: n }, () => Array(m).fill(-1))

    let answer = dfs(data, [0, 0], n, m, 10001, dp);

    console.log(answer);

}

solution(n, m, data);