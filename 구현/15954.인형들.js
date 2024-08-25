//[실버1] 15954.인형들 https://www.acmicpc.net/problem/15954

import { createRequire } from 'module';
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let [n, k] = input[0].split(' ').map((v) => +v);

let data = input[1].split(' ').map((v) => +v);

function getAvg(data, start, end) {

    let result = 0;
    for (let i = start; i < end; i++) {
        result += data[i];
    }
    return result / (end - start);
}

function standardDeviation(data, start, end) {
    let result = 0;
    let avg = getAvg(data, start, end);
    for (let i = start; i < end; i++) {
        result += Math.pow((data[i] - avg), 2);
    }
    return Math.sqrt(result / (end - start));
}

function solution(n, k, data) {

    let minSD = Infinity;

    for (let i = 0; i <= n - k; i++) {
        for (let j = k; j + i <= n; j++) {
            minSD = Math.min(minSD, standardDeviation(data, i, i + j));
        }
    }

    console.log(minSD);

}
solution(n, k, data);