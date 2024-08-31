//[실버2] 11722.가장긴감소하는부분수열 https://www.acmicpc.net/problem/11722

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input[0];
let seq = input[1].split(' ').map((v) => +v);

function binarySearch(target, array) {
    let left = 0;
    let right = array.length - 1;
    let result = 0;
    let mid;
    while (left <= right) {
        mid = Math.floor((left + right) / 2);
        if (target >= array[mid]) {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return result;
}

function solution(n, seq) {

    let tracking = [];

    let answer = [seq[0]];
    tracking.push([0, seq[0]]);

    for (let i = 1; i < n; i++) {
        if (seq[i] < answer.at(-1)) {
            answer.push(seq[i]);
            tracking.push([i, seq[i]]);
        }
        else {
            let targetIdx = binarySearch(seq[i], answer);
            answer[targetIdx] = seq[i];
            tracking.push([targetIdx, seq[i]]);
        }
    }

    let idx = answer.length - 1;
    for (let i = tracking.length - 1; i >= 0; i--) {
        if (tracking[i][0] === idx) {
            answer[idx] = tracking[i][1];
            idx--;
        }
        if (idx < 0) {
            break;
        }
    }

    // console.log(answer);
    console.log(answer.length);
}

solution(n, seq);