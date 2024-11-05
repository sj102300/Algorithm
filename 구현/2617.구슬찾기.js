//[골드4] 2617.구슬찾기 https://www.acmicpc.net/problem/2617

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split("\n").map((v) => v.split(" ").map((e) => +e));

let [N, M] = input.shift();

function solution(N, M, data) {

    let heavier = Array.from({ length: N + 1 }, () => []);
    let lighter = Array.from({ length: N + 1 }, () => []);

    data.forEach(([a, b]) => {
        lighter[a] = [...new Set([...lighter[a], ...lighter[b], b])];
        heavier[b] = [...new Set([...heavier[b], ...heavier[a], a])];
        heavier[a].forEach((value)=>{
            lighter[value] = [...new Set([...lighter[a], ...lighter[value]])];
        });
        lighter[b].forEach((value)=>{
            heavier[value] = [...new Set([...heavier[b], ...heavier[value]])];
        })
    });

    let criteria = (N+1)/2;
    let answer = 0;

    for(let i=1;i<=N;i++){
        if(heavier[i].length >= criteria || lighter[i].length >= criteria)
            answer++;
    }

    return answer;

}

console.log(solution(N, M, input));