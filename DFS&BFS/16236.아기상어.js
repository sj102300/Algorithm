//[골드3] 16236.아기상어 https://www.acmicpc.net/problem/16236

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input.shift();
let map = input.map((e) => e.split(" ").map((V) => +V));

function BFS(map, visited, start, n, sharkSize) {

    let queue = [start];
    let front = 0;
    visited[start[0]][start[1]] = 0;

    let dx = [1, 0, -1, 0];
    let dy = [0, 1, 0, -1];

    while (front < queue.length) {
        let first = queue[front++];

        for (let i = 0; i < 4; i++) {
            let newX = first[0] + dx[i];
            let newY = first[1] + dy[i];
            if (newX < 0 || newY < 0 || newX >= n || newY >= n)
                continue;
            if (map[newX][newY] <= sharkSize && (visited[newX][newY] === 123456789 || visited[newX][newY] > visited[first[0]][first[1]] + 1)) {
                queue.push([newX, newY]);
                visited[newX][newY] = visited[first[0]][first[1]] + 1;
            }
        }
    }

}

function initVisited(visited, n) {
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            visited[i][j] = 123456789;
        }
    }
}

function solution(n, map) {

    let fishesLocation = Array.from({ length: 7 }, () => new Set());

    let sharkLocation;

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (map[i][j] === 9) {
                sharkLocation = [i, j];
                map[i][j] = 0;
            }
            else if (map[i][j] !== 0) {
                let fishSize = map[i][j];
                fishesLocation[fishSize].add(`${i} ${j}`);
            }
        }
    }

    let sharkSize = 2;
    let time = 0;
    let eatenFishNum = 0;

    let visited = Array.from({ length: n }, () => Array(n).fill(123456789));

    while (true) {

        initVisited(visited, n);
        BFS(map, visited, sharkLocation, n, sharkSize);

        let availableFishes = [];
        for (let i = 1; i < sharkSize && i < 7; i++) {
            for (let value of fishesLocation[i]) {
                let [x, y] = value.split(" ").map((V) => +V);
                availableFishes.push([x, y]);
            }
        }

        if (availableFishes.length === 0) {
            //더 이상 먹을 수 있는 물고기가 없음
            break;
        }

        let targetFishLocation = [...availableFishes[0]];
        let minLength = visited[targetFishLocation[0]][targetFishLocation[1]];

        availableFishes.map(([x, y]) => {
            if (visited[x][y] !== 123456789) {
                if (visited[x][y] < minLength) {
                    targetFishLocation = [x, y];
                    minLength = visited[x][y];
                }
                else if (visited[x][y] === minLength) {
                    if (x < targetFishLocation[0] ||
                        (x === targetFishLocation[0] && y < targetFishLocation[1])
                    ) {
                        targetFishLocation = [x, y];
                    }
                }
            }
        })

        if (minLength === 123456789) {  //먹을 수 있는 물고기한테 갈수 없음
            break;
        }

        time += minLength;
        sharkLocation = targetFishLocation;
        eatenFishNum++;
        fishesLocation[map[targetFishLocation[0]][targetFishLocation[1]]].delete(`${targetFishLocation[0]} ${targetFishLocation[1]}`);
        map[targetFishLocation[0]][targetFishLocation[1]] = 0;
        if (eatenFishNum === sharkSize) {
            sharkSize++;
            eatenFishNum = 0;
        }

    }

    return time;

}

console.log(solution(n, map));