//[골드5] 2294.동전2 https://www.acmicpc.net/problem/2294

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [n, k] = input[0].split(' ');
const coins = [...new Set(input.slice(1).map((e) => +e).filter((v)=>v<=k))]; //동전가치가 k보다 작은애들만 남기고, set으로 중복제거

function solution(k, coins) {

    const dp = Array(10001).fill(Number.MAX_SAFE_INTEGER);
    dp[0] = 0;
    coins.forEach((v)=>{
        for (let i=v; i<=k ;i++){
            dp[i] = Math.min(dp[i], dp[i-v] + 1);
        }
    })

    console.log(dp[k] === Number.MAX_SAFE_INTEGER ? -1 : dp[k]);
}

solution(k, coins);