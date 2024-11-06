//[골드3] 2629.양팔저울 https://www.acmicpc.net/problem/2629

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split("\n").map((v) => v.split(" ").map((e) => +e));

let N = input.shift()[0]
let weights = input.shift();
let M = input.shift()[0];
let marbles = input.shift();

function solution(N, weights, M, marbles) {

    let weightSum = weights.reduce((acc, cur) => acc + cur, 0);

    let dp = Array.from({ length: N + 1 }, () => Array(weightSum + 1).fill(false));

    for (let i = 1; i <= N; i++) {
        let weight = weights[i - 1];

        dp[i][weight] = true;

        for (let j = 1; j <= weightSum; j++) {

            if (dp[i - 1][j]) {
                dp[i][j] = true;
                if (weight - j <= weightSum && weight - j > 0) {
                    dp[i][weight - j] = true;
                }
                if (j - weight <= weightSum && j - weight > 0) {
                    dp[i][j - weight] = true;
                }
                if (weight + j <= weightSum) {
                    dp[i][weight + j] = true;
                }
            }
        }
    }

    let result = dp.pop();

    marbles.forEach((marble, i) => {
        if (result[marble]) {
            marbles[i] = "Y";
        }
        else {
            marbles[i] = "N";
        }
    })

    return marbles.join(" ");

}

console.log(solution(N, weights, M, marbles));
