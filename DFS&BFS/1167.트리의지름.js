//[골드2] 1167.트리의지름 https://www.acmicpc.net/problem/1167

import { createRequire, findSourceMap } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let V = +input.shift();
let graph = {};
input.forEach((cmd) => {
    cmd = cmd.split(' ').map((v) => +v);

    graph[cmd[0]] = [];
    for (let i = 1; i < cmd.length - 1; i += 2) {
        graph[cmd[0]].push([cmd[i], cmd[i + 1]]);
    }

    graph[cmd[0]].sort((a, b) => b[1] - a[1]);

})

function BFS(start, graph, visited, V) {

    let queue = [start];
    let front = 0;
    visited[start] = 0;

    while (front < queue.length) {
        let first = queue[front++];

        graph[first]?.forEach(([end, cost]) => {
            if (visited[end] === 0) {
                queue.push(end);
                visited[end] = Math.max(visited[first] + cost, visited[first]);
            }
        })
    }

    visited[start] = 0;
    return;

}

function solution(V, graph) {

    let visited = Array.from({ length: V + 1 }, () => 0);

    BFS(1, graph, visited, V);

    let maxIdx, maxValue = 0;
    visited.forEach((value, i) => {
        if (maxValue < value) {
            maxValue = value;
            maxIdx = i;
        }
    })

    visited = visited.map(() => 0);

    BFS(maxIdx, graph, visited, V);

    return Math.max(...visited);

}

console.log(solution(V, graph));