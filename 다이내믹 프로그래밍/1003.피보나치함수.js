//[실버3] 1003.피보나치함수 https://acmicpc.net/problem/1003

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n').map((V) => +V);
let T = input.shift();

function solution(T, input) {

    let dpOne = Array.from({ length: 41 }, () => 0);
    let dpZero = Array.from({ length: 41 }, () => 0);

    dpOne[0] = 0;
    dpOne[1] = 1;
    dpOne[2] = 1;

    dpZero[0] = 1;
    dpZero[1] = 0;
    dpZero[2] = 1;

    for(let i= 3; i<41; i++){
        //fibo(i) = 2*fibo(i-2) + fibo(i-3);
        dpOne[i] = 2* dpOne[i-2] + dpOne[i-3];
        dpZero[i] = 2* dpZero[i-2] + dpZero[i-3];
    }

    let answer = [];
    input.forEach((v)=>{
        answer.push(`${dpZero[v]} ${dpOne[v]}`);
    })

    return answer.join('\n');
}

console.log(solution(T, input));