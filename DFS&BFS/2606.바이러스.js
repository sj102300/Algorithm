//[실버3] 2606.바이러스 https://www.acmicpc.net/problem/2606

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let N = +input.shift();

input.shift();

input = input.map((v)=>v.split(' ').map(e=>+e));

function dfs(graph, visited, start){

    if(visited[start])
        return 0;
    
    visited[start] = true;

    let result = 1;
    if(graph[start]){
        graph[start].forEach((v)=>{
            result += dfs(graph, visited, v);
        })
    }
    return result;
}

function solution(N, input){
    let visited = Array.from({length:N+1},()=>false);

    let graph = {};
    input.forEach(([s, e])=>{
        if(graph[s])
            graph[s].push(e);
        else
            graph[s] = [e];
        if(graph[e])
            graph[e].push(s);
        else
            graph[e] = [s];
    })

    return dfs(graph, visited, 1) - 1;

}

console.log(solution(N, input));
