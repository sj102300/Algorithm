//[골드3] 7579.앱 https://www.acmicpc.net/problem/7579

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [N, M] = input[0].split(' ').map((V) => +V);
let A = input[1].split(' ').map((v) => +v);
let C = input[2].split(' ').map((v) => +v);

function solution(N, M, A, C) {
    let data = [];
    let sumC = 0;

    for (let i = 0; i < N; i++) {
        data.push([A[i], C[i]]);
        sumC += C[i];
    }

    let dp = Array.from({ length: sumC + 1 }, () => 0);

    for (let i = 0; i < N; i++) {
        let [a, c] = data[i];

        for (let j = sumC; j >= c; j--) {
            dp[j] = Math.max(dp[j], dp[j - c] + a);
        }
    }

    for(let i=0;i<sumC+1;i++){
        if(dp[i] >= M){
            return i;
        }
    }

}

console.log(solution(N, M, A, C));