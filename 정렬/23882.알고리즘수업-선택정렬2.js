//[브론즈1] 23882.알고리즘수업-선택정렬2 https://www.acmicpc.net/problem/23882

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [n, k] = input[0].split(' ').map((v) => +v);
let seq = input[1].split(' ').map((v) => +v);

function selectionSort(seq, n, k) {

    let max, idx;
    for (let i = n - 1; i >= 0; i--) {
        max = seq[i];
        idx = i;
        for (let j = i - 1; j >= 0; j--) {
            if (max < seq[j]) {
                max = seq[j];
                idx = j;
            }
        }
        if (i !== idx) {
            k--;
            let tmp = seq[i];
            seq[i] = seq[idx];
            seq[idx] = tmp;
        }
        if (k === 0) {
            return seq.join(' ');
        }
    }

    return -1;

}

function solution(n, k, seq) {

    return selectionSort(seq, n, k);

}

console.log(solution(n, k, seq));