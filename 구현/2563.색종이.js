//[실버5] 2563.색종이 https://www.acmicpc.net/problem/2563

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

input.shift();
input = input.map(v => v.split(' ').map((e) => +e));

function solution(input) {

    let map = Array.from({ length: 101 }, () => Array.from({ length: 101 }, () => 0));

    input.forEach(([x, y]) => {
        for (let i = 0; i < 10; i++) {
            for (let j = 0; j < 10; j++) {
                map[i + x][j + y] = 1;
            }
        }
    })

    let answer = 0;

    for (let i = 0; i < 101; i++) {
        for (let j = 0; j < 101; j++) {
            if (map[i][j] === 1) {
                answer++;
            }
        }
    }
    return answer;

}

console.log(solution(input));