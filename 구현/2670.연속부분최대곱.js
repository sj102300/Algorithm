//[실버4] 2670.연속부분최대곱 https://www.acmicpc.net/problem/2670

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n').map((v) => +v);

let n = input.shift();

function solution(n, input) {
    let max = -1;
    for (let i = 0; i < input.length; i++) {
        let mul = input[i];
        if(max < input[i]){
            max = input[i]
        }
        for (let j = i + 1; j < input.length; j++) {
            mul *= input[j];
            if(max < mul){
                max = mul;
            }
        }
    }

    return max.toFixed(3);
}

console.log(solution(n, input));