//[실버2] 16953.A->B https://www.acmicpc.net/problem/16953

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let [A, B] = fs.readFileSync('dev/stdin', 'utf-8').trim().split(' ').map((v) => +v);

function solution(A, B) {

    let queue = [A];
    let front = 0;

    let answer = {};
    answer[A] = 1;

    while (front < queue.length) {
        let first = queue[front++];

        let value1 = 2 * first;
        let value2 = first * 10 + 1;

        if (value1 <= B && !answer[value1]) {
            answer[value1] = answer[first] + 1;
            queue.push(value1);
        }
        if (value2 <= B && !answer[value2]) {
            answer[value2] = answer[first] + 1;
            queue.push(value2);
        }
    }

    return answer[B] ? answer[B] : -1;
}

console.log(solution(A, B));
