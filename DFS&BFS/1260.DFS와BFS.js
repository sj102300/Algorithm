//[실버2] 1260.DFS와BFS https://www.acmicpc.net/problem/1260

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [N, M, V] = input.shift().split(' ').map((v) => +v);
input = input.map((e) => e.split(' ').map((V) => +V));

function dfs(graph, visited, start, DFSAnswer) {

    if (visited[start])
        return;

    visited[start] = true;
    DFSAnswer.push(start);

    if (graph[start]) {
        graph[start].forEach((v) => {
            dfs(graph, visited, v, DFSAnswer);
        })
    }
}

function BFS(graph, visited, start, BFSAnswer) {

    let queue = [start];
    let front = 0;
    visited[start] = true;
    BFSAnswer.push(start);

    while (front < queue.length) {
        let first = queue[front];
        front++;
        if (graph[first]) {
            graph[first].forEach((v) => {
                if (!visited[v]) {
                    queue.push(v);
                    visited[v] = true;
                    BFSAnswer.push(v);
                }
            })
        }
    }

}

function solution(N, M, V, input) {

    let DFSAnswer = [];
    let visited = Array.from({ length: N + 1 }, () => false);

    //인접리스트 그래프 만들기 (양방향))
    let graph = {};
    input.forEach((cmd) => {
        if (graph[cmd[0]]) {
            graph[cmd[0]].push(cmd[1]);
        }
        else {
            graph[cmd[0]] = [cmd[1]];
        }
        if (graph[cmd[1]]) {
            graph[cmd[1]].push(cmd[0]);
        }
        else {
            graph[cmd[1]] = [cmd[0]];
        }
    })

    //그래프의 연결 노드들을 오름차순으로 정렬
    for (let vertex in graph) {
        graph[vertex].sort((a, b) => a - b);
    }

    dfs(graph, visited, V, DFSAnswer);

    let BFSAnswer = [];
    visited = visited.map(() => false);

    BFS(graph, visited, V, BFSAnswer);

    return DFSAnswer.join(' ') + '\n' + BFSAnswer.join(' ');

}

console.log(solution(N, M, V, input));