//[브론즈2] 2750.수정렬하기 https://www.acmicpc.net/problem/2750

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n').map((v) => +v);

input.shift();

function solution(input) {

    for (let i = 0; i < input.length; i++) {
        for (let j = i + 1; j < input.length; j++) {
            if (input[i] > input[j]) {
                [input[i], input[j]] = [input[j], input[i]]
            }
        }
    }

    return input.join('\n');

}

console.log(solution(input));