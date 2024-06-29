//[실버4] 1822.차집합 https://www.acmicpc.net/problem/1822

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [na, nb] = input[0].split(' ').map(Number);
let A = input[1].split(' ').map(Number).sort((a, b) => a - b);
let B = input[2].split(' ').map(Number).sort((a, b) => a - b);

function solution(na, nb, A, B) {

    let answer = [];
    let aIdx = 0;
    let bIdx = 0;
    while(aIdx < na){
        if(bIdx >= nb || A[aIdx] < B[bIdx]){
            answer.push(A[aIdx]);
            aIdx++;
        }
        else if(A[aIdx] > B[bIdx]){
            bIdx++;
        }
        else{
            aIdx++;
            bIdx++;
        }
    }

    console.log(answer.length);
    answer.length > 0 ? console.log(answer.join(' ')) : null;

}

solution(na, nb, A, B);