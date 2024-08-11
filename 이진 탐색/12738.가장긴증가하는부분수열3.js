//[골드2] 12738.가장긴증가하는부분수열3 https://www.acmicpc.net/problem/12738

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input[0]
let A = input[1].split(' ').map((v) => +v);

function binarySearch(subseq, n) {

    let left = 0;
    let right = subseq.length - 1;

    let mid;
    while (left <= right) {
        mid = Math.floor((left + right) / 2);
        if(subseq[mid] === n){
            return mid;
        }
        else if (subseq[mid] < n) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return left;

}

function solution(n, A) {

    let subseq = [A[0]];

    let idx = 0;
    for (let i = 1; i < n; i++) {
        if (subseq[idx] < A[i]) {
            subseq.push(A[i]);
            idx++;
        }
        else {
            let targetIdx = binarySearch(subseq, A[i]);
            subseq[targetIdx] = A[i];
        }
    }

    console.log(subseq.length);

}

solution(n, A);