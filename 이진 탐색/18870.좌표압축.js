//[실버2] 18870.좌표압축 https://www.acmicpc.net/problem/18870

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input[0];
let seq = input[1].split(' ').map((v) => +v);

function binarySearch_ASC_lowerbound(array, target) {

    let left = 0;
    let right = array.length;
    while (left < right) {
        let mid = Math.floor((left + right) / 2);
        if (target > array[mid]) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return right;
}

function solution(n, seq) {

    let sorted = [...new Set(seq)].sort((a, b) => a - b)

    seq = seq.map((elem) => {
        return binarySearch_ASC_lowerbound(sorted, elem);
    })
    return seq.join(' ');
}

console.log(solution(n, seq));