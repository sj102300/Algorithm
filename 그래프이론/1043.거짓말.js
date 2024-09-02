//[골드4] 1043.거짓말 https://www.acmicpc.net/problem/1043

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [n, m] = input.shift().split(' ').map((v) => +v);
let truth = input.shift().split(' ').map((v) => +v);
let truthNum = truth.shift();
let parties = input.map((v) => v.split(' ').map((e) => +e)).map((v) => {
    return v.slice(1)
})

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

function find(x, parent) {
    if (parent[x] === x)
        return x;
    return parent[x] = find(parent[x], parent);
}

function solution(n, m, truthNum, truth, parties) {

    let parent = Array.from({ length: n + 1 }, (_, i) => i);
    let answer = m;

    for (let i = 1; i < truthNum; i++) {
        union(truth[0], truth[i], parent);
    }

    parties.forEach((party) => {
        for (let i = 1; i < party.length; i++) {
            union(party[0], party[i], parent);
        }
    })

    let truthParent = find(truth[0], parent);

    parties.forEach((party)=>{
        if(find(party[0], parent) === truthParent){
            answer--;
        }
    })
    console.log(answer);
}

solution(n, m, truthNum, truth, parties);