//[브론즈1] 1546.평균 https://www.acmicpc.net/problem/1546

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input[0];
let score = input[1].split(' ').map((v) => +v);

function solution(n, score) {
    let max = Math.max(...score);
    let newScore = score.map((s)=> s/max * 100);
    return newScore.reduce((acc,cur)=>acc+cur, 0)/n
}

console.log(solution(n, score));