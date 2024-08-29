//[골드4] 1197.최소스패닝트리 https://www.acmicpc.net/problem/1197

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
const input = fs.readFileSync('dev/stdin', 'utf-8').trim().split("\n");

// 만들어졌던 연결이나 cycle을 만들면안됨
// 가장 짧은 간선순으로 정렬

const [V, E] = input[0].split(" ").map((v) => +v)
const data = input.slice(1).map((line)=>line.split(' ').map((v)=>+v))

function find(parent, x) {
    if (parent[x] === x) {
        return x
    }
    //경로 압축
    return parent[x] = find(parent, parent[x])
}

function union(parent, a, b) {
    const pa = find(parent, a)
    const pb = find(parent, b)
    if (pa < pb) {
        parent[pb] = pa
    } else {
        parent[pa] = pb
    }
}

function solution(V, E, data) {

    data.sort((a, b) => a[2] - b[2]);
    const parent = Array.from({ length: V + 1 }, (_, i) => i);

    let answer= 0;
    data.forEach(([start, arrived, cost])=>{
        if(find(parent, start) !== find(parent, arrived)){
            union(parent, start, arrived);
            answer+=cost;
        }
    })

    console.log(answer)

}

solution(V, E, data)

