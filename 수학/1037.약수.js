//[브론즈1] 1037.약수 https://www.acmicpc.net/problem/1037

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input[0]
let array = input[1].split(' ').map((v)=>+v).sort((a,b)=>b-a);

function solution(n, array){

    return array[0] * array.at(-1);
    
}

console.log(solution(n, array));