//[골드5] 1916.최소비용구하기 https://www.acmicpc.net/problem/1916

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input[0];
let m = +input[1];

let [start, end] = input.at(-1).split(' ').map((e)=>+e);

let graph = Array.from({ length: (n+1) }, () => Array(n+1).fill(Infinity) );
let visited = Array(n+1).fill(false);
let distance = Array(n+1).fill(Infinity);

input.slice(2, input.length-1).map((row)=>{
    let [depart, arrived, cost] = row.split(' ').map((e)=>+e);
    if (graph[depart][arrived] > cost){
        graph[depart][arrived] = cost;
    }
})

// console.log(graph);

function getSmallestNode(){
    let min = Infinity;
    let index = 0;

    for(let i= 1;i<n+1; i++){
        if(distance[i] < min && !visited[i]){
            min = distance[i];
            index=i;
        }
    }
    return index;
}

function dijkstra(start){
    distance[start] = 0;
    visited[start] = true;
    graph[start].forEach((cost, arrived)=>{
        if(cost !== Infinity){
            distance[arrived] = cost;
        }
    })
    for(let i =0;i<n;i++){
        let now = getSmallestNode();
        visited[now]=true;
        graph[now].forEach((busCost, arrived)=>{
            let cost = distance[now] + busCost;
            if (cost < distance[arrived]){
                distance[arrived] = cost;
            }
        })
    }
}

function solution(n, m, graph){

    dijkstra(start);

    console.log(distance[end]);
    
}


solution(n, m, graph);