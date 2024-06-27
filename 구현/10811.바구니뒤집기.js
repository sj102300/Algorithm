//[브론즈2] 10811.바구니뒤집기 https://www.acmicpc.net/problem/10811

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n').map((v) => v.split(' ').map((e) => +e));

let [n, m] = input.shift();

function solution(n, m, input) {
    let answer = Array.from({ length: n }, (_, i) => i + 1);

    input.forEach(([i, j]) => {
        i--;
        j--;
        let left = answer.slice(0, i);
        let right = answer.slice(j + 1);
        let part = answer.slice(i, j + 1).reverse();
        answer = [...left, ...part, ...right]
    })

    return answer.join(' ');
}

console.log(solution(n, m, input));
