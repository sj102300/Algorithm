//[실버2] 1260.DFS와BFS https://www.acmicpc.net/problem/1260

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [N, M, V] = input.shift().split(' ').map((v) => +v);
input = input.map((e) => e.split(' ').map((V) => +V));

function dfs(graph, visited, start, DFSAnswer) {

    //현재위치 방문표시(중복방문 방지)
    visited[start] = true;
    DFSAnswer.push(start);

    //연결된 노드, 4방향, 8방향.. 반복처리
    graph[start]?.forEach((v) => { 
        if (!visited[v]) {  //범위내, 미방문, 조건에 맞으면 dfs호출
            dfs(graph, visited, v, DFSAnswer);
        }
    })
}

function BFS(graph, visited, start, BFSAnswer) {

    //현재위치 방문처리
    visited[start] = 0;
    BFSAnswer.push(start);

    //큐에 초기 데이터들 삽입
    let queue = [start];
    let front = 0; //(원래는 큐를 써야하지만,, shift연산이 오래걸리니 헤드 포인터를 두고 이걸 옮겨다니겠음)

    //큐에 데이터가 있는 동안 반복처리
    while (front < queue.length) {
        let first = queue[front++]; //맨앞 원소 꺼내오기 (shift);
        
        //만약 방문한 노드에서 뭔가 종료조건이나 작업할 사항이 있다면 여기서 처리하자. 

        //연결된 노드, 4방향, 8방향 .. 반복처리
        graph[first]?.forEach((v) => {
            if (visited[v] === -1) {  //범위내, 미방문, 조건에 맞으면 큐에 삽입.
                queue.push(v);
                visited[v] = visited[first] + 1; //start에서 얼마나 멀리떨어져있는지를 봐보자. 그러려면 현재 노드보다 1칸 멀어짐을 이용.
                BFSAnswer.push(v);
            }
        })
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
    visited = visited.map(() => -1);

    BFS(graph, visited, V, BFSAnswer);

    return DFSAnswer.join(' ') + '\n' + BFSAnswer.join(' ');

}

console.log(solution(N, M, V, input));