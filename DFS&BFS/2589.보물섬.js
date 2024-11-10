//[골드5] 2589.보물섬 https://www.acmicpc.net/problem/2589

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [X, Y] = input.shift().split(" ").map((v) => +v);

function BFS(map, start, X, Y) {

    let visited = Array.from({ length: X }, () => Array(Y).fill(-1));

    let queue = [start];
    visited[start[0]][start[1]] = 0;
    let front = 0;

    let dx = [1, 0, -1, 0];
    let dy = [0, 1, 0, -1];

    while (front < queue.length) {
        let first = queue[front++];

        for (let i = 0; i < 4; i++) {
            let newX = first[0] + dx[i];
            let newY = first[1] + dy[i];
            if (newX < 0 || newY < 0 || newX >= X || newY >= Y)
                continue;
            if (visited[newX][newY] === -1 && map[newX][newY] === 'L') {
                queue.push([newX, newY]);
                visited[newX][newY] = visited[first[0]][first[1]] + 1;
            }
        }
    }

    let lastLand = queue.pop();

    return visited[lastLand[0]][lastLand[1]];

}

function solution(X, Y, map) {

    let answer = 0;

    for (let i = 0; i < X; i++) {
        for (let j = 0; j < Y; j++) {
            if (map[i][j] === 'L') {
                let shortestLongPath = BFS(map, [i, j], X, Y);
                if (answer < shortestLongPath)
                    answer = shortestLongPath;
            }
        }
    }

    return answer;

}

console.log(solution(X, Y, input));