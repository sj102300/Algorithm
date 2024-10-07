//[골드5] 2212.센서 https://www.acmicpc.net/problem/2212

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let N = +input[0];
let K = +input[1];
const sensors = input[2].split(' ').map((v) => +v);

sensors.sort((a, b) => a - b);

function solution(N, K, sensors) {

    let gap = [];

    for (let i = 1; i < N; i++) {
        gap.push(sensors[i] - sensors[i - 1]);
    }

    gap.sort((a, b) => b - a);

    let answer = 0;
    for (let i = K - 1; i < gap.length; i++) {
        answer += gap[i];

    }

    return answer;
}

console.log(solution(N, K, sensors));