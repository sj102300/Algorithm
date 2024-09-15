//[실버5] 2018.수들의합5 https://www.acmicpc.net/problem/2018

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = +fs.readFileSync('dev/stdin', 'utf-8').trim();

function solution(input) {

    let answer = 0;

    for (let i = 1; i < input; i++) {
        let sum = i;
        for (let j = i + 1; j < input; j++) {
            sum += j;
            if (sum === input) {
                answer++;
            }
            if (sum >= input) {
                break;
            }
        }
    }

    return answer + 1;
}

console.log(solution(input));