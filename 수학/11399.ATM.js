//[실버4] 11399.ATM https://www.acmicpc.net/problem/11399

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input.shift();
let seq = input[0].split(' ').map((v) => +v).sort((a, b) => a - b);

function solution(n, seq) {

    let answer = 0;
    for (let i = 0; i < n; i++) {
        answer += seq[i] * (n - i);
    }
    return answer;

}

console.log(solution(n, seq));