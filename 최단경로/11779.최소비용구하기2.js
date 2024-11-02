//[골드3] 11779.최소비용구하기2 https://www.acmicpc.net/problem/11779

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split("\n").map((v) => v.split(" ").map((e) => +e));

let N = +input.shift();
let M = +input.shift();

let [S, E] = input.pop();

function getMinNode(visited, distance) {
    let minNode;
    let minDistance = 123456789;
    for (let i = 1; i < visited.length; i++) {
        if (!visited[i] && distance[i] < minDistance) {
            minDistance = distance[i];
            minNode = i;
        }
    }
    return minNode;
}

function dijkstra(graph, distance, history, start, N) {

    let visited = Array.from({ length: N + 1 }, () => false);

    visited[start] = true;
    distance[start] = 0;

    graph[start]?.forEach(([end, cost]) => {
        if (distance[end] > cost) {
            distance[end] = cost;
            history[end] = [start, end]
        }
    })

    for (let i = 1; i <= N; i++) {
        let minNode = getMinNode(visited, distance);
        visited[minNode] = true;

        graph[minNode]?.forEach(([end, cost])=>{
            if(distance[minNode] + cost <= distance[end]){
                distance[end] = distance[minNode] + cost;
                history[end] = [...history[minNode], end]
            }
        })
    }

}

function solution(N, M, S, E, input) {
    //visited, distance, history 이렇게

    let graph = {};
    for (let i = 0; i < M; i++) {
        let [start, end, cost] = input[i];
        if(graph[start]){
            graph[start].push([end, cost]);
        }
        else{
            graph[start] = [[end, cost]];
        }
    }

    let distance = Array.from({ length: N + 1 }, () => 123456789);
    let history = Array.from({ length: N + 1 }, () => []);

    dijkstra(graph, distance, history, S, N);

    console.log(distance[E]);
    console.log(history[E].length);
    console.log(history[E].join(" "));

}

console.log(solution(N, M, S, E, input))