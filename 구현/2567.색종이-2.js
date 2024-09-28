//[실버4] 2567.색종이-2.js https://www.acmicpc.net/problem/2567

import { createRequire } from "module";
const require = createRequire(import.meta.url);

const fs = require('fs');
let input = fs.readFileSync('dev/stdin', 'utf-8').trim().split('\n');

let n = +input.shift();
let data = input.map((e) => e.split(' ').map((v) => +v));

function solution(n, data) {

    //100까지 색종이가 붙으면 둘레를 계산하기 위해서는 0이 있는 패딩을 만들어줘야함.
    let map = Array.from({ length: 102 }, () => Array.from({ length: 102 }, () => 0));

    const dx = [0, 1, 0, -1];
    const dy = [1, 0, -1, 0];

    data.forEach(([x, y]) => {
        for (let i = x; i < x + 10; i++) {
            for (let j = y; j < y + 10; j++) {
                map[i][j] = 1;
            }
        }
    })

    let answer = 0;
    for (let i = 1; i < 101; i++) {
        for (let j = 1; j < 101; j++) {
            if (map[i][j] === 1) {
                for (let dir = 0; dir < 4; dir++) {
                    let newX = dx[dir] + i;
                    let newY = dy[dir] + j;
                    if (map[newX][newY] === 0) {
                        answer++;
                    }
                }
            }
        }
    }

    return answer;

}

console.log(solution(n, data));