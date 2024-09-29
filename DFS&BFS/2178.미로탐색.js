//[실버1] 2178.미로탐색 https://www.iacmicpc.net/problem/2178

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [N, M] = input.shift().split(' ').map((v) => +v);

function solution(N, M, map) {
    let visited = Array.from({ length: N }, () => Array.from({ length: M }, () => 0));

    let queue = [[0, 0]]
    let front = 0;

    visited[0][0] = 1;

    let dx = [1, 0, -1, 0];
    let dy = [0, 1, 0, -1];

    while (front < queue.length) {
        let first = queue[front++];

        for (let i = 0; i < 4; i++) {
            let newX = first[0] + dx[i];
            let newY = first[1] + dy[i];
            if (newX < 0 || newY < 0 || newX >= N || newY >= M)
                continue;
            if(map[newX][newY] === '1' && visited[newX][newY] === 0){
                visited[newX][newY] = visited[first[0]][first[1]] + 1;
                queue.push([newX, newY]);
            }

        }
    }

    return visited[N - 1][M - 1];

}

console.log(solution(N, M, input))