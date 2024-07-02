//[브론즈1] 1032.명령프롬프트 https://www.acmicpc.net/problem/1032

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input.shift();

function solution(n, input) {

    let str = []
    for (let j = 0; j < input[0].length; j++) {
        let target = input[0][j];
        str.push(target);
        for (let i = 1; i < n; i++) {
            if(input[i][j] !== target){
                str[str.length-1] = '?'
                break;
            }
        }
    }
    return str.join('');
}

console.log(solution(n, input));