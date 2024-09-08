//[브론즈1] 23881.알고리즘수업-선택정렬1 https://www.acmicpc.net/problem/23881

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [n, k] = input[0].split(' ').map((v) => +v);
let seq = input[1].split(' ').map((V) => +V);

function selectionSort(seq, n) {

    let max, idx;
    let tracking = [];
    for (let i = n - 1; i >= 0; i--) {
        max = seq[i];
        idx = i;
        for (let j = i - 1; j >= 0; j--) {
            if (max < seq[j]) {
                max = seq[j];
                idx = j;
            }
        }
        if(idx !== i){
            tracking.push([seq[i], seq[idx]]);
            let tmp = seq[idx];
            seq[idx] = seq[i];
            seq[i] = tmp;
        }
    }

    return tracking;

}

function solution(n, k, seq) {

    let tracking = selectionSort(seq, n);
    return tracking.length < k ? -1 : tracking[k - 1].join(' ');

}

console.log(solution(n, k, seq));