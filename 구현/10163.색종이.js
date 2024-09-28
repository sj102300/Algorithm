//[브론즈1] 10163.색종이 https://www.acmicpc.net/problem/10163

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input.shift();
let data = input.map((v) => v.split(' ').map((e) => +e));

function solution(n, data) {
    let map = Array.from({ length: 1002 }, () => Array.from({ length: 1002 }, () => 0));

    data.forEach(([a, b, x, y], idx) => {
        for (let i = 0; i < x; i++) {
            for (let j = 0; j < y; j++) {
                map[a + i][b + j] = idx + 1;
            }
        }
    })

    let answer = [];
    for (let idx = 1; idx <= n; idx++) {
        let tmp = 0;
        for (let i = 0; i < 1002; i++) {
            for (let j = 0; j < 1002; j++) {
                if (map[i][j] === idx)
                    tmp++;
            }
        }
        answer.push(tmp);
    }
    return answer.join('\n');
}

console.log(solution(n, data));