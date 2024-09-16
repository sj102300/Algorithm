//[브론즈1] 2309.일곱난쟁이 https://www.acmicpc.net/problem/2309

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n').map((v)=>+v);

function solution(input) {

    let notTarget;

    for (let i = 0; i < 9; i++) {
        for (let j = 1; j < 9; j++) {
            let sum = 0;
            for (let a = 0; a < 9; a++) {
                if (a !== i && a !== j) {
                    sum += input[a];
                }
            }
            if (sum === 100) {
                notTarget = [i, j];
                break;
            }
        }
    }

    return input.filter((v, i) => i !== notTarget[0] && i !== notTarget[1]).sort((a, b) => a - b).join('\n');

}

console.log(solution(input));