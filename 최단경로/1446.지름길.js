//[실버1] 1446.지름길 https://www.acmicpc.net/problem/1446

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n').map((v) => v.split(" ").map((e) => +e));

let [N, D] = input.shift();

// function getMinNode(distance, visited) {
//     let minNode, minWeight = 123456789;
//     for (let i = 0; i <= D; i++) {
//         if (!visited[i] && distance[i] < minWeight) {
//             minNode = i;
//             minWeight = distance[i];
//         }
//     }
//     return minNode;
// }

function dijkstra(graph, start, distance, D) {

    // let visited = Array.from({ length: D + 1 }, () => false);

    distance[start] = 0;
    // visited[start] = true;

    graph[start]?.forEach(([end, weight]) => {
        if (distance[end] > weight) {
            distance[end] = weight;
        }
    })

    for (let i = 1; i <= D; i++) {
        // let minNode = getMinNode(distance, visited);
        let minNode = i - 1;
        // visited[minNode] = true;

        graph[minNode]?.forEach(([end, weight]) => {
            if (distance[minNode] + weight < distance[end]) {
                distance[end] = distance[minNode] + weight;
            }
        })
    }

}

function solution(N, D, data) {

    let graph = Array.from({ length: D + 1 }, (_, i) => [[i + 1, 1]])
    for (let i = 0; i < N; i++) {
        let [start, end, distance] = data[i];
        if (start > D || end > D)
            continue;
        graph[start].push([end, distance]);
    }

    let distance = Array.from({ length: D + 1 }, (_, i) => i);

    dijkstra(graph, 0, distance, D);

    return distance[D];
}

console.log(solution(N, D, input));