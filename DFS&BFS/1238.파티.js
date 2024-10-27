//[골드3] 1238.파티 https://www.acmicpc.net/problem/1238

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n').map((v) => v.split(" ").map((e) => +e));

let [N, M, X] = input.shift();

function BFS(graph, start, visited) {

    let queue = [start];
    let front = 0;
    visited[start][start] = 0;

    while (front < queue.length) {
        let first = queue[front++];

        graph[first]?.forEach(([end, weight]) => {
            if (visited[start][end] > visited[start][first] + weight) {
                visited[start][end] = visited[start][first] + weight;
                queue.push(end);
            }
        })
    }
}

function solution(N, M, X, data) {

    let graph = Array.from({ length: N + 1 }, () => []);

    for (let i = 0; i < M; i++) {
        let [start, end, weight] = data[i];
        graph[start].push([end, weight]);
    }

    let visited = Array.from({ length: N + 1 }, () => Array.from({ length: N + 1 }, () => 123456789));

    for (let i = 1; i <= N; i++) {
        BFS(graph, i, visited);
    }

    let weightByStudents = Array.from({ length: N + 1 }, () => 0);

    for (let i = 1; i <= N; i++) {
        weightByStudents[i] = visited[i][X] + visited[X][i];
    }

    return Math.max(...weightByStudents);

}

console.log(solution(N, M, X, input));

