//[실버1] 2667.단지내번호붙이기 https://www.acmicpc.net/problem/2667

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');
let n = +input.shift();

function BFS(map, start, visited, n) {

    visited[start[0]][start[1]] = true;
    let result = 1;
    let queue = [start];
    let front = 0;

    const dx = [1, 0, -1, 0];
    const dy = [0, 1, 0, -1];

    while (front < queue.length) {
        let first = queue[front++];

        for (let i = 0; i < 4; i++) {
            let newX = first[0] + dx[i];
            let newY = first[1] + dy[i];
            if (newX < 0 || newY < 0 || newX >= n || newY >= n)
                continue;
            if (!visited[newX][newY] && map[newX][newY] === '1') {
                queue.push([newX, newY]);
                visited[newX][newY] = true;
                result++;
            }
        }
    }

    return result;
}

function solution(n, map) {

    let visited = Array.from({ length: n }, () => Array.from({ length: n }, () => false));

    let answer = [];
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (!visited[i][j] && map[i][j] === '1') {
                answer.push(BFS(map, [i, j], visited, n));
            }
        }
    }

    answer.sort((a, b) => a - b);
    return answer.length + '\n' + answer.join('\n');

}

console.log(solution(n, input));