//[골드4] 16562.친구비 https://www.acmicpc.net/problem/16562

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [n, m, k] = input[0].split(' ').map((v) => +v);
let friendFee = input[1].split(' ').map((v) => +v);
let relations = input.slice(2).map((v) => v.split(' ').map((e) => +e - 1));

function find(x, parent) {
    if (parent[x] === x)
        return x;
    return parent[x] = find(parent[x], parent);
}

function union(a, b, parent, friendFee) {
    let pa = find(a, parent);
    let pb = find(b, parent);
    if (parent[pa] < parent[pb]) {
        parent[pb] = pa;
    }
    else {
        parent[pa] = pb;
    }
}

function solution(n, m, k, friendFee, relations) {
    const parent = Array.from({ length: n }, (_, i) => i);

    relations.forEach((relation) => {
        union(relation[0], relation[1], parent, friendFee);
    })

    //대표노드 갱신하기
    for(let i=0;i<n;i++){
        find(i, parent);
    }

    let friendSet = [...new Set(parent)];

    let answer = 0;
    friendSet.forEach((e)=>{
        let lst = [];
        for (let i = 0; i < n; i++) {
            if (parent[i] === e) {
                lst.push(friendFee[i]);
            }
        }
        answer += Math.min(...lst);
    })

    return answer <= k ? answer : "Oh no"

}

console.log(solution(n, m, k, friendFee, relations));