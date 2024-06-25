//[실버4] 2960.에라토스테네스의체 https://www.acmicpc.net/problem/2960

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let [n, k] = fs.readFileSync('dev/stdin', 'utf-8').trim().split(' ').map((v) => +v);

function solution(n, k) {

    //true->소수, false->소수x
    let array = Array.from({ length: n + 1 }, () => true);
    let answer = [];

    let p = 2;
    while (p <= n) {
        answer.push(p);
        for (let i = p + 1; i <= n; i++) {
            if (array[i] === true && i % p === 0) {
                array[i] = false;
                answer.push(i);
            }
        }
        do {
            p++;
        } while (array[p] === false);
    }
    return answer[k - 1];
}

console.log(solution(n, k));