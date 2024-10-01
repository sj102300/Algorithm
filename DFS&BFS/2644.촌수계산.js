//[실버2] 2644.촌수계산 https://www.acmicpc.net/problem/2644

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input.shift();
let [start, end] = input.shift().split(' ').map((v) => +v);
input.shift();

input = input.map((v) => v.split(' ').map((e) => +e));

function BFS(graph, start, end) {

    let visited = Array.from({ length: n + 1 }, () => -1);

    let queue = [start];
    visited[start] = 0;
    let front = 0;

    while (front < queue.length) {
        let first = queue[front++];
        //정답/종료조건 처리는 여기서 하자.
        if (first === end)
            return visited[end];

        graph[first]?.forEach((v) => {
            if (visited[v] === -1) {
                visited[v] = visited[first] + 1;
                queue.push(v);
            }
        })
    }

    return visited[end];
}

function solution(n, start, end, input) {

    let visited = Array.from({})

    let graph = {};
    input.forEach(([s, e]) => {
        if (graph[s])
            graph[s].push(e);
        else
            graph[s] = [e];
        if (graph[e])
            graph[e].push(s);
        else
            graph[e] = [s];
    })

    return BFS(graph, start, end)

}

console.log(solution(n, start, end, input));