//[실버1] 5014.스타트링크 https://www.acmicpc.net/problem/5014

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let [F, S, G, U, D] = fs.readFileSync('dev/stdin', 'utf-8').trim().split(' ').map((v) => +v);

function solution(F, S, G, U, D) {

    let visited = Array.from({ length: F + 1 }, () => F + 1);

    let queue = [S];
    let front = 0;
    visited[S] = 0;

    while (front < queue.length) {
        let first = queue[front++];

        let goUp = first + U;
        let goDown = first - D;

        if (goUp < F + 1 && goUp > 0 && visited[goUp] > visited[first] + 1) {
            visited[goUp] = visited[first] + 1;
            queue.push(goUp)
        }
        if (goDown < F + 1 && goDown > 0 && visited[goDown] > visited[first] + 1) {
            visited[goDown] = visited[first] + 1;
            queue.push(goDown);
        }
    }

    return visited[G] !== F + 1 ? visited[G] : 'use the stairs'

}

console.log(solution(F, S, G, U, D));