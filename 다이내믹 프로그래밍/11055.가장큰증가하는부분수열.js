//[실버2] 11055.가장큰증가하는부분수열 https://www.acmicpc.net/problem/11055

import { createRequire } from "module";
const require = createRequire(import.meta.url);
const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input[0];
let seq = input[1].split(' ').map((v)=>+v);

function solution(n, seq){

    let dp = [...seq];

    for(let i=0;i<n;i++){
        
        for(let j = 0; j<i;j++){
            if(seq[i] > seq[j]){
                dp[i] = Math.max(dp[i], dp[j]+seq[i]);
            }
        }
    }

    console.log(Math.max(...dp));
}

solution(n, seq);