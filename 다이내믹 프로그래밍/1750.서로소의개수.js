//[골드3] 1750.서로소의개수 https://www.acmicpc.net/problem/1750

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input[0]
let seq = input.slice(1).map((v) => +v);

function gcd(a, b) {
    let [max, min] = a > b ? [a, b] : [b, a];
    if (max % min === 0) {
        return min;
    }
    return gcd(b, a % b);
}

function solution(n, seq) {
    //dp[i] = i를 최대공약수로 가지는 경우의 수
    let dp = Array(Math.max(...seq) + 1).fill(0);

    for(let i=0;i<n;i++){
        for(let j =1;j<dp.length;j++){
            if(dp[j]){
                dp[gcd(j, seq[i])] += dp[j];
            }
        }
        dp[seq[i]] += 1;
    }

    console.log(dp[1] % 10000003);
}

solution(n, seq);