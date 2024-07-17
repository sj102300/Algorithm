//[브론즈2] 24267.알고리즘수업-알고리즘의수행시간6 https://www.acmicpc.net/problem/24267

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let n = +fs.readFileSync('dev/stdin', 'utf-8').trim();

function solution(n) {

    let dp = Array.from({ length: n + 1 }, (_, i) => BigInt(i));

    for(let i=1;i<=n;i++){
        dp[i] = dp[i-1] + dp[i];
    }

    switch (n) {
        case 1:
            return [0, 3];
        case 2:
            return [0, 3];
        default:
            let tmp = 0n;
            for (let i = 0; i <= n - 2; i++) {
                tmp += dp[i]
            }
            return [tmp, 3];
    }
}

function solution2(n){  //n개중에 3개를 뽑는 조합수 nC3
    return[ (BigInt(n) * BigInt(n-1) * BigInt(n-2) / BigInt(6)), 3];
}

console.log(solution2(n).join('\n'));