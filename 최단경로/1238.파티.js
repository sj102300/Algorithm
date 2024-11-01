//[골드3] 1238.파티 https://www.acmicpc.net/problem/1238
//다익스트라 알고리즘으로 풀이해보자

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n').map((v) => v.split(" ").map((e) => +e));

let [N, M, X] = input.shift();

function getMinNode(distance, visited, N) {  //방문하지 않은 노드들 중 가중치가 최소인 정점 찾기(우선순위 큐 사용가능)
    let minWeight = 123456789;
    let minNode;

    for (let i = 1; i <= N; i++) {
        if (distance[i] < minWeight && !visited[i]) {
            minWeight = distance[i];
            minNode = i;
        }
    }

    return minNode;
}

function dijkstra(start, graph, distance) {

    let visited = Array.from({ length: N + 1 }, () => false);  //방문하지 않은건지 찾아야함. 

    distance[start] = 0;
    visited[start] = true;

    graph[start]?.forEach(([end, weight]) => {
        distance[end] = weight;   //시작 정점과 연결된 정점들 가중치 초기화
    })

    for (let i = 1; i <= N; i++) {
        let minNode = getMinNode(distance, visited, N);     //방문하지 않은 노드들 중, 가장 가중치가 작은 노드 찾기
        visited[minNode] = true;  //방문처리

        graph[minNode]?.forEach(([end, weight]) => {  //해당 노드에 연결된 노드들 중 
            if (distance[minNode] + weight < distance[end]) {  //가중치 업데이트 가능한 경우, 업데이트
                distance[end] = distance[minNode] + weight;
            }
        })

    }

}

function solution(N, M, X, data) {

    let graph = Array.from({ length: N + 1 }, () => []);
    let reverseGraph = Array.from({length: N+1}, ()=>[]);

    for (let i = 0; i < M; i++) {
        let [start, end, weight] = data[i];
        graph[start].push([end, weight]);
        reverseGraph[end].push([start, weight]);
    }

    let XtoN = Array.from({ length: N + 1 }, () => 123456789);

    dijkstra(X, graph, XtoN, N);

    let NtoX = Array.from({ length: N + 1 }, () => 123456789);

    dijkstra(X, reverseGraph, NtoX);

    let answers = Array.from({length:N+1}, ()=>0);

    for(let i=1;i<=N;i++){
        answers[i] = NtoX[i] + XtoN[i];
    }

    return Math.max(...answers);

}

console.log(solution(N, M, X, input));

