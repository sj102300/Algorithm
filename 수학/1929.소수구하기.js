//[실버3] 1929.소수구하기 https://www.acmicpc.net/problem/1929

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let [m, n] = fs.readFileSync('dev/stdin', 'utf-8').trim().split(' ').map((v) => +v);

function solution(m, n) {
    //true -> 소수, false->소수x
    let array = Array.from({ length: n + 1 }, () => true);

    array[0] = false; // 0은 소수가 아님
    array[1] = false; // 1이 소수가 아니니?

    let p = 2;
    while (p <= Math.floor(Math.sqrt(n))) {
        for (let i = p + 1; i <= n; i++) {
            if (array[i] && (i % p === 0)) {
                array[i] = false;
            }
        }
        do {
            p++;
        } while (p <= Math.floor(Math.sqrt(n)) && array[p] === false);
    }

    let answer = [];
    for (let i = m; i <= n; i++) {
        if (array[i]) {
            answer.push(i);
        }
    }

    return answer.join('\n');
}

console.log(solution(m, n));