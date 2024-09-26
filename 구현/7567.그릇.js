//[브론즈2] 7567.그릇 https://www.acmicpc.net/problem/7567

import { createRequire } from "module";
const require = createRequire(import.meta.url)

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim();

function solution(input){

    let answer= 10;

    for(let i=1;i<input.length;i++){
        if(input[i] !== input[i-1])
            answer+= 10;
        else
            answer+=5;
    }

    return answer;

}

console.log(solution(input));