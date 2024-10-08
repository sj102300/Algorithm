//[골드3] 2146.다리만들기 https://www.acmicpc.net/problem/2146

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = input.shift();
let map = input.map((v) => v.split(' ').map((e) => +e));

function BFS(map, visited, N, start, islandNum) {

    let queue = [start];
    let front = 0;
    visited[start[0]][start[1]] = islandNum;

    let dx = [1, 0, -1, 0];
    let dy = [0, 1, 0, -1];

    let lines = [];

    while (front < queue.length) {
        let first = queue[front++];

        let isLine = false;
        for (let dir = 0; dir < 4; dir++) {
            let newX = first[0] + dx[dir];
            let newY = first[1] + dy[dir];

            if (newX < 0 || newY < 0 || newX >= N || newY >= N)
                continue;

            if(map[newX][newY] === 0)
                isLine = true;

            if (map[newX][newY] === 1 && visited[newX][newY] === 0) {
                visited[newX][newY] = islandNum;
                queue.push([newX, newY]);
            }
        }
        if (isLine)
            lines.push([first[0], first[1]])
    }

    return lines;
}

function solution(N, map) {

    let visited = Array.from({ length: N }, () => Array.from({ length: N }, () => 0));

    let islands = [];

    let islandPointer = 10;
    for (let i = 0; i < N; i++) {
        for (let j = 0; j < N; j++) {
            if (map[i][j] === 1 && visited[i][j] === 0) {
                islands.push(BFS(map, visited, N, [i, j], ++islandPointer));
            }
        }
    }

    let answer = Infinity;
    for (let i = 0; i < islands.length; i++) {
        for (let j = i + 1; j < islands.length; j++) {
            let firstIsland = islands[i];
            let secondIsland = islands[j];
            for (let k = 0; k < firstIsland.length; k++) {
                for (let l = 0; l < secondIsland.length; l++) {
                    let bridgeLength = Math.abs(firstIsland[k][0] - secondIsland[l][0]) + Math.abs(firstIsland[k][1] - secondIsland[l][1]) - 1;
                    answer = Math.min(bridgeLength, answer);
                }
            }
        }
    }

    return answer;
}

console.log(solution(n, map));