//[실버4] 10816.숫자카드2 https://www.acmicpc.net/problem/10816

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input[0];
let array = input[1].split(' ').map((v) => +v).sort((a, b) => a - b);

let m = +input[2];
let data = input[3].split(' ').map((v) => +v);

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

function binarySearch_ASC_Upperbound(array, target) {
    let left = 0;
    let right = array.length;
    while (left < right) {
        let mid = Math.floor((left + right) / 2);
        if (target >= array[mid]) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return right;
}

function solution(n, array, m, data) {

    let answer = [];

    data.forEach((elem) => {
        answer.push(binarySearch_ASC_Upperbound(array, elem) - binarySearch_ASC_lowerbound(array,elem));
    })

    console.log(answer.join(' '))
}

solution(n, array, m, data);