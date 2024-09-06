//[골드3] 2342.DanceDanceRevolution https://www.acmicpc.net/problem/2342

import { createRequire } from 'module';
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = [0, ...fs.readFileSync('dev/stdin', 'utf-8').trim().split(' ').map((v) => +v)];

function solution(input) {

    //graph[0][1] = 0에서 1로가는데 드는 힘
    let graph = [
        [0, 2, 2, 2, 2],
        [2, 1, 3, 4, 3],
        [2, 3, 1, 3, 4],
        [2, 4, 3, 1, 3],
        [2, 3, 4, 3, 1]
    ]

    //dp[i][j][k] => i에 왼발 j에 오른발을 두고 k를 밟는 경우의 최솟값
    let dp = Array.from({ length: 5 }, () => Array.from({ length: 5 }, () => Array.from({ length: input.length }, () => Infinity)));

    dp[0][0][0] = 0;

    for (let step = 1; step < input.length; step++) {
        let target = input[step];
        for (let i = 0; i < 5; i++) {
            for (let j = 0; j < 5; j++) {
                dp[i][target][step] = Math.min(dp[i][target][step], dp[i][j][step - 1] + graph[j][target]);
                dp[target][j][step] = Math.min(dp[target][j][step], dp[i][j][step - 1] + graph[i][target]);
            }
        }
    }

    let min = Infinity;
    let last = input.at(-2);
    for (let i = 0; i < 5; i++) {
        min = Math.min(min, dp[i][last][input.length - 2], dp[last][i][input.length - 2])
    }
    return min;
}

console.log(solution(input));