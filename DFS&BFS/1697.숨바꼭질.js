//[실버1] 1697.숨바꼭질 https://www.acmicpc.net/problem/1697

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let [N, K] = fs.readFileSync('dev/stdin', 'utf-8').trim().split(' ').map((v) => +v);

function solution(N, K) {

    let visited = Array.from({ length: 100001 }, () => Infinity);

    let queue = [N];
    let front = 0;
    visited[N] = 0;

    while (front < queue.length) {
        let first = queue[front++];

        let walkLeft = first - 1;
        let walkRight = first + 1;
        let teleport = 2 * first;

        if (walkLeft >= 0 && walkLeft <= 100000 && visited[walkLeft] > visited[first] + 1) {
            visited[walkLeft] = visited[first] + 1;
            queue.push(walkLeft);
        }
        if (walkRight >= 0 && walkRight <= 100000 && visited[walkRight] > visited[first] + 1) {
            visited[walkRight] = visited[first] + 1;
            queue.push(walkRight);
        }
        if (teleport >= 0 && teleport <= 100000 && visited[teleport] > visited[first] + 1) {
            visited[teleport] = visited[first] + 1;
            queue.push(teleport);
        }
    }

    return visited[K];

}

console.log(solution(N, K));