//[골드4] 20040.사이클게임 https://www.acmicpc.net/problem/20040

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split("\n").map((v) => v.split(" ").map((e) => +e));
let [n, m] = input.shift();

function union(a, b, parent) {
    let pa = find(a, parent);
    let pb = find(b, parent);

    if (pa < pb) {
        parent[pb] = pa;
    }
    else {
        parent[pa] = pb;
    }
}

function find(a, parent) {
    if (a === parent[a])
        return a;
    return parent[a] = find(parent[a], parent);
}

function solution(n, m, data) {

    let parent = Array.from({ length: n }, (_, i) => i);

    for(let i=0;i<m;i++){
        let [a, b] = data[i];
        if (find(a, parent) === find(b, parent)) { //이미 같은 집합에있으면
            return i + 1;
        }
        union(a, b, parent);
    }

    return 0;
}

console.log(solution(n, m, input))