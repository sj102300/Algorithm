//[골드4] 1915.가장큰정사각형 https://www.acmicpc.net/problem/1915

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [n, m] = input[0].split(' ').map((v) => +v);
let data = input.slice(1);

let answer = 0;

function solution(n, m, data) {

    //dp[i][j] = data[i][j]를 포함해서 만들수 있는 가장 큰 정사각형의 크기
    //dp[i][j] = min(dp[i+1][j+1], dp[i+1][j], dp[i][j+1]) + 1;
    let dp = Array.from({ length: n }, () => Array(m).fill(0));

    for (let i = 0; i < m; i++) {
        dp[n - 1][i] = data[n - 1][i] === '0' ? 0 : 1;
        if (dp[n - 1][i] === 1)
            answer = 1;
    }

    for (let i = 0; i < n; i++) {
        dp[i][m - 1] = data[i][m - 1] === '0' ? 0 : 1;
        if (dp[i][m - 1] === 1)
            answer = 1;
    }

    for (let i = n - 2; i >= 0; i--) {
        for (let j = m - 2; j >= 0; j--) {
            if (data[i][j] === '0') {
                dp[i][j] = 0;
                continue;
            }
            if (dp[i + 1][j + 1] === 0) {
                dp[i][j] = 1;
                answer = answer > dp[i][j] ? answer : dp[i][j];
                continue;
            }
            let length = 1;
            for (let k = i + 1, l = j + 1; k < n && l < m && length <= dp[i+1][j+1]; k++, l++) {
                if (data[k][j] === '1' && data[i][l] === '1') {
                    length++;
                }
                else {
                    break;
                }
            }
            dp[i][j] = length;
            answer = answer > dp[i][j] ? answer : dp[i][j];
        }
    }
}

solution(n, m, data);

console.log(answer ** 2);