//[실버1] 1912.연속합 https://www.acmicpc.net/problem/1912

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input.shift();
let seq = input[0].split(' ').map((v) => +v);

// 1차원 dp 배열, nlogn

function solution(n, seq) {

    let dp = Array.from({ length: n }, () => -1001);

    dp[n-1] = seq[n-1];

    for(let i=n-2;i>=0;i--){
        dp[i] = Math.max(dp[i+1] + seq[i], seq[i]);
    }

    return Math.max(...dp);

}

console.log(solution(n, seq));