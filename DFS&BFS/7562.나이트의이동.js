//[실버1] 7562.나이트의이동 https://www.acmicpc.net/problem/7562

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let T = +input.shift();
let cases = [];
for (let i = 0; i < T; i++) {
    cases.push([+input.shift(), input.shift().split(' ').map((v) => +v), input.shift().split(' ').map((V) => +V)]);
}

function solution(cases) {

    let dy = [1, 1, 2, 2, -1, -1, -2, -2];
    let dx = [2, -2, 1, -1, 2, -2, 1, -1];

    let answer = [];

    cases.forEach(([I, start, end]) => {

        let queue = [start];
        let front = 0;
        let visited = Array.from({ length: I }, () => Array.from({ length: I }, () => Infinity));
        visited[start[0]][start[1]] = 0;

        while (front < queue.length) {
            let first = queue[front++];

            for (let dir = 0; dir < 8; dir++) {
                let newX = first[0] + dx[dir];
                let newY = first[1] + dy[dir];
                if (newX < 0 || newY < 0 || newX >= I || newY >= I)
                    continue;
                if (visited[newX][newY] > visited[first[0]][first[1]] + 1) {
                    visited[newX][newY] = visited[first[0]][first[1]] + 1;
                    queue.push([newX, newY]);
                }
            }
        }

        answer.push(visited[end[0]][end[1]]);

    })

    return answer.join('\n');

}

console.log(solution(cases));