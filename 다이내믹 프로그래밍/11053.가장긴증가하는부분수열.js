//[실버2] 11053.가장긴증가하는부분수열 https://www.acmicpc.net/problem/11053

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input[0]
let A = input[1].split(' ').map((v)=>+v);

function solution(n, A){

    let dp = Array(n).fill(1);

    for(let i=1; i<n;i++){
        for(let j=i;j>=0;j--){
            if(A[i] > A[j]){
                dp[i] = Math.max(dp[i], dp[j]+1);
            }
        }
    }

    console.log(Math.max(...dp));

}

solution(n, A);