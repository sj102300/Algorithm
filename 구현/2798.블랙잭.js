//[브론즈2] 2798.블랙잭 https://www.acmicpc.net/problem/2798

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [N, M] = input[0].split(' ').map((v) => +v);
let array = input[1].split(' ').map((v) => +v);

function solution(N, M, array) {

    let answer = 0;

    for (let i = 0; i < N; i++) {
        for (let j = i + 1; j < N; j++) {
            for (let k = j + 1; k < N; k++) {
                let sum = array[i] + array[j] + array[k];
                if (sum <= M && sum > answer)
                    answer = sum
                if (answer === M)
                    break;
            }
        }
    }

    return answer;

}

console.log(solution(N, M, array));