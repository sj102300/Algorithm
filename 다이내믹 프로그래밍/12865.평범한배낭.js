//[골드5] 12865.평범한배낭 https://www.acmicpc.net/problem/12865

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n').map((v) => v.split(" ").map((e) => +e));

let [N, K] = input.shift();

function solution(N, K, data) {

    let dp = Array.from({ length: K + 1 }, () => 0);

    for (let i = 0; i < N; i++) {
        let [W, V] = data[i];

        for (let j = K; j >= W; j--) {
            dp[j] = Math.max(dp[j], dp[j - W] + V)
        }
    }

    return dp[K];

}

console.log(solution(N, K, input));