//[실버4] 1920.수찾기 https://www.acmicpc.net/problem/1920

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let N = +input[0];
let A = input[1].split(' ').map((v) => +v).sort((a, b) => a - b); //오름차순 정렬

let M = +input[2];
let data = input[3].split(' ').map((v) => +v);

function binarySearch(array, target) {
    let left = 0;
    let right = array.length - 1;
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (array[mid] === target) {
            return 1;
        }
        else if (target > array[mid]) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return 0
}

function solution(N, A, M, data) {

    data.forEach((elem) => {
        console.log(binarySearch(A, elem));
    });

}

solution(N, A, M, data)