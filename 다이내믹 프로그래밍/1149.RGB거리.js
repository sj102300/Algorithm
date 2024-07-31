//[실버1] 1149.RGB거리 https://www.acmicpc.net/problem/1149


import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require("fs")
// let input = fs.readFileSync('input.txt').toString().split('\n');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
const N = +input[0];

for (let i = 1; i <= N; ++i){
    input[i] = input[i].split(' ').map((elem) => +elem)
}

input.splice(0,1);

function solution(n, data){

    let dp = [];
    dp.push(data[0]);
    for (let i = 1; i < n; i++){
        let r = Math.min(dp[i-1][1], dp[i-1][2]) + data[i][0];
        let g = Math.min(dp[i-1][0], dp[i-1][2]) + data[i][1];
        let b = Math.min(dp[i-1][0], dp[i-1][1]) + data[i][2];
        dp.push([r,g,b]);
    }

    console.log(Math.min(...dp.at(-1)));
}

solution(N, input);
