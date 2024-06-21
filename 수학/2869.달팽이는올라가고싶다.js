//[브론즈1] 2869.달팽이는올라가고싶다 https://www.acmicpc.net/problem/2869

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [a, b, v] = input[0].split(' ').map((v)=>+v);

function solution(a,b,v){
    return Math.ceil((v-b)/(a-b));
}

console.log(solution(a,b,v));