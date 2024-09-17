//[골드5] 13549.숨바꼭질3 https://www.acmicpc.net/problem/13549

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let [n, k] = fs.readFileSync('dev/stdin', 'utf-8').trim().split(' ').map((v) => +v);

function solution(n, k) {

    let dp = Array.from({ length: 1000000 }, () => -1);

    dp[n] = 0;

    let deque = [];

    deque.push(n);

    while (deque.length > 0) {
        let x = deque.shift();
        if (x === k) {
            return dp[x];
        }
        if (dp[2 * x] === -1 || dp[2 * x] > dp[x]) {
            dp[2 * x] = dp[x];
            deque.push(2 * x);
        }
        if (dp[x + 1] === -1 || dp[x + 1] > dp[x] + 1) {
            dp[x + 1] = dp[x] + 1;
            deque.push(x + 1);
        }
        if (dp[x - 1] === -1 || dp[x - 1] > dp[x] + 1) {
            dp[x - 1] = dp[x] + 1;
            deque.push(x - 1);
        }
    }

    return dp[k];

}

console.log(solution(n, k));