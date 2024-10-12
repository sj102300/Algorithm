//[골드4] 1253.좋다 https://www.acmicpc.net/problem/1253

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let N = +input[0];
let A = input[1].split(' ').map((V) => +V).sort((a, b) => a - b);

function solution(N, A) {

    let answer = 0;

    A.forEach((value, i) => {
        let a = 0;
        let b = A.length - 1;
        while (a < b) {
            if (a === i){
                a++;
                continue;
            }
            if (b === i){
                b--;
                continue;
            }

            if(A[a] + A[b] === value){
                answer++;
                break;
            }
            else if(A[a] + A[b] > value){
                b--;
            }
            else{
                a++;
            }
        }
    })

    return answer;
}

console.log(solution(N, A));